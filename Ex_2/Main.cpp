#include <stdlib.h>
#include <iostream>
#include "glut.h"
#include "CoordinateXY.h"

using namespace std;
//#pragma comment(lib,"opengl32.lib")
//#pragma comment(lib,"glu32.lib")
#pragma comment(lib,"glut32.lib")

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

bool creak = false;
static CoordinateXY   coorxy;

//test code
void setXY(int x, int y) {
	coorxy.setX(x);
	coorxy.setY(y);
	coorxy.plusnum();
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
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutCreateWindow("simple");
	InitMenu();
	glMatrixMode(GL_PROJECTION);// sets the current matrix to projection
	glLoadIdentity();//multiply the current matrix by identity matrix
	gluOrtho2D(0.0, WINDOW_WIDTH, WINDOW_HEIGHT, 0);//sets the parallel(orthographic) projection of the full frame buffer 

}

//渲染
void RenderScene() {


	//glColor3f(1, 1, 0);
	glPointSize(10);
	if (creak)
	{


		glBegin(GL_POINTS);
		glVertex2i(coorxy.getCoorX(), coorxy.getCoorY());
		glEnd();
	}
	cout << coorxy.getpointnum() << endl;
	glFlush();
}

//鼠标操作，将坐标传递给cooxy
void mouseProcess(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		creak = true;


		setXY(x, y);
	}

	glutPostRedisplay();
}

int main() {
	//创建窗口
	InitWindow();


	//setXY(100, 200);
	glutDisplayFunc(RenderScene);

	glutMouseFunc(mouseProcess);

	glutMainLoop();
	return 0;
}