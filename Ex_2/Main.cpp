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

bool creak = false;
bool saved = false;
static CoordinateXY   coorxy;
vector<vector<int>> datapoint;
fstream datafile;

void savedata(vector<vector<int>> datapoint);


void setXY(int x, int y) {
	coorxy.setX(x);
	coorxy.setY(y);
	coorxy.plusnum();
	datafile.open("Data.txt", ios::out|ios::app);
	datafile << x << " "<<y << endl;
	datafile.close();
}

//右键菜单更改颜色
void processmenu(int MenuID) {

	switch (MenuID)
	{
	case 0: {
		glColor3f(1, 1, 1);
		break;
	}
	case 1: {
		glColor3f(1, 0, 0);
		break;
	}
	case 2: {
		glColor3f(0, 1, 0);
		break;
	}
	case 3: {
		glColor3f(0, 0, 1);
		break;
	}
	case 4: {
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
	glutAddMenuEntry("EXIT", 4);
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
	cout << coorxy.getpointnum() <<" ["<<coorxy.getCoorX()<<","<<coorxy.getCoorY()<<"]" <<endl;
	glFlush();
}

//鼠标操作，将坐标传递给cooxy
void mouseProcess(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		creak = true;


		setXY(x,WINDOW_HEIGHT- y);
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

void savedata(vector<vector<int>> datapoint)
{
	datafile.open("Data.txt",ios::out);
	for (int i = 0; i < datapoint.size(); i++)
	{
		for (int j = 0; j < datapoint[0].size(); j++)
		{
			datafile << datapoint[i][j] << endl;
		}
	}
	datafile.close();
}
