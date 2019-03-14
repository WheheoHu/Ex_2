#include "CoordinateXY.h"






CoordinateXY::CoordinateXY(int coorX, int coorY)
{
	CoordinateX = coorX;
	CoordinateY = coorY;
	point_num = 0;
}

CoordinateXY::CoordinateXY()
{
}

CoordinateXY::~CoordinateXY()
{
}

void CoordinateXY::setX(int x)
{
	CoordinateX = x;
}

void CoordinateXY::setY(int y)
{
	CoordinateY = y;
}

void CoordinateXY::plusnum()
{
	point_num++;
}
