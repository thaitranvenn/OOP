#include <iostream>
#include "DoubleValidator.h"
using namespace std;


bool DoubleValidator::IsPositive(double value)
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
		if (IsPositive(value) == false)
		{
			throw exception("Value is negative!");
		}
	}
	catch (const std::exception&)
	{
		cout << "Value is negative!" << endl;
	}
}

void DoubleValidator::AssertValueInRange(double value, double min, double max)
{
	try
	{
		if (IsValueInRange(value, min, max) == false)
		{
			throw exception("Value is out of range!");
		}
	}
	catch (const std::exception&)
	{
		cout << "Value is out of range!" << endl;
	}
}
