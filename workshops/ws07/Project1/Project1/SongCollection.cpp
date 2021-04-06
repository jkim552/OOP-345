#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm>
#include "SongCollection.h"
using namespace std;

namespace sdds {

	// From provided module W7_P2.cpp
	void printbar(std::ostream& out = std::cout)
	{
		out << std::setw(89) << std::setfill('-') << '\n' << std::setfill(' ');
	}

	SongCollection::SongCollection(const std::string file) {
		ifstream openFile(file);
		if (!openFile) {
			throw "Filename is incorrect!";
			return;
		}
		string str;
		while (openFile.good()) {
			getline(openFile, str);
			Song _song;

			// Title is exactly 25 characters
			_song.title = str.substr(0, 25);
			_song.title.erase(_song.title.find_last_not_of(' ') + 1);
			_song.title.erase(0, _song.title.find_first_not_of(' '));

			// Artist is exactly 25 characters
			_song.artist = str.substr(25, 25);
			_song.artist.erase(_song.artist.find_last_not_of(' ') + 1);
			_song.artist.erase(0, _song.artist.find_first_not_of(' '));

			// Album is exactly 25 characters
			_song.album = str.substr(50, 25); 
			_song.album.erase(_song.album.find_last_not_of(' ') + 1);
			_song.album.erase(0, _song.album.find_first_not_of(' '));

			try {
				_song.year = stoi(str.substr(75, 5));
			}
			// If there are no year to read
			catch (...) {
				_song.year = 0;
			}

			_song.length = stoi(str.substr(80, 5));
			_song.price = stod(str.substr(85, 5));
			collection.push_back(_song);
		}
	}

	void SongCollection::display(std::ostream& out) const {
		size_t time = 0;
		for (auto& songs : collection) {
			out << songs << endl;
			time += songs.length;
		}

		// Part 2 Modification
		int hour = time / 3600;
		int min = (time % 3600) / 60;
		int second = time % 60;
		printbar(out);
		out << "|" << right << setw(85) << setfill(' ');
		out << "Total Listening Time: " + to_string(hour) + ":" + to_string(min) + ":";
		out << to_string(second) + " |" << endl;
		
	}
	ostream& operator<<(ostream& out, const Song& theSong) {
		out << "| " << left << setw(20) << theSong.title << " | ";
		out << left << setw(15) << theSong.artist << " | ";
		out << left << setw(20) << theSong.album << " | ";
		if (theSong.year == 0) {
			out << right << setw(6) << "" << " | ";
		}
		else {
			out << right << setw(6) << theSong.year << " | ";
		}
		out << right << theSong.length / 60 << ":" << setw(2) << setfill('0') << theSong.length % 60 << " | ";
		out << setfill(' ');
		out << fixed << setprecision(2) << theSong.price << " |";
		return out;
	}

	void SongCollection::sort(const std::string str) {
		// Compare the string and sort the order
		if (str == "title") {
			std::sort(collection.begin(), collection.end(), [](Song t1, Song t2) {
				return t1.title < t2.title;});
		}
		else if (str == "album") {
			std::sort(collection.begin(), collection.end(), [](Song a1, Song a2) {
				return a1.album < a2.album;});
		}
		else if (str == "length") {
			std::sort(collection.begin(), collection.end(), [](Song l1, Song l2) {
				return l1.length < l2.length;});
		}
	}
	void SongCollection::cleanAlbum() {
		// If the album is none, change it to empty string
		for (auto& _song : collection) {
			if (_song.album == "[None]") {
				_song.album = "";
			}
		}
	}
	bool SongCollection::inCollection(const std::string str) const {
		bool exists = false;
		// If the artist is in the collection, return true.
		for (auto& _song : collection) {
			if (str == _song.artist) {
				exists = true;
			}
		}
		return exists;
	}
	std::list<Song> SongCollection::getSongsForArtist(const std::string str) const {
		list<Song> songs;
		// Add the song that matches with the artist in the collection to the given parameter 
		for (auto& _song : collection) {
			if (_song.artist == str) {
				songs.push_back(_song);
			}
		}
		return songs;
	}
}