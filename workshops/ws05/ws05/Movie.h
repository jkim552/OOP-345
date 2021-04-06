#ifndef SDDS_Movie_H
#define SDDS_Movie_H
#include <iostream>
#include <string>
#include "SpellChecker.h"
namespace sdds {
	class Movie {
		std::string m_title;
		size_t m_year;
		std::string m_description;
	public:
		Movie();
		const std::string& title() const;
		Movie(const std::string& strMovie);
		
		template<class T>
		void fixSpelling(T spellChecker) {
			spellChecker(m_title);
			spellChecker(m_description);
		}
		friend std::ostream& operator<<(std::ostream& os, const Movie& m);

	};
}

#endif