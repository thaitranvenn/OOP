#pragma once
#include "Point.h"
#include <exception>
#include <iostream>
using namespace std;

class Rectangle
{
private:
	double _length;
	double _width;
	Point _center;

public:
	void SetLength(double length);
	void SetWidth(double width);
	void SetCenter(Point point);

	double GetLength();
	double GetWidth();
	Point GetCenter();

	Rectangle(double length, double width, Point center);
	Rectangle();
};

void DemoRectangleWithPoint();
