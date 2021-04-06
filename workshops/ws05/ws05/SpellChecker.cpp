#define _CRT_SECURE_NO_WARNIGS
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "SpellChecker.h"
using namespace std;
namespace sdds {
	SpellChecker::SpellChecker(const char* filename) {
		ifstream file(filename);
		if (!file) {
			throw "Bad file name!";
		}
		string line;
		int counter = 0;
		while (getline(file, line)) {
			istringstream iss(line);
			string temp;
			iss >> temp;
			m_badWords[counter] = temp;
			iss >> temp;
			m_goodWords[counter] = temp;
			counter++;
		}
		file.close();
	}

	void SpellChecker::operator()(std::string& text) const {
		for (int i = 0; i < 5; i++) {
			while (text.find(m_badWords[i]) != std::string::npos) {
				text.replace(text.find(m_badWords[i]), m_badWords[i].length(), m_goodWords[i]);
			}
		}
	}
}