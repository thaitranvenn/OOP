#pragma once
#include "Album.h"

class Band
{
private:
	string _name;
	string _description;
	Album* _albums;
	int _albumsCount;

public:
	void SetName(string name);
	void SetDescription(string description);
	void SetAlbums(Album* albums);
	void SetAlbumCount(int albumCount);

	string GetName();
	string GetDescription();
	Album* GetAlbums();
	int GetAlbumCount();

	Band(string name, string description, Album* albums, int albumCount);
	Band();

	Song* FindSong(string songTitle);
	Album* FindAlbum(Song* song);
	Song* GetAllSongs(int& allSongsCount);
	Song* GetAllGenreSongs(Genre findingGenre, int& allSongsCount);
};

void DemoBand();
