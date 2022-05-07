#include <iostream>
#include <Windows.h>
#include "Ring.h"
#include "RectangleClass.h"
#include "CollisionManager.h"
#include "GeometricProgram.h"
#include "CheckInput.h"
using namespace std;

int main()
{
	GeometricProgram test;

	while (true)
	{
		int number = 0;
		cout << "Enter menu:" << endl;
		cout << "1. DemoCollision" << endl;
		cout << "2. DemoRectangleWithPoint" << endl;
		cout << "3. DemoRing" << endl;
		CheckInput::CheckInputInt(&number);
		switch (number)
		{
			case 1: test.DemoCollision(); break;
			case 2: test.DemoRectangleWithPoint(); break;
			case 3: test.DemoRing(); break;
		}
	}
}