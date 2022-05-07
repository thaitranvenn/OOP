#include"Album.h"

Album::Album(string name, int year, Song* song, int songCount)
{
	this->SetName(name);
	this->SetYear(year);
	this->SetSongs(song);
	this->SetSongCount(songCount);
}

Album::Album()
{
	this->SetName("unknown");
	this->SetYear(0);
	this->SetSongs(nullptr);
	this->SetSongCount(0);
}

string Album::GetName()
{
	return this->_name;
}

int Album::GetYear()
{
	return this->_year;
}

int Album::GetSongCount()
{
	return this->_songsCount;
}

Song* Album::GetSongs()
{
	return this->_songs;
}

void Album::SetName(string name)
{
	this->_name = name;
}

void Album::SetYear(int year)
{
	if (year < 0 || year >2020)
	{
		throw exception("Year must be greater than 0 and smaller than the current year.");
	}
	this->_year = year;
}

void Album::SetSongs(Song* song)
{
	this->_songs = song;
}

void Album::SetSongCount(int songCount)
{
	if (songCount < 0)
	{
		throw exception("The number of songs must be strictly greater than 0.");
	}
	this->_songsCount = songCount;
}