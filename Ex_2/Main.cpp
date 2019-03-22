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

//保存xy数据
void setXY(int x, int y);
void processmenu(int MenuID);
//保存数据
void savedata(vector<CoordinateXY> datapoint);
//读取Data.txt数据
void loaddata(fstream &datafile);
//清屏&重置数据
void removeall(fstream &datafile);
//初始化菜单
void InitMenu();
//初始化窗口
void InitWindow();
//渲染
void RenderScene();
//鼠标操作，将坐标传递给cooxy
void mouseProcess(int button, int state, int x, int y);

int main() {
	//创建窗口
	InitWindow();

	glutMouseFunc(mouseProcess);
	glutDisplayFunc(RenderScene);


	glutMainLoop();

	
	return 0;
}

void savedata(vector<CoordinateXY> datapoint)
{
	//remove("Data.txt");
	datafile.open("Data.txt", ios::out |ios::app);
	for (vector<CoordinateXY>::iterator iter = datapoint.begin(); iter != datapoint.end(); iter++)
	{
		datafile << iter->getCoorX() << " " << iter->getCoorY() << " " << iter->getColor() << endl;
	}
	datafile.close();
}

void loaddata(fstream & datafile)
{
	datafile.open("Data.txt",ios::in);
	int coorx;
	int coory;
	int pointcolor;
	
	while (!datafile.eof())
	{
		datafile >> coorx;
		datafile >> coory;
		datafile >> pointcolor;
		iColor = pointcolor;
		switch (iColor)
		{
		case RED: {
			glColor3f(1, 0, 0);
			break;
		}
		case GREEN: {
			glColor3f(0, 1, 0);
			break;
		}
		case BLUE: {
			glColor3f(0, 0, 1);
			break;
		}
		case WHITE: {
			glColor3f(1, 1, 1);
			break;
		}
		}
		glBegin(GL_POINTS);
		glVertex2i(coorx, coory);
		glEnd();
		glutPostRedisplay();
	}
	datafile.close();
}

void removeall(fstream & datafile)
{
	datafile.open("Data.txt", ios::out);
	datafile.close();
	loaddata(datafile);
	glClear(GL_COLOR_BUFFER_BIT);
}

void InitMenu()
{
	int m_menuID = glutCreateMenu(processmenu);
	glutSetMenu(m_menuID);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutAddMenuEntry("White", 0);
	glutAddMenuEntry("Red", 1);
	glutAddMenuEntry("Green", 2);
	glutAddMenuEntry("Blue", 3);
	glutAddMenuEntry("SAVE", 4);
	glutAddMenuEntry("LOAD", 5);
	glutAddMenuEntry("CLEAN ALL!", 6);
	glutAddMenuEntry("EXIT", 7);
}

void InitWindow()
{
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutCreateWindow("simple");
	InitMenu();
	glMatrixMode(GL_PROJECTION);// sets the current matrix to projection
	glLoadIdentity();//multiply the current matrix by identity matrix
	gluOrtho2D(0.0, WINDOW_WIDTH, 0, WINDOW_HEIGHT);//sets the parallel(orthographic) projection of the full frame buffer 

}

void RenderScene()
{
	
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

void mouseProcess(int button, int state, int x, int y)
{
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			creak = true;
			setXY(x, WINDOW_HEIGHT - y);
		}
		glutPostRedisplay();
	
}

void setXY(int x, int y) {
	coorxy.setX(x);
	coorxy.setY(y);
	coorxy.setColor(iColor);
	coorxy.plusnum();
	datapoint.push_back(CoordinateXY(x, y, iColor));
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
		loaddata(datafile);
		break;
	}
	case 6: {

		removeall(datafile);
		break;
	}
	case 7: {
		exit(0);
		break; }
	}
}

