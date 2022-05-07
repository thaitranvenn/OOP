#include <iostream>
#include <Windows.h>
#include "Ring.h"
#include "RectangleClass.h"
#include "CollisionManager.h"
#include "GeometricProgram.h"
#include "Ring.h"
#include "CheckInput.h"
#include "DoubleValidator.h"
using namespace std;

void GeometricProgram::DemoCollision()
{
	RectangleClass rectangle1, rectangle2;
	rectangle1.ReadRectanglesFromConsole();
	rectangle2.ReadRectanglesFromConsole();

	switch (CollisionManager::IsCollision(rectangle1, rectangle2))
	{
	case true: cout << "Rectangles intersect" << endl; break;

	case false: cout << "Rectangles do not intersect" << endl; break;
	}

	Point point1, point2;
	point1 = Point(4, 4);
	point2 = Point(5, 5);

	Ring ring1, ring2;
	ring1 = Ring(point1, 10, 7);
	ring2 = Ring(point2, 5, 4);

	switch (CollisionManager::IsCollision(ring1, ring2))
	{
	case true: cout << "Rings intersect" << endl; break;

	case false: cout << "Rings do not intersect" << endl; break;
	}
}

void GeometricProgram::DemoRectangleWithPoint()
{
	RectangleClass rect;
	rect.DemoRectangleWithPoint();
}

void GeometricProgram::DemoRing()
{
	cout << "Number of rings before constructor call: " << Ring::GetAllRingsCount() << endl;

	Ring* ring = new Ring(Point(25.0, 25.0), 10.0, 5.0);
	cout << "Number of rings after constructor call: " << Ring::GetAllRingsCount() << endl;

	delete ring;
	cout << "Number of rings after destructor call: " << Ring::GetAllRingsCount() << endl;

	const int countRings = 3;
	Ring rings[countRings];

	for (int i = 0; i < countRings; i++)
	{
		double innerRadius, outerRadius;
		cout << "Enter inner radius " << i + 1 << "-th rings: ";
		CheckInput::CheckInputDouble(&innerRadius);
		cout << "\nEnter outer radius  " << i + 1 << "-th rings:";
		CheckInput::CheckInputDouble(&outerRadius);

		Point point;
		cout << "\nEnter Center  " << i + 1 << "-th rings: " << endl;
		double X, Y;
		cout << "Enter X: ";
		CheckInput::CheckInputDouble(&X);
		cout << "\nEnter Y: ";
		CheckInput::CheckInputDouble(&Y);

		point = Point(X, Y);

		rings[i] = Ring(point, outerRadius, innerRadius);
		cout << "Created: " << Ring::GetAllRingsCount() << endl;
		rings[i].WriteRingFromConsole();
		double area;
		area = rings[i].GetArea();
		cout << "Square  " << i + 1 << "-th rings: " << area << endl;
	}
}