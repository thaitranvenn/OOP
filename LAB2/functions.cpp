#include <iostream>
#include <exception>
#include <cstdlib>
#include "functions.h"
#include "ContactNode.h"
#include "DisciplineNode.h"
#include "MovieNode.h"
#include "FlightNode.h"
#include "RectangleNode.h"
#include "SongNode.h"
#include "TimeNode.h"
#include "CircleNode.h"
#include "EnumsNode.h"
#include "MovieNodeWithGenre.h"

using namespace std;

// Сортирует массив вещественных чисел
void Sort(double* values, int count)
{
	double swap;
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < count; j++)
		{
			if (values[i] < values[j])
			{
				swap = values[i];
				values[i] = values[j];
				values[j] = swap;
			}
		}
	}
};

// Демонстрирует работу сортировки
void DemoSort()
{
	int count = 0;
	do
	{
		cout << "\nEnter array capacity to demonstration: ";
		count = CheckInt();
	} while (count == 0);

	try
	{
		double* values = new double[count] {100.0, 249.0, 12.0, 45.0, 23.5};
		for (int i = 0; i < count; i++)
		{
			cout << values[i] << " ";
		}
		cout << endl;
		Sort(values, count);
		for (int i = 0; i < count; i++)
		{
			cout << values[i] << " ";
		}
		delete[] values;
	}
	catch (const exception& exception)
	{
		cout << "\nException found! (" << exception.what() << ")\n";
	}
};

void WrongPointers()
{
	FlightNode Flight;
	MovieNode Movie;
	FlightNode* flight = &Flight;
	MovieNode* movie = &Movie;
	flight = CinFlightNode();
	movie = CinMovieNode();
	cout << endl << endl;
	cout << "Address Flight: " << &Flight;
	cout << endl;
	cout << "Address flight: " << flight;
	cout << endl;
	cout << "Address Movie: " << &Movie;
	cout << endl;
	cout << "Address movie: " << movie;
	cout << endl;
};

void DemoEnums()
{
	Colours color = Orange;
	Week day = Monday;
	Genre genre = Drama;
	StudyForm student = Distance;
	Manufacturer phone = Xiaomi;
	Season season = Winter;

	Colours colors[6] = { Red,Orange,Yellow,Green,Pink,Blue };
	Week days[6] = { Tuesday,Wednesday,Thursday,Friday,Saturday,Sunday };
	Genre genres[6] = { Comedy,Drama,Thriller,Action,Horrors,Criminal };
	StudyForm students[6] = { Distance,Intramural,Extramural,Evening,Extramural,Distance };
	Manufacturer phones[6] = { Samsung,Apple,Xiaomi,OnePlus,Huawei,LG };
	Season seasons[6] = { Winter,Spring,Summer,Authumn,Summer,Spring };

	for (int i = 0; i < 6; i++)
	{
		WriteColor(colors[i]);
	}
}

void WriteColor(Colours colors)
{
	switch (colors)
	{
	case Red:
	{
		cout << "Selected Red.\n";
		break;
	}
	case Orange:
	{
		cout << "Selected Orange.\n";
		break;
	}
	case Yellow:
	{
		cout << "Selected Yellow.\n";
		break;
	}
	case Pink:
	{
		cout << "Selected Pink.\n";
		break;
	}
	case Green:
	{
		cout << "Selected Green.\n";
		break;
	}
	case Blue:
	{
		cout << "Selected Blue.\n";
		break;
	}
	case Purple:
	{
		cout << "Selected Purple.\n";
		break;
	}
	}
};

Colours ReadColor()
{
	cout << "\nEnter a number from 0 to 6 (0 - red, 1 - orange, 2 - yellow, 3 - green, 4 - pink, 5 - blue, 6 - purple): \n";
	int temp;
	do
	{
		temp = CheckInt();
	} while ((temp > 6) || (temp < 0));
	switch (temp)
	{
	case Red:
	{
		return Red;
	}
	case Orange:
	{
		return Orange;
	}
	case Yellow:
	{
		return Yellow;
	}
	case Green:
	{
		return Green;
	}
	case Pink:
	{
		return Pink;
	}
	case Blue:
	{
		return Blue;
	}
	case Purple:
	{
		return Purple;
	}
	}
};

int CountRed(Colours* colors, int count)
{
	int temp = 0;
	for (int i = 0; i < count; i++)
	{
		if (colors[i] == Red)
		{
			temp++;
		}
	}
	return temp;
}

int* CountColors(Colours* colors, int count)
{
	int* temp = new int[Purple + 1];
	for (int i = 0; i < Purple + 1; i++)
	{
		temp[i] = 0;
	}
	for (int i = 0; i < count; i++)
	{
		temp[colors[i]]++;
	}
	return temp;
}