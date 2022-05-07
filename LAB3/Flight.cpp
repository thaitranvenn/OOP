#include"Flight.h"
#define  FLIGHTS_COUNT 5

Flight::Flight(int number, string departure, string destination, Time start, Time end)
{
	this->SetNumber(number);
	this->SetDeparture(departure);
	this->SetDestination(destination);
	this->SetStart(start);
	this->SetEnd(end);
}

Flight::Flight()
{
	this->SetNumber(0);
	this->SetDeparture("unknown");
	this->SetDestination("unknown");
	this->SetStart(Time());
	this->SetEnd(Time());
}

int Flight::GetNumber()
{
	return this->_number;
}

string Flight::GetDeparture()
{
	return this->_departure;
}

string Flight::GetDestination()
{
	return this->_destination;
}

Time Flight::GetStart()
{
	return this->_start;
}

Time Flight::GetEnd()
{
	return this->_end;
}

void Flight::SetNumber(int number)
{
	if (number < 0)
	{
		throw exception("Flight number must be > 0.");
	}
	this->_number = number;
}

void Flight::SetDeparture(string departure)
{
	this->_departure = departure;
}

void Flight::SetDestination(string destination)
{
	this->_destination = destination;
}

void Flight::SetStart(Time start)
{
	this->_start = start;
}

void Flight::SetEnd(Time end)
{
	if (end.GetYear() < this->GetStart().GetYear())
	{
		throw exception("Arrival time cannot be earlier than departure time.");
	}
	else
	{
		if ((end.GetYear() == this->GetStart().GetYear())
			&& (end.GetMonth() < this->GetStart().GetMonth()))
		{
			throw exception("Arrival time cannot be earlier than departure time.");
		}
		else
		{
			if ((end.GetMonth() == this->GetStart().GetMonth())
				&& (end.GetDay() < this->GetStart().GetDay()))
			{
				throw exception("Arrival time cannot be earlier than departure time.");
			}
			else
			{
				if ((end.GetDay() == this->GetStart().GetDay())
					&& (end.GetHours() < this->GetStart().GetHours()))
				{
					throw exception("Arrival time cannot be earlier than departure time.");
				}
				else
				{
					if ((end.GetHours() == this->GetStart().GetHours()) &&
						(end.GetMinute() < this->GetStart().GetMinute()))
					{
						throw exception("Arrival time cannot be earlier than departure time.");
					}
				}
			}
		}
	}
	this->_end = end;

}

int Flight::GetFlightTimeMinutes()
{
	return this->GetEnd().GetHours() * 60 + this->GetEnd().GetMinute() -
		(this->GetStart().GetHours() * 60 + this->GetStart().GetMinute());
}

void DemoFlightWithTime()
{
	Flight* flights = new Flight[FLIGHTS_COUNT];
	flights[0] = Flight(1, "London", "Moscow", Time(2020, 2, 2, 2, 22), Time(2020, 2, 2, 10, 30));
	flights[1] = Flight(2, "Moscow", "Tomsk", Time(2020, 2, 6, 1, 22), Time(2020, 2, 6, 5, 10));
	flights[2] = Flight(3, "Tomsk", "Tokyo", Time(2020, 4, 20, 5, 22), Time(2020, 4, 20, 12, 30));
	flights[3] = Flight(4, "Tokyo", "Hanoi", Time(2020, 7, 17, 12, 22), Time(2020, 7, 17, 20, 30));
	flights[4] = Flight(5, "Hanoi", "London", Time(2020, 12, 1, 10, 22), Time(2020, 12, 1, 19, 30));

	for (int i = 0; i < FLIGHTS_COUNT; i++)
	{
		cout << "No:" << flights[i].GetNumber() << "  "
			<< flights[i].GetDeparture() << "-" << flights[i].GetDestination()
			<< "  Departure: " << flights[i].GetStart().GetDay() << "/"
			<< flights[i].GetStart().GetMonth() << "/"
			<< flights[i].GetStart().GetYear() << "  "
			<< flights[i].GetStart().GetHours() << ":"
			<< flights[i].GetStart().GetMinute() << "  Arrival "
			<< flights[i].GetEnd().GetDay() << "/"
			<< flights[i].GetEnd().GetMonth() << "/"
			<< flights[i].GetEnd().GetYear() << "  "
			<< flights[i].GetEnd().GetHours() << ":" <<
			flights[i].GetEnd().GetMinute() << endl;
	}
	cout << endl;
	for (int i = 0; i < FLIGHTS_COUNT; i++)
	{
		cout << "No:" << flights[i].GetNumber() << "  "
			<< flights[i].GetDeparture() << "-"
			<< flights[i].GetDestination() << "  Flight time:  "
			<< flights[i].GetFlightTimeMinutes() / 60 << "hours "
			<< flights[i].GetFlightTimeMinutes() % 60 << "minutes " << endl;
	}

	delete[] flights;
}