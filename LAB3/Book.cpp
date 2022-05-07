#include"Book.h"
#define BOOKS_COUNT 3

void DemoBook()
{
	Book books[BOOKS_COUNT];
	for (int i = 0; i < BOOKS_COUNT; i++)
	{
		ReadBookFromConsole(books[i]);
	}
	for (int i = 0; i < BOOKS_COUNT; i++)
	{
		WriteBookToConsole(books[i]);
	}

	string author;
	cout << "Enter the author whose book you want to find: ";
	getline(cin, author);

	int result = FindBookByAuthor(books, BOOKS_COUNT, author);

	if (result == -1)
	{
		cout << "No books with this author";
	}
	else
	{
		WriteBookToConsole(books[result]);
	}
}

void ReadBookFromConsole(Book& book)
{
	cout << "Enter book title: ";
	getline(cin, book.Title);

	while (true)
	{
		cout << "Enter the year of publication: ";
		cin >> book.Year;
		if (book.Year > 0 && book.Year <= 2020)
		{
			break;
		}
		cout << "Year must be greater than 0 and smaller than the current year.";
		cout << "\nPlease retype the year!" << endl;
		cin.clear();
		cin.ignore(32767, '\n');
	}

	while (true)
	{
		cout << "Enter the number of pages: ";
		cin >> book.Pages;
		if (book.Pages > 0)
		{
			break;
		}
		cout << "The number of pages must be strictly greater than 0.";
		cout << "\nPlease retype the year!" << endl;
		cin.clear();
		cin.ignore(32767, '\n');
	}

	while (true)
	{
		cout << "Enter the number of authors: ";
		cin >> book.AuthorsCount;
		if (book.AuthorsCount > 0 && book.AuthorsCount <= 10)
		{
			break;
		}
		cout << "The number of authors should be in the range of 1-10.";
		cout << "\nPlease retype the year!" << endl;
		cin.clear();
		cin.ignore(32767, '\n');
	}
	cin.clear();
	cin.ignore(32767, '\n');
	for (int i = 0; i < book.AuthorsCount; i++)
	{
		cout << "Enter author: No. " << i + 1 << ": ";
		getline(cin, book.Authors[i]);
	}
}

void WriteBookToConsole(Book& book)
{
	if (book.AuthorsCount > 1)
	{
		for (int i = 0; i < book.AuthorsCount - 1; i++)
		{
			cout << book.Authors[i] << ", ";
		}
	}
	cout << book.Authors[book.AuthorsCount - 1] << " "
		<< book.Title << ". " << book.Year << ". - "
		<< book.Pages << " pages." << endl;
}

int FindBookByAuthor(Book* books, int booksCount, string author)
{
	int index = -1;
	for (int i = 0; i < booksCount; i++)
	{
		for (int j = 0; j < books[i].AuthorsCount; j++)
		{
			if (author == books[i].Authors[j])
			{
				index = i;
				break;
			}
		}
	}
	return index;
}