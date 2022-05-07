#include <iostream>
#include "functions.h"
#include "MovieNodeWithGenre.h"

using namespace std;

void ShowMovieNodeWithGenre(MovieNodeWithGenre* temp)
{
	cout << "\nFilm: " << temp->title;
	cout << "\nDuration(minute): " << temp->time;
	cout << "\nYear of issue: " << temp->year;
	cout << "\nGenre: ";
	switch (temp->genre)
	{
	case Comedy:
	{
		cout << "Comedy";
		break;
	}
	case Drama:
	{
		cout << "Drama";
		break;
	}
	case Thriller:
	{
		cout << "Thriller";
		break;
	}
	case Action:
	{
		cout << "Action";
		break;
	}
	case Horrors:
	{
		cout << "Horrors";
		break;
	}
	case Criminal:
	{
		cout << "Criminal";
		break;
	}
	}
	cout << "Rating: " << temp->rating << "/10" << endl;
};

void DemoMovieWithGenre()
{
	MovieNodeWithGenre Movie;
	Movie.genre = Comedy;
	Movie.time = 90;
	Movie.rating = 8.0;
	Movie.title = "Click";
	Movie.year = 2001;
	cout << "\nInformation: " << endl;
	ShowMovieNodeWithGenre(&Movie);

	cout << "\nSecond film: " << endl;
	MovieNodeWithGenre* SecondMovie = MakeMovieWithGenre("1 minute", 100, 2001, Comedy, 8.5);
	ShowMovieNodeWithGenre(SecondMovie);
	delete SecondMovie;
};

MovieNodeWithGenre* CopyMovieWithGenre(MovieNodeWithGenre* Movie)
{
	MovieNodeWithGenre* temp = new MovieNodeWithGenre;
	temp->title = Movie->title;
	temp->time = Movie->time;
	temp->year = Movie->year;
	temp->genre = Movie->genre;
	temp->rating = Movie->rating;
	return temp;
};

MovieNodeWithGenre* MakeMovieWithGenre(const char* title, int time, int year, Genre genre, double rating)
{
	MovieNodeWithGenre* temp = new MovieNodeWithGenre;
	temp->title = title;
	temp->time = time;
	temp->year = year;
	temp->genre = genre;
	temp->rating = rating;
	return temp;
};

int CountMoviesByGenre(MovieNodeWithGenre** movies, int count, Genre findGenre)
{
	int temp = 0;
	for (int i = 0; i < count; i++)
	{
		if (movies[i]->genre == findGenre)
		{
			temp++;
		}
	}
	return temp;
};


MovieNodeWithGenre* FindBestGenreMovie(MovieNodeWithGenre** movies, int count, Genre findGenre)
{
	double rating = -1;
	int index = -1;
	for (int i = 0; i < count; i++)
	{
		if ((findGenre == movies[i]->genre) && (movies[i]->rating > rating))
		{
			index = i;
			rating = movies[i]->rating;
		}
	}
	MovieNodeWithGenre* temp;
	if (index != -1)
	{
		temp = CopyMovieWithGenre(movies[index]);
	}
	else
	{
		temp = new MovieNodeWithGenre;
		temp->rating = -1;
	}
	return temp;
};


void CinMovieNodeWithGenre(MovieNodeWithGenre Movies)
{
	cout << "\nEnter film title: ";
	cin >> Movies.title;
	do
	{
		cout << "\nEnter film rating: ";
		cin >> Movies.rating;
	} while ((Movies.rating > 10) || (Movies.rating < 0));
	cout << "\nEnter genre: ";
	cout << "\n0 - Comedy; 1 - Drama; 2 - Thriller; 3 - Action; 4 - Horrors; 5 - Crimainal";
	int number;
	do
	{
		cout << "\nEnter genre: ";
		number = CheckInt();
	} while ((number < 0) || (number > 10));
	switch (number)
	{
	case Comedy:
	{
		Movies.genre = Comedy;
	}
	case Drama:
	{
		Movies.genre = Drama;
	}
	case Thriller:
	{
		Movies.genre = Thriller;
	}
	case Action:
	{
		Movies.genre = Action;
	}
	case Horrors:
	{
		Movies.genre = Horrors;
	}
	case Criminal:
	{
		Movies.genre = Criminal;
	}
	}
	cout << "\nDuration(minute): ";
	Movies.time = CheckInt();
	cout << "\nYear of issue: ";
	Movies.year = CheckInt();
};

MovieNodeWithGenre* CinMovieNodeWithGenrePointer()
{
	MovieNodeWithGenre* temp = new MovieNodeWithGenre;
	cout << "\nEnter film title: ";
	cin >> temp->title;
	do
	{
		cout << "\nEnter film rating: ";
		cin >> temp->rating;
	} while ((temp->rating > 10) || (temp->rating < 0));
	cout << "\nEnter genre: ";
	cout << "\n0 - Comedy; 1 - Drama; 2 - Thriller; 3 - Action; 4 - Horrors; 5 - Crimainal";
	int number;
	do
	{
		cout << "\nEnter genre: ";
		number = CheckInt();
	} while ((number < 0) || (number > 10));
	switch (number)
	{
	case Comedy:
	{
		temp->genre = Comedy;
	}
	case Drama:
	{
		temp->genre = Drama;
	}
	case Thriller:
	{
		temp->genre = Thriller;
	}
	case Action:
	{
		temp->genre = Action;
	}
	case Horrors:
	{
		temp->genre = Horrors;
	}
	case Criminal:
	{
		temp->genre = Criminal;
	}
	}
	cout << "\nDuration(minute): ";
	temp->time = CheckInt();
	cout << "\nYear of issue: ";
	temp->year = CheckInt();
	return temp;
};

void DemoMovieWithGenreForCount()
{
	int count;
	int number;
	do
	{
		cout << "Enter the number of records: ";
		count = CheckInt();
		cout << endl;
	} while (count < 1);
	MovieNodeWithGenre** Movies = new MovieNodeWithGenre * [count];
	cout << endl;
	for (int i = 0; i < count; i++)
	{
		Movies[i] = CinMovieNodeWithGenrePointer();
		cout << endl;
	}
	cout << "\n0 - Comedy; 1 - Drama; 2 - Thriller; 3 - Action; 4 - Horrors; 5 - Crimainal";
	do
	{
		cout << "\nEnter the number of the genre need to look for: ";
		number = CheckInt();
	} while ((number < 0) || (number > 5));
	switch (number)
	{
	case Comedy:
	{
		cout << "Number of Comedies: " << CountMoviesByGenre(Movies, count, Comedy);
		break;
	}
	case Drama:
	{
		cout << "Number of Drama: " << CountMoviesByGenre(Movies, count, Drama);
		break;
	}
	case Thriller:
	{
		cout << "Number of Drama: " << CountMoviesByGenre(Movies, count, Thriller);
		break;
	}
	case Action:
	{
		cout << "Number of Drama: " << CountMoviesByGenre(Movies, count, Action);
		break;
	}
	case Horrors:
	{
		cout << "Number of Drama: " << CountMoviesByGenre(Movies, count, Horrors);
		break;
	}
	case Criminal:
	{
		cout << "Number of Drama: " << CountMoviesByGenre(Movies, count, Criminal);
		break;
	}
	}
};