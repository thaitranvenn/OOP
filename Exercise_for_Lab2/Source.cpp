#include <iostream>
#include <string>

using namespace std;

struct Car
{
	string NameOfCar = "", ColorOfCar = "";
	double MaxSpeed = 0;
	int Quantities = 0;
};

void DemoCar(Car ListOfCar[], int number)
{
	for (int i = 0; i < number; i++)
	{
		cin.ignore();
		cout << "\nEnter name of " << i + 1 << "th car: ";
		getline(cin, ListOfCar[i].NameOfCar);
		cout << "\nEnter color of car: ";
		getline(cin, ListOfCar[i].ColorOfCar);
		cout << "\nEnter max speed: ";
		cin >> ListOfCar[i].MaxSpeed;
	}
	for (int i = 0; i < number; i++)
	{
		cout << "______________________________\n" <<
			"Name of " << i + 1 << "th car: " << ListOfCar[i].NameOfCar
			<< "\nColor of car: " << ListOfCar[i].ColorOfCar <<
			"\nMax speed of car: " << ListOfCar[i].MaxSpeed << endl;
	}
}

int CountCarsWithColor(Car ListOfCar[], int number, string color)
{
	int count = 0;
	for (int i = 0; i < number; i++)
	{
		Car pReturn = ListOfCar[i];
		if (ListOfCar[i].ColorOfCar == color)
		{
			count++;
		}
	}
	return count;
}

int main()
{
	Car list[10];
	int number;
	cout << "\n\tEnter number of cars: ";
	cin >> number;
	DemoCar(list, number);

	string color;
	cout << "\n\n\tEnter color: ";
	cin.ignore();
	getline(cin, color);

	cout << "\nNumber of cars with special color: " << CountCarsWithColor(list, number, color);

	cout << endl;
	system("pause");
	return 0;
}