#pragma once
#include"Genre.h"
#include<iostream>
#include<string>
using namespace std;

class Song
{
private:
	string _name;
	double _duration;
	Genre _genre;

public:
	void SetName(string name);
	void SetDuration(double duration);
	void SetGenre(Genre genre);

	string GetName();
	double GetDuration();
	Genre GetGenre();

	Song(string name, double duration, Genre genre);
	Song();
};
