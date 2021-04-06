#ifndef SDDS_SpellChecker_H
#define SDDS_SpellChecker_H
#include <iostream>
#include <string>
namespace sdds {
	class SpellChecker {
		std::string m_badWords[5];
		std::string m_goodWords[5];
	public:
		SpellChecker(const char* filename);
		void operator()(std::string& text) const;
	};

}
#endif