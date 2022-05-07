#include <iostream>
#include "Song.h"
#include "Genre.h"
#include "CheckInput.h"
using namespace std;

void Song::ReadSongFromConsole()
{
	cout << "Enter song title: ";
	getline(cin, this->Name);

	bool CheckMinute = false;
	while (CheckMinute == false)
	{
		try
		{
			cout << "\nEnter how many minutes the song is: ";
			int minutes;
			CheckInput::CheckInputInt(&minutes);
			if (minutes < 0)
			{
				throw exception("The number of minutes must not be negative! Retype.");
			}
			this->Minute = minutes;
			CheckMinute = true;
		}
		catch (const std::exception&)
		{
			cout << "The number of minutes must not be negative! Retype." << endl;
		}
	}

	bool CheckSecond = false;
	while (CheckSecond == false)
	{
		try
		{
			cout << "\nEnter how many seconds the song lasts: ";
			int seconds;
			CheckInput::CheckInputInt(&seconds);
			if (seconds < 0 || seconds > 2020)
			{
				throw exception("The number of seconds in the track must be between 0 and 60! Re-enter.");
			}
			this->Second = seconds;
			CheckSecond = true;
		}
		catch (const std::exception&)
		{
			cout << "The number of seconds in the track must be between 0 and 60! Re-enter." << endl;
		}
	}
	cin.ignore(32767, '\n');

	cout << "Select song genre:" << endl;
	cout << "1. Rock" << endl;
	cout << "2. Metal" << endl;
	cout << "3. Hip-hop" << endl;
	cout << "4. Rap" << endl;
	cout << "5. Jazz" << endl;
	cout << "6. Classic" << endl;
	string genre;

	bool CheckGenre = false;
	while (CheckGenre == false)
	{
		try
		{
			getline(cin, genre);
			if (genre == "1" || genre == "Rock" || genre == "Rock")
			{
				this->Genre = Rock;
			}
			else if (genre == "2" || genre == "Metal" || genre == "Metal" || genre == "Metal" || genre == "Metal")
			{
				this->Genre = Metall;
			}

			else if (genre == "3" || genre == "Hip-hop" || genre == "Hip-hop" || genre == "Hip-hop" || genre == "Hip-hop")
			{
				this->Genre = HipHop;
			}

			else if (genre == "4" || genre == "Rap" || genre == "Rap" || genre == "Rap" || genre == "Rap")
			{
				this->Genre = Rap;
			}

			else if (genre == "5" || genre == "Jazz" || genre == "Jazz")
			{
				this->Genre = Jazz;
			}

			else if (genre == "6" || genre == "Classic" || genre == "Classic")
			{
				this->Genre = Classic;
			}
			else
			{
				throw exception("This genre was not found! Retype.");
			}
			CheckGenre = true;
		}
		catch (const std::exception&)
		{
			cout << "This genre was not found! Retype." << endl;
		}
	}
}

void Song::WriteSongFromConsole()
{
	cout << " Track: " << this->Name << " Genre: ";
	if (this->Genre == Genre::Rock)
	{
		cout << "Rock ";
	}
	else if (this->Genre == Genre::Metall)
	{
		cout << "Metal ";
	}
	else if (this->Genre == Genre::HipHop)
	{
		cout << "Hip-hop ";
	}
	else if (this->Genre == Genre::Rap)
	{
		cout << "Rap ";
	}
	else if (this->Genre == Genre::Jazz)
	{
		cout << "Jazz ";
	}
	else if (this->Genre == Genre::Classic)
	{
		cout << "Classic ";
	}

	cout << "Duration: " << this->Minute << ":" << this->Second << endl;
}