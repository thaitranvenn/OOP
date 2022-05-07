#include "Time.h"

Time::Time(int year, int month, int day, int hours, int minute)
{
	this->SetYear(year);
	this->SetMonth(month);
	this->SetDay(day);
	this->SetHours(hours);
	this->SetMinute(minute);
}

Time::Time()
{
	this->SetYear(0);
	this->SetMonth(0);
	this->SetDay(0);
	this->SetHours(0);
	this->SetMinute(0);
}

int Time::GetYear()
{
	return this->_year;
}

int Time::GetMonth()
{
	return this->_mounth;
}

int Time::GetDay()
{
	return this->_day;
}

int Time::GetHours()
{
	return this->_hours;
}

int Time::GetMinute()
{
	return this->_minute;
}

void Time::SetYear(int year)
{
	if (year < 0 || year >2020)
	{
		throw exception("The year must be > 0, but not more than the current year.");
	}
	this->_year = year;
}

void Time::SetMonth(int month)
{
	if (month < 0 || month > 12)
	{
		throw exception("The month must be > 0, and no more than 12.");
	}
	this->_mounth = month;
}

void Time::SetDay(int day)
{
	if (day < 0 || day >30)
	{
		throw exception("The day must be > 0, and no more than 31.");
	}
	this->_day = day;
}

void Time::SetHours(int hours)
{
	if (hours < 0 || hours > 24)
	{
		throw exception("The hour must be > 0, and no more than 24.");
	}
	this->_hours = hours;
}

void Time::SetMinute(int minute)
{
	if (minute < 0 || minute >60)
	{
		throw exception("Minutes must be > 0, but not more than 60.");
	}
	this->_minute = minute;
}