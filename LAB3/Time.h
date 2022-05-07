#pragma once
#include<exception>
#include<iostream>
using namespace std;

class Time
{
private:
	int _year;
	int _mounth;
	int _day;
	int _hours;
	int _minute;

public:
	void SetYear(int year);
	void SetMonth(int month);
	void SetDay(int day);
	void SetHours(int hours);
	void SetMinute(int minute);

	int GetYear();
	int GetMonth();
	int GetDay();
	int GetHours();
	int GetMinute();

	Time(int year, int mounth, int day, int hours, int minute);
	Time();
};