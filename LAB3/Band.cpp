#include"Band.h"
#define  SONGS_COUNT 4
#define  ALBUMS_COUNT 3

Band::Band(string name, string description, Album* albums, int albumCount)
{
	this->SetName(name);
	this->SetDescription(description);
	this->SetAlbums(albums);
	this->SetAlbumCount(albumCount);
}

Band::Band()
{
	this->SetName("unknown");
	this->SetDescription("unknown");
	this->SetAlbums(nullptr);
	this->SetAlbumCount(0);
}

string Band::GetName()
{
	return this->_name;
}

string Band::GetDescription()
{
	return this->_description;
}

Album* Band::GetAlbums()
{
	return this->_albums;
}

int Band::GetAlbumCount()
{
	return this->_albumsCount;
}

void Band::SetName(string name)
{
	this->_name = name;
}

void Band::SetDescription(string description)
{
	this->_description = description;
}

void Band::SetAlbums(Album* albums)
{
	this->_albums = albums;
}

void Band::SetAlbumCount(int albumCount)
{
	if (albumCount < 0)
	{
		throw exception("The number of albums must be strictly greater than 0.");
	}
	this->_albumsCount = albumCount;
}

void DemoBand()
{
	Song* first = new Song[SONGS_COUNT];
	Song* second = new Song[SONGS_COUNT];
	Song* third = new Song[SONGS_COUNT];

	first[0] = Song("Twenty one pilots", 3.52, Rock);
	first[1] = Song("No love for the middle child", 3.08, Rock);
	first[2] = Song("The Rush", 3.08, Rock);
	first[3] = Song("World on Fire", 4.57, Rock);

	second[0] = Song("Weird", 3.18, Rock);
	second[1] = Song("Shutdown", 3.16, Rock);
	second[2] = Song("Never looking back the giving moon", 2.59, Rock);
	second[3] = Song("Not OK!", 3.16, Chanson);

	third[0] = Song("Heat Seaker", 3.01, Rock);
	third[1] = Song("Guys", 4.38, Rock);
	third[2] = Song("Living In a Ghost Town", 4.00, Chanson);
	third[3] = Song("If you are too Shy(Let me know)", 4.10, Rock);

	Album* albums = new Album[ALBUMS_COUNT];
	albums[0] = Album("Dark night", 1998, first, 4);
	albums[1] = Album("Roses", 1989, second, 4);
	albums[2] = Album("Cigarette", 2000, third, 4);

	Band band = Band("Dark night",
		"One of the most popular rock bands of the 199X year.",
		albums, ALBUMS_COUNT);

	string songName;
	cout << "What song information do you want to find?" << endl;
	getline(cin, songName);

	Song* song = band.FindSong(songName);
	if (song == nullptr)
	{
		cout << "No song found" << endl;
	}
	else
	{
		cout << "Title song " << song->GetName()
			<< " found, it has a duration "
			<< song->GetDuration() << "min" << endl;

		Album* album = band.FindAlbum(song);
		if (album == nullptr)
		{
			cout << "No album found!";
		}
		else
		{
			cout << "Album with title " << album->GetName()
				<< " found it has "
				<< album->GetSongCount() << " songs, and went into "
				<< album->GetYear() << " year." << endl;
		}
	}

	int songsCount;
	Song* songs = band.GetAllSongs(songsCount);
	cout << "Total songs of group found: " << songsCount << endl;
	delete[] songs;
	songs = band.GetAllGenreSongs(Rock, songsCount);
	cout << "The total number of songs in the given genre of the group found: " << songsCount << endl;
	delete[] songs;

	delete[] first;
	delete[] second;
	delete[] third;
	delete[] albums;
};

Song* Band::FindSong(string songTitle)
{
	Song* result = nullptr;
	for (int i = 0; i < this->GetAlbumCount(); i++)
	{
		for (int j = 0; j < this->GetAlbums()[i].GetSongCount(); j++)
		{
			if (this->GetAlbums()[i].GetSongs()[j].GetName() == songTitle)
			{
				result = &this->GetAlbums()[i].GetSongs()[j];
				break;
			}
		}
	}
	return result;
};

Album* Band::FindAlbum(Song* song)
{
	Album* result = nullptr;
	for (int i = 0; i < this->GetAlbumCount(); i++)
	{
		for (int j = 0; j < this->GetAlbums()[i].GetSongCount(); j++)
		{
			if ((this->GetAlbums()[i].GetSongs()[j].GetName() == song->GetName()) &&
				(this->GetAlbums()[i].GetSongs()[j].GetDuration() == song->GetDuration()) &&
				(this->GetAlbums()[i].GetSongs()[j].GetGenre() == song->GetGenre()))
			{
				result = &this->GetAlbums()[i];
				break;
			}
		}
	}
	return result;
};

Song* Band::GetAllSongs(int& allSongsCount)
{
	allSongsCount = 0;
	for (int i = 0; i < this->GetAlbumCount(); i++)
	{
		allSongsCount += this->GetAlbums()[i].GetSongCount();
	}
	Song* all = new Song[allSongsCount];
	int k = 0;
	for (int i = 0; i < this->GetAlbumCount(); i++)
	{
		for (int j = 0; j < this->GetAlbums()[i].GetSongCount(); j++, k++)
		{
			all[k] = this->GetAlbums()[i].GetSongs()[j];
		}
	}
	return all;
};

Song* Band::GetAllGenreSongs(Genre findingGenre, int& allSongsCount)
{
	allSongsCount = 0;
	for (int i = 0; i < this->GetAlbumCount(); i++)
	{
		for (int j = 0; j < this->GetAlbums()[i].GetSongCount(); j++)
		{
			if (this->GetAlbums()[i].GetSongs()[j].GetGenre() == findingGenre)
			{
				allSongsCount++;
			}
		}
	}
	Song* all = new Song[allSongsCount];
	int k = 0;
	for (int i = 0; i < GetAlbumCount(); i++)
	{
		for (int j = 0; j < this->GetAlbums()[i].GetSongCount(); j++)
		{
			if (this->GetAlbums()[i].GetSongs()[j].GetGenre() == findingGenre)
			{
				all[k] = this->GetAlbums()[i].GetSongs()[j];
				k++;
			}
		}
	}
	return all;
};