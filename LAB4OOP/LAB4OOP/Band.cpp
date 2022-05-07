#include <iostream>
#include "Band.h"
#include "CheckInput.h"
using namespace std;

void Band::ReadBandFromConsole()
{
	cout << "Enter a group name: ";
	getline(cin, this->Name);
	cout << "Enter a short description, history of the group: " << endl;
	getline(cin, this->History);

	bool CheckCountMembers = false;
	while (CheckCountMembers == false)
	{
		try
		{
			cout << "Enter the number of group members: ";
			int count;
			CheckInput::CheckInputInt(&count);
			if (count <= 0)
			{
				throw exception("Participants can not be less than one! Re-enter.");
			}
			this->countMembers = count;
			CheckCountMembers = true;
		}
		catch (const std::exception&)
		{
			cout << "Participants can not be less than one! Re-enter." << endl;
		}
	}
	cin.ignore(32767, '\n');

	this->Members = new string[this->countMembers];
	for (int i = 0; i < this->countMembers; i++)
	{
		cout << "Enter name " << i + 1 << "-th participant: ";
		getline(cin, this->Members[i]);
	}

	bool CheckCountAlbums = false;
	while (CheckCountAlbums == false)
	{
		try
		{
			cout << "Enter the number of group albums: ";
			int count;
			CheckInput::CheckInputInt(&count);
			if (count < 0)
			{
				throw exception("The number cannot be less than 0! Re-enter.");
			}
			this->countAlbums = count;
			CheckCountAlbums = true;
		}
		catch (const std::exception&)
		{
			cout << "The number cannot be less than 0! Re-enter." << endl;
		}
	}
	cin.ignore(32767, '\n');

	this->Albums = new Album[this->countAlbums];
	for (int i = 0; i < this->countAlbums; i++)
	{
		cout << "Enter data " << i + 1 << "-th album:" << endl;
		this->Albums[i].ReadAlbumFromConsole();
	}
}

void Band::WriteBandFromConsole()
{
	cout << "Group name: " << this->Name << endl;
	cout << "Brief history of the group:\n" << this->History << endl;
	cout << "The group consists of ";
	if (this->countMembers == 1)
	{
		cout << "one human: " << this->Members[0] << endl;
	}
	else
	{
		cout << this->countMembers << " human:" << endl;
		for (int i = 0; i < this->countMembers; i++)
		{
			cout << i + 1 << " - " << this->Members[i] << endl;
		}
	}

	cout << "The group has ";
	if (this->countAlbums == 1)
	{
		cout << "one album: " << endl;
		this->Albums[0].WriteAlbumFromConsole();
	}
	else
	{
		cout << this->countAlbums << " albums:" << endl;
		for (int i = 0; i < this->countAlbums; i++)
		{
			this->Albums[i].WriteAlbumFromConsole();
		}
	}

	for (int i = 0; i < this->countAlbums; i++)
	{
		this->AllRockCount = this->AllRockCount + this->Albums[i].RockCount;
		this->AllMetallCount = this->AllMetallCount + this->Albums[i].MetallCount;
		this->AllHipHopCount = this->AllHipHopCount + this->Albums[i].HipHopCount;
		this->AllRapCount = this->AllRapCount + this->Albums[i].RapCount;
		this->AllJazzCount = this->AllJazzCount + this->Albums[i].JazzCount;
		this->AllClassicCount = this->AllClassicCount + this->Albums[i].ClassicCount;
	}
}

Song* Band::FindSong(string songTitle)
{
	for (int i = 0; i < this->countAlbums; i++)
	{
		for (int j = 0; j < this->Albums[i].countSong; j++)
		{
			if (songTitle == this->Albums[i].Songs[j].Name)
			{
				this->searchSongResult = this->Albums[i].Songs[j];
				return &this->searchSongResult;
			}
		}
	}
	return nullptr;
}

Album* Band::FindAlbum(Song* song)
{
	for (int i = 0; i < this->countAlbums; i++)
	{
		for (int j = 0; j < this->Albums[i].countSong; j++)
		{
			if (song->Name == this->Albums[i].Songs[j].Name)
			{
				this->searchAlbumResult = this->Albums[i];
				return &this->searchAlbumResult;
			}
		}
	}
	return nullptr;
}

void Band::GetAllSongs()
{
	int g = 0;
	for (int i = 0; i < this->countAlbums; i++)
	{
		for (int j = 0; j < this->Albums[i].countSong; j++)
		{
			this->AllSongsStorage[g] = this->Albums[i].Songs[j];
			g++;
		}
	}
}

void Band::GetAllGenreSongs(Genre findingGenre)
{
	int rockCount = 0;
	int metallCount = 0;
	int hiphopCount = 0;
	int rapCount = 0;
	int jazzCount = 0;
	int classicCount = 0;
	for (int i = 0; i < this->allSongsCount; i++)
	{
		if (this->AllSongsStorage[i].Genre == Rock)
		{
			this->RockStorage[rockCount] = this->AllSongsStorage[i];
			rockCount++;
		}

		if (this->AllSongsStorage[i].Genre == Metall)
		{
			this->MetallStorage[metallCount] = this->AllSongsStorage[i];
			metallCount++;
		}

		if (this->AllSongsStorage[i].Genre == HipHop)
		{
			this->HipHopStorage[hiphopCount] = this->AllSongsStorage[i];
			hiphopCount++;
		}

		if (this->AllSongsStorage[i].Genre == Rap)
		{
			this->RapStorage[rapCount] = this->AllSongsStorage[i];
			rapCount++;
		}

		if (this->AllSongsStorage[i].Genre == Jazz)
		{
			this->JazzStorage[jazzCount] = this->AllSongsStorage[i];
			jazzCount++;
		}

		if (this->AllSongsStorage[i].Genre == Classic)
		{
			this->ClassicStorage[classicCount] = this->AllSongsStorage[i];
			classicCount++;
		}
	}
	//поиск рока
	if (findingGenre == Rock && this->AllRockCount != 0)
	{
		for (int i = 0; i < this->AllRockCount; i++)
		{
			this->RockStorage[i].WriteSongFromConsole();
		}
	}
	else if (findingGenre == Rock && this->AllRockCount == 0)
	{
		cout << "Rock songs not found" << endl;
	}
	//поиск металла
	if (findingGenre == Metall && this->AllMetallCount != 0)
	{
		for (int i = 0; i < this->AllMetallCount; i++)
		{
			this->MetallStorage[i].WriteSongFromConsole();
		}
	}
	else if (findingGenre == Metall && this->AllMetallCount == 0)
	{
		cout << "No songs found in the genre Metal" << endl;
	}
	//поиск хип-хоп
	if (findingGenre == HipHop && this->AllHipHopCount != 0)
	{
		for (int i = 0; i < this->AllHipHopCount; i++)
		{
			this->HipHopStorage[i].WriteSongFromConsole();
		}
	}
	else if (findingGenre == HipHop && this->AllHipHopCount == 0)
	{
		cout << "Hip-hop songs not found" << endl;
	}
	//поиск рэп
	if (findingGenre == Rap && this->AllRapCount != 0)
	{
		for (int i = 0; i < this->AllRapCount; i++)
		{
			this->RapStorage[i].WriteSongFromConsole();
		}
	}
	else if (findingGenre == Rap && this->AllRapCount == 0)
	{
		cout << "Rap songs not found" << endl;
	}
	//поиск Джаз
	if (findingGenre == Jazz && this->AllJazzCount != 0)
	{
		for (int i = 0; i < this->AllJazzCount; i++)
		{
			this->JazzStorage[i].WriteSongFromConsole();
		}
	}
	else if (findingGenre == Jazz && this->AllJazzCount == 0)
	{
		cout << "Jazz songs not found" << endl;
	}
	//поиск Классический
	if (findingGenre == Classic && this->AllClassicCount != 0)
	{
		for (int i = 0; i < this->AllClassicCount; i++)
		{
			this->ClassicStorage[i].WriteSongFromConsole();
		}
	}
	else if (findingGenre == Classic && this->AllClassicCount == 0)
	{
		cout << "No songs found in the genre Classical" << endl;
	}
}
