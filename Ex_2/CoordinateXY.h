#pragma once
class CoordinateXY
{
public:
	CoordinateXY(int coorX,int coorY);
	CoordinateXY();
	~CoordinateXY();
	void setX(int x);
	void setY(int y);
	void plusnum();

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
private:
	int CoordinateX;
	int CoordinateY;
	int point_num;
};

