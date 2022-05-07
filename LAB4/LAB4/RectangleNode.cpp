#include "RectangleNode.h";
#include <iostream>
#include "CheckInt.h"

using namespace std;

double RectangleNode::getLength()
{
	return this->length;
};

double RectangleNode::getWidth()
{
	return this->width;
};

RectangleNode::RectangleNode()
{
	int choice;
	do
	{
		cout << "Enter 1 for autofill.\n";
		cout << "Enter 2 to fill in manually.\n";
		choice = CheckInt();
	} while (choice < 1 || choice>2);
	if (choice == 2)
	{
		this->Point = new PointNode();
		cout << "Enter the length of the rectangle: ";
		this->length = CheckDouble();
		cout << endl;
		cout << "Enter the width of the rectangle: ";
		this->width = CheckDouble();
		cout << endl;
	}
	else//Иначе будет только 1
	{
		this->length = RandDouble();
		this->width = RandDouble();
		this->Point = new PointNode(this->length, this->width);
		this->length = RandDouble();
		this->width = RandDouble();
	}
};

RectangleNode::RectangleNode(PointNode p, double length, double width)
{
	this->Point = &p;
	this->length = length;
	this->width = width;
};

void RectangleNode::ShowNode()
{
	cout << "X: " << this->Point->GetX();
	cout << " Y: " << this->Point->GetY();
	cout << " length: " << this->getLength();
	cout << " width: " << this->getWidth() << endl;
};

void DemoRectangleNodeWithPoints()
{
	const int count = 5;
	RectangleNode** Rectangle = new RectangleNode * [count];
	for (int i = 0; i < count; i++)
	{
		cout << endl;
		cout << "Enter data for rectangle 1\n";
		Rectangle[i] = new RectangleNode;
	}
	cout << endl;
	for (int i = 0; i < count; i++)
	{
		Rectangle[i]->ShowNode();
		cout << endl;
		cout << "Xcenter = " << Rectangle[i]->getCenterX();
		cout << endl;
		cout << "Ycenter = " << Rectangle[i]->getCenterY();
		cout << endl;
	}
};

double RectangleNode::getCenterX()
{
	double temp = this->Point->GetX();
	temp += this->getLength() / 2;
	return temp;
};

double RectangleNode::getCenterY()
{
	double temp = this->Point->GetY();
	temp += this->getWidth() / 2;
	return temp;
};