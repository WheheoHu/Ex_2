#pragma once
class CoordinateXY
{
public:
	CoordinateXY(int coorX,int coorY);
	CoordinateXY(int coorX, int coorY,int Color);
	CoordinateXY();
	~CoordinateXY();
	void setX(int x);
	void setY(int y);
	void plusnum();
	void setColor(int iColor); 

	//���x����
	int getCoorX() {
		
		return CoordinateX;
	}

	//���Y����
	int getCoorY() {
		return CoordinateY;
	}

	int getpointnum() {
		return point_num;
	}

	int getColor();
	

private:
	int CoordinateX;
	int CoordinateY;
	int point_num;
	int point_color;
};

