#pragma once

class Point
{
private:
	double _x;
	double _y;

public:
	void SetX(double x);
	void SetY(double y);
	double GetX();
	double GetY();

	Point(double x, double y);
	Point();
};
