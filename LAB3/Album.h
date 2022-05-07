#pragma once
#include"Song.h"

class Album
{
private:
	string _name;
	int _year;
	Song* _songs;
	int _songsCount;

public:
	void SetName(string name);
	void SetYear(int year);
	void SetSongs(Song* song);
	void SetSongCount(int songCount);

	string GetName();
	int GetYear();
	Song* GetSongs();
	int GetSongCount();

	Album(string name, int year, Song* song, int songCount);
	Album();
};