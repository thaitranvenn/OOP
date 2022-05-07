#include <iostream>
#include "Album.h"
#include "Genre.h"
#include "CheckInput.h"
using namespace std;

void Album::ReadAlbumFromConsole()
{
	cout << "Enter album name: ";
	getline(cin, this->Name);

	bool CheckYear = false;
	while (CheckYear == false)
	{
		try
		{
			cout << "Enter year of issue: ";
			int year;
			CheckInput::CheckInputInt(&year);
			if (year < 0 || year > 2020)
			{
				throw exception("Wrong release year! Re-enter.");
			}
			this->Year = year;
			CheckYear = true;
		}
		catch (const std::exception&)
		{
			cout << "Wrong release year! Retype" << endl;
		}
	}

	bool CheckCountSongs = false;
	while (CheckCountSongs == false)
	{
		try
		{
			cout << "Enter the number of songs in the album: ";
			int count;
			CheckInput::CheckInputInt(&count);
			if (count < 0)
			{
				throw exception("The number cannot be less than 0! Re-enter.");
			}
			this->countSong = count;
			CheckCountSongs = true;
		}
		catch (const std::exception&)
		{
			cout << "The number cannot be less than 0! Re-enter." << endl;
		}
	}
	cin.ignore(32767, '\n');

	this->Songs = new Song[this->countSong];
	for (int i = 0; i < this->countSong; i++)
	{
		cout << "Enter the name of the song No." << i + 1 << ":" << endl;
		this->Songs[i].ReadSongFromConsole();
	}

	for (int i = 0; i < this->countSong; i++)
	{
		if (this->Songs[i].Genre == Rock)
		{
			this->RockCount++;
		}
		if (this->Songs[i].Genre == Metall)
		{
			this->MetallCount++;
		}
		if (this->Songs[i].Genre == HipHop)
		{
			this->HipHopCount++;
		}
		if (this->Songs[i].Genre == Rap)
		{
			this->RapCount++;
		}
		if (this->Songs[i].Genre == Jazz)
		{
			this->JazzCount++;
		}
		if (this->Songs[i].Genre == Classic)
		{
			this->ClassicCount++;
		}
	}
}

void Album::WriteAlbumFromConsole()
{
	cout << "Album: " << this->Name << endl;
	cout << "Year of issue: " << this->Year << endl;
	cout << "The album contains " << this->countSong << " tracks:" << endl;

	for (int i = 0; i < this->countSong; i++)
	{
		cout << i + 1 << "-";
		this->Songs[i].WriteSongFromConsole();
	}
}
