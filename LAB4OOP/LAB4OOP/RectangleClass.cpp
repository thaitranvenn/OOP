#include <iostream>
#include "RectangleClass.h"
#include "CheckInput.h"
#include "DoubleValidator.h"
using namespace std;

void RectangleClass::ReadRectanglesFromConsole()
{
	cout << "Set values yourself or programmatically? \n1. On one's own\n2. Programmatically" << endl;
	int Switch;
	cin >> Switch;
	switch (Switch)
	{
	case 1:
	{
		bool CheckLength = false;
		while (CheckLength == false)
		{
			cout << "Enter the length of the rectangle: ";
			double Length;
			CheckInput::CheckInputDouble(&Length);
			DoubleValidator::AssertPositiveValue(Length);
			this->Length = Length;
			CheckLength = true;
		}

		bool CheckWidth = false;
		while (CheckWidth == false)
		{
			cout << "\nEnter the width of the rectangle: ";
			double Width;
			CheckInput::CheckInputDouble(&Width);
			DoubleValidator::AssertPositiveValue(Width);
			this->Width = Width;
			CheckWidth = true;

		}

		cout << "Enter the coordinates of the center of the rectangle:" << endl;
		double X, Y;
		cout << "Enter X: ";
		CheckInput::CheckInputDouble(&X);
		cout << "\nEnter Y: ";
		CheckInput::CheckInputDouble(&Y);
		point = Point(X, Y);
	} break;

	case 2:
	{
		double max = 1000.45654;
		double min = -1000.45654;
		double X, Y;
		this->Length = (double)(rand()) / RAND_MAX * max;
		this->Width = (double)(rand()) / RAND_MAX * max;
		X = (double)(rand()) / RAND_MAX * (max - min);
		Y = (double)(rand()) / RAND_MAX * (max - min);
		point = Point(X, Y);
	} break;
	}
}

void RectangleClass::WriteRectanglesFromConsole()
{
	this->point.WritePointFromConsole();
	cout << "\nLength = " << this->Length << "; Width = " << this->Width << endl;
}

void RectangleClass::DemoRectangleWithPoint()
{
	this->ReadRectanglesFromConsole();
	this->WriteRectanglesFromConsole();
}

double RectangleClass::GetLength()
{
	return Length;
}

double RectangleClass::GetWidth()
{
	return Width;
}

double RectangleClass::GetPointX()
{
	return this->point.GetX();
}

double RectangleClass::GetPointY()
{
	return this->point.GetY();
}
