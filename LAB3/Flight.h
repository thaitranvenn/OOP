#pragma once
#include "Time.h"

class Flight
{
private:
	int _number;
	string _departure;
	string _destination;
	Time _start;
	Time _end;

public:
	void SetNumber(int number);
	void SetDeparture(string departure);
	void SetDestination(string destination);
	void SetStart(Time start);
	void SetEnd(Time end);

	int GetNumber();
	string GetDeparture();
	string GetDestination();
	Time GetStart();
	Time GetEnd();

	int GetFlightTimeMinutes();

	Flight(int number, string departure, string destination, Time start, Time end);
	Flight();
};

void DemoFlightWithTime();
