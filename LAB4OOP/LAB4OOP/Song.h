#pragma once
#include <string>
#include "Genre.h"

using namespace std;

class Song
{
public:
	string Name;
	int Minute, Second;
	Genre Genre;
	void ReadSongFromConsole();
	void WriteSongFromConsole();
};