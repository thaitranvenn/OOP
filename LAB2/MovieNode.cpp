#pragma once
#include <iostream>
#include "MovieNode.h"
#include "functions.h"

using namespace std;

void ShowMovieNode(MovieNode* temp)
{
	cout << "\nFilm: " << temp->title;
	cout << "\nDuration(minutes): " << temp->time;
	cout << "\nYear of issue: " << temp->year;
	cout << "\nGenre: " << temp->genre;
	cout << "\nRate: " << temp->rating;
	cout << endl;
}

void DemoMovie()
{
	MovieNode* temp = new MovieNode;
	temp->title = "Click";
	temp->rating = 8.3;
	temp->genre = "Comedy";
	temp->time = 100;
	temp->year = 2001;
	ShowMovieNode(temp);
	delete temp;
}

MovieNode* CinMovieNode()
{
	MovieNode* temp = new MovieNode;
	cout << "\nEnter the title of the movie";
	cin >> temp->title;
	do
	{
		cout << "\nEnter rating of the movie: ";
		cin >> temp->rating;
	} while ((temp->rating > 10) || (temp->rating < 0));
	cout << "\nEnter genre of the movie: ";
	cin >> temp->genre;
	cout << "\nDuration(minutes): ";
	temp->time = CheckInt();
	cout << "\nEnter year of issue: ";
	temp->year = CheckInt();
	return temp;
};

void DemoMovieAdress()
{
	MovieNode temp;
	cout << "\nTemp address: " << &temp << endl;
	temp.title = "1 minute";
	temp.rating = 8.0;
	temp.genre = "Comedy";
	temp.year = 2002;
	temp.time = 100;
	cout << endl;
	ShowMovieNode(&temp);

	MovieNode* newTemp = &temp;
	cout << "\n\nNewTemp address: " << newTemp << endl;
	ShowMovieNode(newTemp);
	cout << endl;
	newTemp->title = "Click";
	newTemp->rating = 8.3;
	newTemp->genre = "Comedy";
	newTemp->time = 90;
	newTemp->year = 2001;
	cout << "\nAfter change: \nNewTemp:" << newTemp << endl;
	ShowMovieNode(newTemp);
	cout << "\nTemp: " << &temp;
	cout << endl;
	ShowMovieNode(&temp);
};

MovieNode* MakeMovie(const char* title, int time, int year, const char* genre, double rating)
{
	MovieNode* temp = new MovieNode;
	temp->title = title;
	temp->time = time;
	temp->year = year;
	temp->genre = genre;
	temp->rating = rating;
	return temp;
}

MovieNode* CopyMovie(MovieNode* Movie)
{
	MovieNode* temp = new MovieNode;
	temp->title = Movie->title;
	temp->time = Movie->time;
	temp->year = Movie->year;
	temp->genre = Movie->genre;
	temp->rating = Movie->rating;
	return temp;
};