#include <iostream>
#include "Ring.h"
#include "CheckInput.h"
#include "DoubleValidator.h"
using namespace std;

int Ring::AllRingsCount = 0;

void Ring::AssertOnPositiveValue(double outerRadius, double innerRadius)
{
	if (true)
	{
		DoubleValidator::AssertPositiveValue(outerRadius);
		DoubleValidator::AssertPositiveValue(innerRadius);
		/*try
		{
			if (outerRadius <= 0 || innerRadius <= 0)
			{
				throw exception("Radius must be a real positive number!");
			}

		}
		catch (const std::exception&)
		{
			cout << "The radius must be a real positive number!" << endl;
		}*/

		try
		{
			if (outerRadius < innerRadius)
			{
				throw exception("The inner radius cannot be greater than the outer one!");
			}

		}
		catch (const std::exception&)
		{
			cout << "The inner radius cannot be greater than the outer one!" << endl;
			system("pause");
		}
	}
}

void Ring::ReadRingFromConsole(Point center, double outerRadius, double innerRadius)
{
	AssertOnPositiveValue(outerRadius, innerRadius);

	this->_center = center;
	this->_outerRadius = outerRadius;
	this->_innerRadius = innerRadius;
}

void Ring::WriteRingFromConsole()
{
	cout << "Outer ring radius: " << this->_innerRadius << endl;
	cout << "Ring inner radius: " << this->_outerRadius << endl;
	this->_center.WritePointFromConsole();
}

int Ring::GetAllRingsCount()
{
	return AllRingsCount;
}

double Ring::GetOuterRadius()
{
	return this->_outerRadius;
}

double Ring::GetPointX()
{
	return this->_center.GetX();
}

double Ring::GetPointY()
{
	return this->_center.GetY();
}

double Ring::GetArea()
{
	double Area;
	Area = (3.1415 * this->_outerRadius - 3.1415 * this->_innerRadius);
	return Area;
}

Ring::Ring()
{
	Ring::AllRingsCount++;
}

Ring::Ring(Point center, double outerRadius, double innerRadius)
{
	Ring::AllRingsCount++;
	ReadRingFromConsole(center, outerRadius, innerRadius);

}

Ring::~Ring()
{
	Ring::AllRingsCount--;
	cout << "Left: " << Ring::AllRingsCount << endl;
}