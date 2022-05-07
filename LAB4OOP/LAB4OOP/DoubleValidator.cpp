#include <iostream>
#include "DoubleValidator.h"
using namespace std;


bool DoubleValidator::IsValuePositive(double value)
{
	if (value > 0)
	{
		return true;
	}
	else return false;
}

bool DoubleValidator::IsValueInRange(double value, double min, double max)
{
	if (min < value < max)
	{
		return true;
	}
	else return false;
}

void DoubleValidator::AssertPositiveValue(double value)
{
	try
	{
		if (IsValuePositive(value) == false)
		{
			throw exception("The value is negative!");
		}
	}
	catch (const std::exception&)
	{
		cout << "The value is negative!" << endl;
		system("pause");
	}
}

void DoubleValidator::AssertValueInRange(double value, double min, double max)
{
	try
	{
		if (IsValueInRange(value, min, max) == false)
		{
			throw exception("The value is out of range!");
		}
	}
	catch (const std::exception&)
	{
		cout << "The value is out of range!" << endl;
		system("pause");
	}
}