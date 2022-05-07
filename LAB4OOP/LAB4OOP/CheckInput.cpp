#include <iostream>
#include "CheckInput.h"
using namespace std;

void CheckInput::CheckInputInt(int* CheckInt)
{
	int index;
	bool correct = false;
	while (!correct) {
		cin >> index;
		if (cin.fail()) {
			cin.clear();
			while (cin.get() != '\n');
			cout << "Please enter a valid value." << endl;
			correct = false;
		}
		else {
			cin.ignore();
			*CheckInt = index;
			correct = true;
		}
	}
}

void CheckInput::CheckInputDouble(double* CheckDouble)
{
	double index;
	bool correct = false;
	while (!correct)
	{
		cin >> index;
		if (cin.fail())
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "Please enter a valid value." << endl;
			correct = false;
		}
		else {
			cin.ignore();
			*CheckDouble = index;
			correct = true;
		}
	}
}
