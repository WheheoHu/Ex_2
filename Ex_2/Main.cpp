#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "glut.h"
#include "CoordinateXY.h"

using namespace std;


#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480
#define WHITE 0
#define RED 1
#define GREEN 2
#define	BLUE 3

bool creak = false;
bool saved = false;
static int inc = 0;
static int iColor = WHITE;
static CoordinateXY   coorxy;
vector< CoordinateXY> datapoint;
fstream datafile;

void savedata(vector<CoordinateXY> datapoint);
void loaddata(fstream &datafile);

void setXY(int x, int y) {
	coorxy.setX(x);
	coorxy.setY(y);
	coorxy.setColor(iColor);
	coorxy.plusnum();
	datapoint.push_back(CoordinateXY(x, y,iColor));
	//datafile << x << " " << y << " " << iColor << endl;
}

//右键菜单更改颜色
void processmenu(int MenuID) {

	switch (MenuID)
	{
	case 0: {
		iColor = WHITE;
		glColor3f(1, 1, 1);
		break;
	}
	case 1: {
		iColor = RED;
		glColor3f(1, 0, 0);
		break;
	}
	case 2: {
		iColor = GREEN;
		glColor3f(0, 1, 0);
		break;
	}
	case 3: {
		iColor = BLUE;
		glColor3f(0, 0, 1);
		break;
	}
	case 4: {
		savedata(datapoint);
		break;
	}
	case 5: {

		break;
	}

	case 6: {
		exit(0);
		break; }
	}
}

//初始化菜单
void InitMenu() {
	int m_menuID = glutCreateMenu(processmenu);
	glutSetMenu(m_menuID);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutAddMenuEntry("White", 0);
	glutAddMenuEntry("Red", 1);
	glutAddMenuEntry("Green", 2);
	glutAddMenuEntry("Blue", 3);
	glutAddMenuEntry("SAVE", 4);
	glutAddMenuEntry("LOAD", 5);
	glutAddMenuEntry("EXIT", 6);
}

//初始化窗口
void InitWindow() {
	datafile.open("Data.txt", ios::out);
	datafile.close();
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutCreateWindow("simple");
	InitMenu();
	glMatrixMode(GL_PROJECTION);// sets the current matrix to projection
	glLoadIdentity();//multiply the current matrix by identity matrix
	gluOrtho2D(0.0, WINDOW_WIDTH, 0, WINDOW_HEIGHT);//sets the parallel(orthographic) projection of the full frame buffer 

}

//渲染
void RenderScene() {


	//glColor3f(1, 1, 0);
	glPointSize(5);
	if (creak)
	{


		glBegin(GL_POINTS);
		glVertex2i(coorxy.getCoorX(), coorxy.getCoorY());
		glEnd();
	}
	cout << coorxy.getpointnum() << " [" << coorxy.getCoorX() << "," << coorxy.getCoorY() << "]" << endl;
	glFlush();
}

//鼠标操作，将坐标传递给cooxy
void mouseProcess(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		creak = true;


		setXY(x, WINDOW_HEIGHT - y);
	}

	glutPostRedisplay();
}

int main() {
	//创建窗口
	InitWindow();

	glutDisplayFunc(RenderScene);

	glutMouseFunc(mouseProcess);

	glutMainLoop();

	/*datafile.open("Data.txt", ios::out);
	datafile << "adsasdasd" << endl;
	datafile << "ads" << endl;
	datafile.close();

	datafile.open("Data.txt", ios::in);
	string line_s;
	while (!datafile.eof())
	{
		cout <<  line_s<< endl;
	}
	datafile.close();
	system("pause");*/
	return 0;
}

void savedata(vector<CoordinateXY> datapoint)
{
	datafile.open("Data.txt", ios::out | ios::app);
	for (vector<CoordinateXY>::iterator iter = datapoint.begin(); iter != datapoint.end(); iter++)
	{
		datafile << iter->getCoorX() << " " << iter->getCoorY() << " " << iter->getColor() << endl;
	}
	datafile.close();
}

void loaddata(fstream & datafile)
{
	datafile.open("Data.txt",ios::in);

	datafile.close();
}
