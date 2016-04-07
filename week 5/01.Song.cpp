
#include "stdafx.h"
#include <iostream>
#include <string.h>
#include <stdlib.h>     
#include <time.h>

using namespace std;

class Song
{
public:
	Song(char* name, double length);

	Song(char* name, double length, char* artist);

	Song();

	~Song();

	char* getName() const;
	void setName(char *name);
	double getLength() const;
	void setLength(double length);
	char* getArtist() const;
	void setArtist(char *artist);

private:
	char* name; // име на песнта
	double length;//дължина на песента
	char* artist; // име на певеца(или групата, която изпълнява песента)
};

Song :: Song(char* name, double length)
{
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
	this->length = length;
}

Song :: Song(char* name, double length, char* artist)
{
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);

	this->length = length;

	this->artist = new char[strlen(artist) + 1];
	strcpy_s(this->artist, strlen(artist) + 1, artist);
}

Song::Song()
{
	this->name = NULL;
	this->length = 0;
	this->artist = NULL;
}

Song :: ~Song()
{
	if (this->name != NULL)
	{
		delete[]this->name;
	}

	if (this->artist != NULL)
	{
		delete[]this->artist;
	}
}

char* Song :: getName() const
{
	return this->name;
}

void Song :: setName(char *name)
{
	if (this->name != NULL)
	{
		delete[]this->name;
	}
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}

double Song :: getLength() const
{
	return this->length;
}

void Song :: setLength(double length)
{
	this->length = length;
}

char* Song :: getArtist() const
{
	return this->artist;
}

void Song :: setArtist(char *artist)
{
	if (this->artist != NULL)
	{
		delete[]this->artist;
	}
	this->artist = new char[strlen(artist) + 1];
	strcpy_s(this->artist, strlen(artist) + 1, artist);
}

class Album
{
public:
	void addSong(const Song song); // когато добавяме песни към албум, трябва да се внимава дали песните са на един и същ изпълнител или група
	void removeSong(const char* name); // като аргумент се подава името на песента
	void removeSong(const int index);  //по индекс от масива(започват от 0)
	Song getSongByIndex(int index);

	Album(char* name);

	Album(char* name, Song* songsArr, int capacity, int sizeArr);

	Album();

	~Album();

	Song* getSongsArr()const;
	void setSongsArr(Song*songsArr, int capacity, int sizeSongsArr);
	char* getName()const;
	void setName(char *name);
	int getCountSongs()const;
	int getCapacity()const;
	void setCapacity(int capacity);


private:
	Song*songsArr;
	char*name; // Името на албума;
	int countSongs;
	int capacity;

};

Album :: Album(char* name)
{
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
	this->countSongs = 0;
}

Album :: Album(char* name, Song *songsArr, int capacity, int sizeArr)
{
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);

	this->songsArr = new Song [capacity];
	this->countSongs = sizeArr;
	this->capacity = capacity;
	
	for (int i = 0; i < sizeArr; i++)
	{
		this->songsArr[i] = songsArr[i];
	}
}

Album :: Album()
{
	this->capacity = 30;
	this->countSongs = 0;
	this->name = NULL;
	this->songsArr = NULL;
} 

Album::~Album()
{
	if (this->name != NULL)
	{
		delete[]this->name;
	}

	if (this->songsArr != NULL)
	{
		delete[]this->songsArr;
	}
}

Song * Album :: getSongsArr()const
{
	return this->songsArr;
}

void Album::setSongsArr(Song* songsArr, int capacity, int sizeSongsArr)
{
	if (this->songsArr != NULL)
	{
		delete[]this->songsArr;
	}
	this->songsArr = new Song [capacity];

	for (int i = 0; i < sizeSongsArr; i++)
	{
		this->songsArr[i] = songsArr[i];
	}

	this->capacity = capacity;
}

char* Album::getName()const
{
	return this->name;
}

void Album::setName(char *name)
{
	if (this->name != NULL)
	{
		delete[]this->name;
	}
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}

int Album::getCountSongs()const
{
	return this->countSongs;
}

int Album::getCapacity()const
{
	return this->capacity;
}

void Album::setCapacity(int capacity)
{
	this->capacity = capacity;
}

void Album::addSong(const Song song)
{
	if (this->capacity > this->countSongs)
	{
		this->songsArr[countSongs] = song;
		this->countSongs += 1;
	}
	else
	{
		cout << "You have reached the limit of the album!" << endl;
	}
}

void Album::removeSong(const char* name)
{
	for (int i = 0; i < this->countSongs - 1; i++)
	{
		if (strcmp(this->songsArr[i].getName(), name) == 0)
		{
			for (int j = i; j < this->countSongs - 1; j++)
			{
				this->songsArr[j] = this->songsArr[j + 1];
			}
			this->countSongs -= 1;
		}
	}

	if (strcmp(this->songsArr[this->countSongs].getName(), name) == 0)
	{
		this->countSongs -= 1;
	}
}

void Album::removeSong(const int index)
{
	for (int i = 0; i < this->countSongs - 1; i++)
	{
		if (i == index)
		{
			for (int j = i; j < this->countSongs - 1; j++)
			{
				this->songsArr[j] = this->songsArr[j + 1];
			}
			this->countSongs -= 1;
		}
	}

	if (this->countSongs - 1 == index)
	{
		this->countSongs -= 1;
	}
}

Song Album::getSongByIndex(int index)
{
	return this->songsArr[index];
}

const int capacityALLSongsInMP3 = 1000;
const int capacityALLAlbumsInMP3 = 50;

class MP3Player
{
public:
	MP3Player();
	~MP3Player();
	MP3Player(char*name, Song*songsArr, int sizeSongsArr);
	MP3Player(char*name, Album*albumsArr, int sizeAlbumsArr);
	MP3Player(char*name, Song*songsArr, Album*albumsArr, int sizeSongsArr, int sizeAlbumsArr);

	void addSong(Song song);
	void addSongs(Song*songsArr, int sizeSongsArr);
	void addAlbum(Album album, int songsInAlbum);
	void addAlbums(Album*albumsArr, int sizeAlbumsArr);
	void removeAlbum(char*name);

	void charge();
	void stopCharge();
	void play(bool shuffle); /* пуска песен, но при пускането на песен имаме няколко условия:
							 ако батерията е по-малко от 15 % трябва да бъде изведено съобщение, че батерията налява.
							 при пускането на песента тя хаби толкова батерия колкото е дълга( взима се само цялата част, тоест на песен, която е дълга 2.22 взима 2 % от батерията)
							 ако MP3Player-а се зарежда в момента не можем да пускаме песни.
							 ако нямаме песни също не може да пуснем песни.
							 ако shuffle e true трябва да се пусне рандом песен.
							 ако shuffle e false трябва да се пусне песента последната песен. */

private:
	Song*songsArr;
	Album*albumsArr;
	int capacityAblumsArr;
	int capacitySongsArr;
	int sizeSongsArr;
	int sizeAlbumsArr;
	char*name;
	int countSongs;
	int countAlbums;
	int battery;
	bool isCharging;
};

MP3Player::MP3Player()
{
	this->songsArr = NULL;
	this->albumsArr = NULL;
	this->capacitySongsArr = capacityALLSongsInMP3;
	this->capacityAblumsArr = capacityALLAlbumsInMP3;
	this->sizeSongsArr = 0;
	this->sizeAlbumsArr = 0;
	this->countSongs = 0;
	this->countAlbums = 0;
	this->name = NULL;
	this->battery = 100;
	this->isCharging = false;
}

MP3Player::~MP3Player()
{
	if (this->songsArr != NULL)
	{
		delete[]this->songsArr;
	}

	if (this->albumsArr != NULL)
	{
		delete[]this->albumsArr;
	}

	if (this->name != NULL)
	{
		delete[]this->name;
	}
}

MP3Player::MP3Player(char*name, Song* songsArr, int sizeSongsArr)
{
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);

	this->capacitySongsArr = capacityALLSongsInMP3;
	this->capacityAblumsArr = capacityALLAlbumsInMP3;
	this->countSongs = sizeSongsArr;

	this->songsArr = new Song[capacityALLSongsInMP3];

	this->albumsArr = new Album[capacityALLAlbumsInMP3];

	for (int i = 0; i < sizeSongsArr; ++i)
	{
		this->songsArr[i] = songsArr[i];
	}

	this->countAlbums = 0;
	this->battery = 100;
	this->isCharging = false;
}

MP3Player::MP3Player(char*name, Album* albumsArr, int sizeAlbumsArr)
{
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);

	this->capacitySongsArr = capacityALLSongsInMP3;
	this->capacityAblumsArr = capacityALLAlbumsInMP3;

	this->songsArr = new Song[capacityALLSongsInMP3];
	this->albumsArr = new Album[capacityALLAlbumsInMP3];

	for (int i = 0; i < sizeAlbumsArr; ++i)
	{
		this->albumsArr[i] = albumsArr[i];
	}

	for (int i = 0; i < sizeAlbumsArr; ++i)
	{
		for (int j = 0; j < albumsArr[i].getCountSongs(); ++j)
		{
			this->songsArr[j] = albumsArr[i].getSongByIndex(j);
			this->countSongs += 1;
		}
	}

	this->countAlbums = sizeAlbumsArr;
	this->battery = 100;
	this->isCharging = false;
}

MP3Player::MP3Player(char*name, Song* songsArr, Album* albumsArr, int sizeSongsArr, int sizeAlbumsArr)
{
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);

	this->capacitySongsArr = capacityALLSongsInMP3;
	this->capacityAblumsArr = capacityALLAlbumsInMP3;

	this->songsArr = new Song[capacityALLSongsInMP3];
	this->albumsArr = new Album[capacityALLAlbumsInMP3];

	this->sizeSongsArr = sizeSongsArr;
	this->sizeAlbumsArr = sizeAlbumsArr;

	for (int i = 0; i < sizeAlbumsArr; ++i)
	{
		this->sizeSongsArr += albumsArr[i].getCountSongs();
	}

	for (int i = 0; i < sizeSongsArr; ++i)
	{
		this->songsArr[i] = songsArr[i];
	}

	for (int i = 0; i < sizeAlbumsArr; ++i)
	{
		this->albumsArr[i] = albumsArr[i];
	}

	int counter = this->sizeSongsArr;

	for (int i = 0; i <	sizeAlbumsArr; ++i)
	{
		for (int j = 0; j < albumsArr[i].getCountSongs(); ++j)
		{
			this->songsArr[counter] = albumsArr[i].getSongByIndex(j);
			counter += 1;
		}
	}

	this->battery = 100;
	this->isCharging = false;
}

void MP3Player::addSong(Song song)
{
	if (this->countSongs < capacityALLSongsInMP3)
	{
		this->songsArr[countSongs] = song;
		this->countSongs += 1;
	}
	else
	{
		cout << "You have reached the capacity of the songs and cannot add a new song!" << endl;
	}
}

void MP3Player::addSongs(Song*songsArr, int sizeSongsArr)
{
	if ((this->countSongs + sizeSongsArr) < capacityALLSongsInMP3)
	{
		int index = 0;
		for (int i = this->countSongs; i < (this->countSongs + sizeSongsArr); ++i)
		{
			this->songsArr[i] = songsArr[index];
			index += 1;
		}
	}
	else
	{
		cout << "You have reached the capacity of the songs and cannot add so many song!" << endl;
	}
}

void MP3Player::addAlbum(Album album, int songsInAlbum)
{
	if (this->countAlbums < capacityALLAlbumsInMP3)
	{
		if ((this->countSongs + songsInAlbum) < capacityALLSongsInMP3)
		{
			this->albumsArr[countAlbums] = album;
			this->countAlbums += 1;
			
			int counter = 0;
			for (int i = this->countSongs; i < (this->countSongs + songsInAlbum); ++i)
			{
				this->songsArr[i] = album.getSongsArr()[counter];
				counter += 1;
			}
			this->countSongs += songsInAlbum;
		}
		else
		{
			cout << "You have reached the capacity of the songs and cannot add so many song!" << endl;
		}
	}
	else
	{
		cout << "You have reached the capacity of the albums and cannot add a new album!" << endl;
	}
}

void MP3Player::addAlbums(Album* albumsArr, int sizeAlbumsArr)
{
	int countSongsInAllAlbums = this->countSongs;
	int counter = 0;
	for (int i = this->countAlbums; i < (this->countAlbums + sizeAlbumsArr); ++i)
	{
		countSongsInAllAlbums += albumsArr[counter].getCountSongs();
		counter += 1;
	}

	if ((this->countAlbums + sizeAlbumsArr) < capacityALLAlbumsInMP3)
	{
		if (countSongsInAllAlbums < capacityALLSongsInMP3)
		{
			int index = 0;
			for (int i = this->countAlbums; i < (this->countAlbums + sizeAlbumsArr); ++i)
			{
				this->albumsArr[i] = albumsArr[index];
				index += 1;
			}

			int secIndex = this->countSongs;
			for (int i = 0; i < sizeAlbumsArr; ++i)
			{
				for (int j = 0; j < albumsArr[i].getCountSongs(); ++j)
				{
					this->songsArr[secIndex] = albumsArr[i].getSongByIndex(j);
					secIndex += 1;
				}
			}
			this->countSongs = secIndex;
		}
		else
		{
			cout << "You have reached the capacity of the songs and cannot add so many songs!" << endl;
		}
	}
	else
	{
		cout << "You have reached the capacity of the albums and cannot add a new album!" << endl;
	}
}

void MP3Player::removeAlbum(char*name)
{
	for (int i = 0; i < this->countAlbums; ++i)
	{
		if (strcmp(this->albumsArr[i].getName(), name) == 0)
		{
			int index = 0;
			for (int j = (this->countSongs - this->albumsArr[i].getCountSongs()); j < this->countSongs; ++j)
			{
				for (int p = 0; p < this->countSongs; ++p)
				{
					if (strcmp(this->songsArr[p].getName(), this->albumsArr[i].getSongByIndex(index).getName()) == 0)
					{
						if (p < this->countSongs - 1)
						{
							for (int k = i; j < this->countSongs - 1; ++k)
							{
								this->songsArr[k] = this->songsArr[k + 1];
							}
							this->countSongs -= 1;
						}

						if (p == this->countSongs - 1)
						{
							this->countSongs -= 1;
						}
					}
				}
			}
			if (this->countAlbums - 1 < i)
			{
				for (int j = i; j < this->countAlbums - 1; j++)
				{
					this->albumsArr[j] = this->albumsArr[j + 1];
				}
				this->countAlbums -= 1;
			}
				
			if (this->countAlbums - 1 == i)
			{
				this->countAlbums -= 1;
			}
			
			this->countSongs -= this->albumsArr[i].getCountSongs();
		}
	}
}

void MP3Player::charge()
{
	this->isCharging = true;
	this->battery = 100;
}

void MP3Player::stopCharge()
{
	this->isCharging = false;
}

void MP3Player::play(bool shuffle)
{
	if (this->battery < 15)
	{
		cout << "Low battery!" << endl;
	}

	if (this->isCharging)
	{
		cout << "You cannot play a song because the phone is charging!" << endl;
	}

	if (this->countSongs == 0)
	{
		cout << "You cannot play a song because there are no songs!" << endl;
	}
	
	if (shuffle)
	{
		Song randomSong = this->songsArr[rand() % this->countSongs];
		cout << "You are playing " << randomSong.getName() << "-" << randomSong.getArtist() << "  " << randomSong.getLength() << endl;
	}
	else
	{
		Song lastSong = this->songsArr[this->countSongs - 1];
		cout << "You are playing " << lastSong.getName() << "-" << lastSong.getArtist() << "  " << lastSong.getLength() << endl;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
		char name1Song[32] = "Pesen za domata";
		char name2Song[32] = "Pesen za boba";
		char name3Song[32] = "Gotina pesen";
		char name4Song[32] = "abv";
		char name5Song[32] = "abc";
		char name6Song[32] = "abd";
		char name7Song[32] = "acv";
		char name8Song[32] = "adv";
		char name9Song[32] = "cbv";

		char name1artist[32] = "Bongo";
		char name2artist[32] = "Traqn";
		char name3artist[32] = "Boqn";
		char name4artist[32] = "Bobi";
		char name5artist[32] = "Bob";
		char name6artist[32] = "Bo";
		char name7artist[32] = "Borqn";
		char name8artist[32] = "Korchan";
		char name9artist[32] = "Bojan";

	Song edno(name1Song, 2.1, name1artist);
	Song dve(name2Song, 1.33, name2artist);
	Song tri(name3Song, 1.25, name3artist);
	Song chetiri(name4Song, 1.23, name4artist);
	Song pet(name5Song, 1.3, name5artist);
	Song shest(name6Song, 1.53, name6artist);
	Song sedem(name7Song, 1.45, name7artist);
	Song osem(name8Song, 1.38, name8artist);
	Song devet(name9Song, 1.13, name9artist);
	
	Song albumShakira[20];
	Song albumBoqn[30];
	Song albumCanko[10];
	Song randomSongs[5];

	albumShakira[0] = edno;
	albumShakira[1] = dve;
	albumShakira[2] = tri;
	albumBoqn[0] = chetiri;
	albumBoqn[1] = pet;
	albumBoqn[2] = shest;
	albumCanko[0] = sedem;
	albumCanko[1] = osem;
	albumCanko[2] = devet;
	randomSongs[0] = dve;
	randomSongs[1] = tri;

	char name1Album[32] = "Qk album";
	char name2Album[32] = "Vratsaalbum";
	char name3Album[32] = "Cankosalbum";
	
	Album Shakira(name1Album, albumShakira, 20, 3);
	Album Boqn(name2Album, albumBoqn, 30, 3);
	Album Canko(name3Album, albumCanko, 10, 3);

	Album masivAlbumi[10];
	masivAlbumi[0] = Shakira;
	masivAlbumi[1] = Boqn;
	masivAlbumi[2] = Canko;

	char nameMP3[32] = "myMP3";

	MP3Player mp3(nameMP3, randomSongs, masivAlbumi, 2, 3);

	mp3.play(true);

	return 0;
}

