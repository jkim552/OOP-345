#ifndef SDDS_SongCollection_H
#define SDDS_SongCollection_H
#include <iostream>
#include <vector>
#include <list>

namespace sdds {
	struct Song {
		std::string artist = "";
		std::string title = "";
		std::string album = "";
		double price = { 0.0 };
		size_t year = { 0 };
		size_t length = { 0 };
	};

	class SongCollection {
		std::vector<Song> collection;
	public:
		SongCollection(const std::string);
		void display(std::ostream& out) const;
		void sort(const std::string);
		void cleanAlbum();
		bool inCollection(const std::string) const;
		std::list<Song> getSongsForArtist(const std::string) const;

	};
	std::ostream& operator<<(std::ostream& out, const Song& theSong);
}


#endif // !SDDS_SongCollection_H
