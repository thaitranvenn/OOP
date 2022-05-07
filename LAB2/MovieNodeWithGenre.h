#pragma once
#include <string>
#include "EnumsNode.h"

using namespace std;

struct MovieNodeWithGenre
{
	string title;
	int time;
	int year;
	Genre genre;
	double rating = -1;
};
// Структура Фильм
// Начало описания структуры
// Строковое поле Название
// Целочисленное поле Продолжительность в минутах
// Целочисленное поле Год выпуска
// Строковое поле Жанр
// Вещественное поле Рейтинг
// Конец описания структуры
void DemoMovieWithGenre();
MovieNodeWithGenre* CopyMovieWithGenre(MovieNode* Movie);
MovieNodeWithGenre* MakeMovieWithGenre(const char* title, int time, int year, Genre genre, double rating);
int CountMoviesByGenre(MovieNodeWithGenre* movies, int count, Genre findGenre);
MovieNodeWithGenre* FindBestGenreMovie(MovieNodeWithGenre** movies, int count, Genre findGenre);
void CinMovieNodeWithGenre(MovieNodeWithGenre Movies);
MovieNodeWithGenre* CinMovieNodeWithGenrePointer();
void DemoMovieWithGenreForCount();
void ShowMovieNodeWithGenre(MovieNodeWithGenre* temp);