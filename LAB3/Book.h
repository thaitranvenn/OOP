#pragma once
#include<iostream>
#include<string>
using namespace std;

struct Book
{
	string Title;
	int Year;
	int Pages;
	string Authors[10];
	int AuthorsCount;
};

void DemoBook();
void ReadBookFromConsole(Book& book);
void WriteBookToConsole(Book& book);
int FindBookByAuthor(Book* books, int booksCount, string author);
