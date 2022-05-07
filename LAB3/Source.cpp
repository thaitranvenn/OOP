#include "Menu.h"
#define MENU_EXIT_OPTION 6

void Menu()
{
	//Реализация функций меню
	int option;
	do
	{
		Options();
		option = Choose();

		switch (option)
		{
		case 1:
		{
			system("cls");
			DemoBook();
			break;
		}
		case 2:
		{
			system("cls");
			DemoRoute();
			break;
		}
		case 3:
		{
			system("cls");
			DemoRectangleWithPoint();
			break;
		}
		case 4:
		{
			system("cls");
			DemoFlightWithTime();
			break;
		}
		case 5:
		{
			system("cls");
			DemoBand();
			break;
		}
		}
	} while (option != MENU_EXIT_OPTION);
}

int main()
{
	Menu();
	return 0;
}

//Список вариантов задач
void Options()
{
	cout << "\n=======================================" << endl;
	cout << "|*|____________ WELCOME ____________|*|" << endl;
	cout << "|*|---Select a task from the list---|*|" << endl;
	cout << "|*| 1. Structure Book               |*|" << endl;
	cout << "|*| 2. Structure Route              |*|" << endl;
	cout << "|*| 3. Class Rectangle              |*|" << endl;
	cout << "|*| 4. Class Flight                 |*|" << endl;
	cout << "|*| 5. Class Band                   |*|" << endl;
	cout << "|*| 6. EXIT                         |*|" << endl;
	cout << "================== END ================\n";
}

//Выбор задачи
int Choose()
{
	int number;
	//Бесконечный цикл
	while (true)
	{
		cin >> number;
		if ((cin.good()) && (number <= MENU_EXIT_OPTION) && (number > 0))
		{
			cin.ignore(10, '\n');
			break;
		}
		cin.clear();
		cout << "\nInput error, try again." << endl;
		cin.ignore(10, '\n');
	}
	return number;
}