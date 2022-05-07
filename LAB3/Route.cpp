#include "Route.h"
#define ROUTES_COUNT 3

void DemoRoute()
{
	Route routes[ROUTES_COUNT];
	for (int i = 0; i < ROUTES_COUNT; i++)
	{
		ReadRouteFromConsole(routes[i]);
	}
	for (int i = 0; i < ROUTES_COUNT; i++)
	{
		WriteRouteToConsole(routes[i]);
	}

	string stop;
	cout << "Enter the bus station you want to find: ";
	getline(cin, stop);

	int result = FindRouteTo(routes, ROUTES_COUNT, stop);

	if (result == -1)
	{
		cout << "There is no route with this bus station";
	}
	else
	{
		WriteRouteToConsole(routes[result]);
	}
}

void ReadRouteFromConsole(Route& route)
{
	cout << "Enter route number: ";
	cin >> route.Number;

	while (true)
	{
		cout << "Enter the length of the route: ";
		cin >> route.Duration;
		if (route.Duration > 0)
		{
			break;
		}
		cout << "Duration must be strictly > 0.";
		cout << "\nRetype!" << endl;
		cin.clear();
		cin.ignore(32767, '\n');
	}

	while (true)
	{
		cout << "Enter the frequency of the route: ";
		cin >> route.Frequency;
		if (route.Frequency > 0)
		{
			break;
		}
		cout << "The frequency must be strictly > 0.";
		cout << "\nRetype!" << endl;
		cin.clear();
		cin.ignore(32767, '\n');
	}

	while (true)
	{
		cout << "Enter the number of the bus stations: ";
		cin >> route.StopsCount;
		if (route.StopsCount > 0 && route.StopsCount <= 10)
		{
			break;
		}
		cout << "The number of bus stations should be in the range of 1-10.";
		cout << "\nRetype!" << endl;
		cin.clear();
		cin.ignore(32767, '\n');
	}
	cin.clear();
	cin.ignore(32767, '\n');
	for (int i = 0; i < route.StopsCount; i++)
	{
		cout << "Enter bus station: No." << i << ": ";
		getline(cin, route.Stops[i]);
	}
}

void WriteRouteToConsole(Route& route)
{
	cout << "Route No." << route.Number << " duration "
		<< route.Duration << ", go every " << route.Frequency << ",";
	cout << " has the following bus stations: ";
	if (route.StopsCount > 1)
	{
		for (int i = 0; i < route.StopsCount - 1; i++)
		{
			cout << route.Stops[i] << ", ";
		}
	}
	cout << route.Stops[route.StopsCount - 1] << "." << endl;
}

int FindRouteTo(Route* route, int routeCount, string stop)
{
	int index = -1;
	for (int i = 0; i < routeCount; i++)
	{
		for (int j = 0; j < route[i].StopsCount; j++)
		{
			if (stop == route[i].Stops[j])
			{
				index = i;
				break;
			}
		}
	}
	return index;
}