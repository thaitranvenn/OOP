#include <iostream>
#include <string>
#include <Windows.h>
#include "CheckInt.h"
#include "GeometricProgram.h"

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int choice = 0;
	GeometricProgram demo;
	while (true)
	{
		system("cls");
		cout << "Menu:\n";
		cout << "0) Exit\n";
		cout << "1) DemoRing()\n";
		cout << "2) DemoCollision()\n";
		choice = CheckInt();
		switch (choice)
		{
			case 0:
			{
				return 0;
			}
			case 1:
			{
				demo.DemoRing();
				system("pause");
				break;
			}
			case 2:
			{
				demo.DemoCollision();
				system("pause");
				break;
			}
			default:
			{
				cout << "Choose one of the proposed items!\n";
				system("pause");
				break;
			}
		}
	}
};