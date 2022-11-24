#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <unordered_map>
#include <Windows.h>
using namespace std;
enum Style
{
	NONE,
	ROCK,
	JAZZ,
	POP,
	CLASSICAL,
	ELECTRONIC,
	BLUES,
	HIP_HOP,
	DANCE,
	INSTRUMENTAL,
	INDIE,
	SYNTHWAVE
};

unordered_map<std::string, Style>
	const TABLE = {
		{ "NONE", NONE
		},
		{ "ROCK", ROCK
		},
		{ "JAZZ", JAZZ
		},
		{ "POP", POP
		},
		{ "CLASSICAL", CLASSICAL
		},
		{ "ELECTRONIC", ELECTRONIC
		},
		{ "BLUES", BLUES
		},
		{ "HIP_HOP", HIP_HOP
		},
		{ "DANCE", DANCE
		},
		{ "INSTRUMENTAL", INSTRUMENTAL
		},
		{ "INDIE", INDIE
		},
		{ "SYNTHWAVE", SYNTHWAVE
		}
	};

unordered_map<Style, std::string>
	const TABLE_REVERSE = {
		{
			NONE, "NONE" },
		{
			ROCK, "ROCK" },
		{
			JAZZ, "JAZZ" },
		{
			POP, "POP" },
		{
			CLASSICAL, "CLASSICAL" },
		{
			ELECTRONIC, "ELECTRONIC" },
		{
			BLUES, "BLUES" },
		{
			HIP_HOP, "HIP_HOP" },
		{
			DANCE, "DANCE" },
		{
			INSTRUMENTAL, "INSTRUMENTAL" },
		{
			INDIE, "INDIE" },
		{
			SYNTHWAVE, "SYNTHWAVE" }
	};

class Player
{
	static int countOfArtists;
	static int countOfMusic;
	class Artist
	{
		friend Player;
		int countOfMusicArtist = 0;
		string artist_;
		string biography_;
		string country_;
		Artist(string artist, string biography,
			string country);
		Artist(string artist);
		class Music
		{
			friend Player;
			// friend Artist;
			string title_;
			string description_;
			Style style_;
			int year_;
			Music(string title, string description,
				Style style, int year);
			public:
				string getTitle();
			string getDescription();
			Style getStyle();
			int getYear();
			void setTitle(string title);
			void setDescription(string description);
			void setStyle(Style style);
			void setYear(int year);
			bool operator>(const Music &music) const
			{
				return this->title_ > music.title_;
			}

			bool operator < (const Music &music) const
			{
				return this->title_ > music.title_;
			}
		};

		public:
			string getArtist();
		string getBiography();
		string getCountry();
		void setArtist(string artist);
		void setBiography(string biography);
		void setCountry(string country);
		bool operator>(const Artist &artist) const
		{
			return this->artist_ > artist.artist_;
		}

		bool operator < (const Artist &artist) const
		{
			return this->artist_ < artist.artist_;
		}
	};

	// Содержит ключ исполнителя к его песням и ключ к классу исполнителя
	map<string, int> artistsStr_;
	// Содержит исполнителя
	unordered_map<int, Artist> artists_;
	// Содержит песни
	unordered_map<int, map<string, Artist::Music>> artistsSongs_;
	public:
		unordered_map<int, Artist>::iterator addArtist(string artist, string biography,
			string country);
	bool deleteArtist(string artist);
	bool deleteArtist(unordered_map<int, Artist>::iterator artistToDelete);
	pair<bool, unordered_map<int, map< string, Artist::Music >>::iterator>
		getArtistMusic(string artist);
	pair<bool, unordered_map<int, map< string, Artist::Music >>::iterator>
		getArtistMusic(unordered_map<int, Artist>::iterator artist);
	unordered_map<int, map<string, Artist::Music>>::iterator addArtistMusic(string title,
		string artist,
		string description, Style style, int year);
	pair<bool, map<string, Artist::Music >::iterator > deleteArtistMusic(string artist,
		string title);
	pair<bool, map<string, Artist::Music >::iterator > deleteArtistMusic(unordered_map< int,
		Artist >::iterator artist, string title);
	pair<bool, map<string, Player::Artist::Music >::iterator > changeArtistMusic(string title, map<string, Player::Artist::Music>::iterator artist,
		string newTitle, string newDescription, Style newStyle,
		int newYear);
	pair<bool, map<string, Player::Artist::Music >::iterator > changeArtistMusic(string title, string artist,
		string newTitle, string newDescription, Style newStyle,
		int newYear);
	pair<bool, unordered_map<int, Player::Artist >::iterator > changeArtist(string artist,
		string newArtist, string newBiography,
		string newCountry);
	pair<bool, unordered_map<int, Player::Artist >::iterator>
		changeArtist(unordered_map<int, Artist>::iterator artistToChange, string newArtist,
			string newBiography,
			string newCountry);
	void printPlayer(string outputTXT);
};

int Player::countOfMusic = 0;
int Player::countOfArtists = 0;
//-----Music
Player::Artist::Music::Music(string title,
	string description, Style style, int year)
{
	setTitle(title);
	setDescription(description);
	setStyle(style);
	setYear(year);
}

// getters
string Player::Artist::Music::getTitle()
{
	return title_;
}

string Player::Artist::Music::getDescription()
{
	return description_;
}

Style Player::Artist::Music::getStyle()
{
	return style_;
}

int Player::Artist::Music::getYear()
{
	return year_;
}

// setters
void Player::Artist::Music::setTitle(string title)
{
	title_ = title;
}

void Player::Artist::Music::setDescription(string description)
{
	description_ = description;
}

void Player::Artist::Music::setStyle(Style style)
{
	style_ = style;
}

void Player::Artist::Music::setYear(int year)
{
	year_ = year;
}

//-----Artist
Player::Artist::Artist(string artist, string biography,
	string country)
{
	artist_ = artist;
	biography_ = biography;
	country_ = country;
}

Player::Artist::Artist(string artist)
{
	artist_ = artist;
}

// getters
string Player::Artist::getArtist()
{
	return artist_;
}

string Player::Artist::getBiography()
{
	return biography_;
}

string Player::Artist::getCountry()
{
	return country_;
}

// setters
void Player::Artist::setArtist(string artist)
{
	artist_ = artist;
}

void Player::Artist::setBiography(string biography)
{
	biography_ = biography;
}

void Player::Artist::setCountry(string country)
{
	country_ = country;
}

//-----Player
unordered_map<int, Player::Artist>::iterator Player::addArtist(string artist, string biography,
	string country)
{
	Artist insertArtist(artist, biography, country);
	// Вставляем исполнителя в качестве ключа,
	// а в качестве значения - его "индекс" в map песен
	auto insertedArtist = artists_.insert({ countOfArtists, insertArtist });
	// Вставляем в artistsStr_, для навигации в artists_
	artistsStr_.insert({ artist, countOfArtists });
	// создаем контейнер для композиций исполнителя
	map<string, Player::Artist::Music > temp;
	// добавляем в общий список песен под ключом номера
	// исполнителя
	artistsSongs_.insert({ countOfArtists, temp });
	countOfArtists++;
	return insertedArtist.first;
}

bool Player::deleteArtist(string artist)
{
	// Ищем исполнителя (строку)
	auto artistToDeleteStr = artistsStr_.find(artist);
	if (artistToDeleteStr != artistsStr_.end())
	{
		// Ищем исполнителя (класс)
		auto artistToDelete = artists_.find(artistToDeleteStr->second);
		countOfMusic -= artistToDelete->second.countOfMusicArtist;
		// Удаляем его песни
		artistsSongs_.erase(artistToDelete->first);
		// Удаляем исполнителя
		artists_.erase(artistToDelete);
		countOfArtists--;
		return true;
	}

	return false;
}

bool Player::deleteArtist(unordered_map<int, Artist>::iterator artistToDelete)
{
	countOfMusic -= artistToDelete->second.countOfMusicArtist;
	// Удаляем его песни
	artistsSongs_.erase(artistToDelete->first);
	// Удаляем исполнителя
	artists_.erase(artistToDelete);
	countOfArtists--;
	return true;
}

pair<bool, unordered_map<int, Player::Artist >::iterator>
	Player::changeArtist(unordered_map<int, Artist>::iterator artistToChange, string newArtist, string newBiography,
		string newCountry)
	{
		artistToChange->second.setArtist(newArtist);
		artistToChange->second.setBiography(newBiography);
		artistToChange->second.setCountry(newCountry);
		pair<bool, unordered_map<int, Player::Artist >::iterator>
			Changed({ true, artistToChange });
		return Changed;
	}

pair<bool, unordered_map<int, Player::Artist >::iterator > Player::changeArtist(string artist, string newArtist, string newBiography,
	string newCountry)
{
	auto artistToChangeStr = artistsStr_.find(artist);
	if (artistToChangeStr != artistsStr_.end())
	{
		// Ищем исполнителя (класс)
		auto artistToChange = artists_.find(artistToChangeStr->second);
		artistToChange->second.setArtist(newArtist);
		artistToChange->second.setBiography(newBiography);
		artistToChange->second.setCountry(newCountry);
		pair<bool, unordered_map<int, Player::Artist >::iterator>
			Changed({ true, artistToChange });
		return Changed;
	}

	return {
		false, artists_.end()
	};

}

pair<bool, unordered_map<int, map< string, Player::Artist::Music >>::iterator>
	Player::getArtistMusic(string artist)
	{
		// Ищем исполнителя
		auto artistToAddMusic = artistsStr_.find(artist);
		if (artistToAddMusic != artistsStr_.end())
		{
			// Ищем список песен по индексу
			auto findListOfMusicArtist =
				artistsSongs_.find(artistToAddMusic->second);
			pair<bool, unordered_map<int, map< string, Player::Artist::Music >>::iterator>
				Found({ true, findListOfMusicArtist });
			return Found;
		}

		return { 	false, artistsSongs_.end()
		};

	}

pair<bool, unordered_map<int, map< string, Player::Artist::Music >>::iterator>
	Player::getArtistMusic(unordered_map<int, Artist>::iterator artist)
	{
		// Ищем список песен по индексу
		auto findListOfMusicArtist =
			artistsSongs_.find(artist->first);
		pair<bool, unordered_map<int, map< string, Player::Artist::Music >>::iterator>
			Found({ true, findListOfMusicArtist });
		return Found;
	}

unordered_map<int, map<string, Player::Artist::Music>>::iterator
Player::addArtistMusic(string title, string artist,
	string description, Style style, int year)
{
	// Ищем исполнителя (по строке)
	auto artistStr = artistsStr_.find(artist);
	// Ищем класс исполнителя
	auto foundArtist = artists_.find(artistStr->second);
	// Ищем список песен исполнителя
	auto findListOfMusicArtist = getArtistMusic(artist);
	// Создаем заданную музыку
	Artist::Music music(title, description, style, year);
	// Ключ - название песни, значение - музыка
	findListOfMusicArtist.second->second.insert({ title, music });
	foundArtist->second.countOfMusicArtist++;
	countOfMusic++;
	return findListOfMusicArtist.second;
}

pair<bool, map<string, Player::Artist::Music >::iterator > Player::deleteArtistMusic(string artist, string title)
{
	// Ищем исполнителя (по строке)
	auto artistStr = artistsStr_.find(artist);
	// Ищем класс исполнителя
	auto foundArtist = artists_.find(artistStr->second);
	// Ищем список песен исполнителя
	auto findListOfMusicArtist = getArtistMusic(artist);
	// Находим в списке песню
	auto foundMusic = findListOfMusicArtist.second->second.find(title);
	// Если таковая имеется
	if (foundMusic != findListOfMusicArtist.second->second.end())
	{
		// Удаляем по названию композиции
		map<string, Player::Artist::Music>::iterator iter = --foundMusic;
		findListOfMusicArtist.second->second.erase(foundMusic);
		foundArtist->second.countOfMusicArtist--;
		return { 	true, iter
		};

	}

	return {
		false, findListOfMusicArtist.second->second.end()
	};

}

pair<bool, map<string, Player::Artist::Music >::iterator>
	Player::deleteArtistMusic(unordered_map<int, Artist>::iterator artist, string title)
	{
		// Ищем список песен исполнителя
		auto findListOfMusicArtist = getArtistMusic(artist);
		// Находим в списке песню
		auto foundMusic = findListOfMusicArtist.second->second.find(title);
		// Если таковая имеется
		if (foundMusic != findListOfMusicArtist.second->second.end())
		{
			// Удаляем по названию композиции
			map<string, Player::Artist::Music>::iterator iter = --foundMusic;
			findListOfMusicArtist.second->second.erase(foundMusic);
			artist->second.countOfMusicArtist--;
			return { 	true, iter
			};

		}

		return { 	false, findListOfMusicArtist.second->second.end()
		};

	}

pair<bool, map<string, Player::Artist::Music >::iterator > Player::changeArtistMusic(string title, map<string, Player::Artist::Music>::iterator musicIter,
	string newTitle, string newDescription, Style newStyle,
	int newYear)
{
	Artist::Music music(newTitle, newDescription, newStyle, newYear);
	musicIter->second = music;
	return {
		true, musicIter
	};

}

pair<bool, map<string, Player::Artist::Music >::iterator > Player::changeArtistMusic(string title, string artist,
	string newTitle, string newDescription, Style newStyle,
	int newYear)
{
	// Ищем список песен исполнителя
	auto findListOfMusicArtist = getArtistMusic(artist);
	// Находим в списке песню
	auto foundMusic = findListOfMusicArtist.second->second.find(title);
	// Если таковая имеется
	if (foundMusic != findListOfMusicArtist.second->second.end())
	{
		Artist::Music music(newTitle, newDescription, newStyle, newYear);
		foundMusic->second = music;
		return { 	true, foundMusic
		};

	}

	return {
		false, findListOfMusicArtist.second->second.end()
	};

}

void Player::printPlayer(string outputTXT)
{
	ofstream out(outputTXT);
	for (auto iterArtist = artists_.begin(); iterArtist != artists_.end(); iterArtist++)
	{
		out << iterArtist->second.getArtist() << " | " << iterArtist -
			>
			second.getBiography() << " | " <<
			iterArtist->second.getCountry() << '\n';
		auto iterSongs = artistsSongs_.find(iterArtist->first);
		for (auto song = iterSongs->second.begin(); song != iterSongs->second.end(); song++)
		{
			auto style = TABLE_REVERSE.find(song->second.getStyle());
			out << song->second.getTitle() << " | " << song->second.getDescription() << " |
				" <<
			style->second << " | " << song->second.getYear() << '\n';
		}

		out << '\n';
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");
	ifstream in ("input.txt");
	Player player;
	string s;
	string group, artistName, artistBiography,
	artistCountry;
	string title, description, style, year;
	while (in .peek() != EOF)
	{
		getline(in, s, '|');
		group = s;
		getline(in, artistBiography, '|');
		getline(in, artistCountry);
		player.addArtist(group, artistBiography,
			artistCountry);
		getline(in, s, '|');
		while (s != "-")
		{
			title = s;
			getline(in, description, '|');
			getline(in, style, '|');
			getline(in, year);
			// Ставим соответствие между ENUM и string
			auto it = TABLE.find(style);
			if (it != TABLE.end())
			{
			 	// Заносим в плеер
				player.addArtistMusic(title, group,
					description, it->second, stoi(year));
			}
			else
			{
			 	// Заносим в плеер
				player.addArtistMusic(title, group,
					description, NONE, stoi(year));
			}

			getline(in, s, '|');
		}

		getline(in, s);
	}

	player.changeArtist("The Weeknd", "The Weeknd", "Description The Weeknd", "USA");
	// Добавляем солиста в список
	player.addArtist("Solist", "Description Solist", "Solist's country");
	// Получаем список песен распавшейся группы
	auto oldArtist = player.getArtistMusic("Daft Punk");
	auto OldList = oldArtist.second->second;
	// Ищем последний год выпущенной песни
	int maxYear = 0;
	for (auto it = OldList.begin(); it != OldList.end(); it++)
	{
		int currentYear = it->second.getYear();
		if (maxYear < currentYear)
		{
			maxYear = currentYear;
		}
	}

	// Перемещаем песни к солисту
	for (auto it = OldList.begin(); it != OldList.end(); it++)
	{
		int currentYear = it->second.getYear();
		if (currentYear == maxYear)
		{
			player.addArtistMusic(it->second.getTitle(), "Solist",
				it->second.getDescription(), it->second.getStyle(), it -
				>
				second.getYear());
		}
	}

	// Вывод
	player.printPlayer("output.txt"); in .close();
	return 0;
}