#pragma once
#include "PointNode.h"

class RectangleNode
{
public:
	RectangleNode();
	RectangleNode(PointNode p, double length, double width);
	double getLength();
	double getWidth();
	void ShowNode();
	double getCenterX();
	double getCenterY();
private:
	PointNode* Point;
	double length;
	double width;
};

void DemoRectangleNodeWithPoints();