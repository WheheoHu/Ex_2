#pragma once

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "glut.h"
#include "CoordinateXY.h"
#include  "MenuFunc.h"

using namespace std;

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480
#define WHITE 0
#define RED 1
#define GREEN 2
#define	BLUE 3

bool creak = false;

static int inc = 0;
static int iColor = WHITE;
static CoordinateXY   coorxy;
vector< CoordinateXY> datapoint;
fstream datafile;

//保存xy数据
void setXY(int x, int y);


//初始化窗口
void InitWindow();
//渲染
void RenderScene();
//鼠标操作，将坐标传递给cooxy
void mouseProcess(int button, int state, int x, int y);





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
}

