#include "Song.h"

Song::Song(string name, double duration, Genre genre)
{
	this->SetName(name);
	this->SetDuration(duration);
	this->SetGenre(genre);
}

Song::Song()
{
	this->SetName("unknown");
	this->SetDuration(0);
	this->SetGenre(Default);
}

string Song::GetName()
{
	return this->_name;
}

double Song::GetDuration()
{
	return this->_duration;
}

Genre Song::GetGenre()
{
	return this->_genre;
}

void Song::SetName(string name)
{
	this->_name = name;
}

void Song::SetDuration(double duration)
{
	if (duration < 0)
	{
		throw exception("Duration should be > 0.");
	}
	this->_duration = duration;
}

void Song::SetGenre(Genre genre)
{
	this->_genre = genre;
}