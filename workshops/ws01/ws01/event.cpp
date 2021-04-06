/**********************************************************
 * Name:Junhee Kim
 * Student ID:159777184
 * Date: November 23 2020
 * Seneca email:jkim552@myseneca.ca
 * Section:NHH
 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 **********************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "event.h"


using namespace std;
unsigned int g_sysClock;
namespace sdds {
	Event::Event() {
		setEmpty();
	}
	void Event::setEmpty() {
		description = nullptr;
		time = 0;
	}

	void Event::display() {
		static int counter = 0;
		counter++;
		cout << setw(3) << setfill(' ') << counter << ". ";
		if (description == nullptr) {
			cout << "[ No Event ]" << endl;
		}
		else {
			cout << setw(2) << setfill('0') << (time / 3600) << ":";
			cout << setw(2) << setfill('0') << (time / 60 % 60) << ":";
			cout << setw(2) << setfill('0') << (time % 60); 
			cout << " -> " << description << endl;
		}
	}

	void Event::setDescription(const char* desc) {
		if (desc == nullptr || desc[0] == '\0') {
			setEmpty();
		}
		else {
			if (description != nullptr) {
				delete[] description;
				description = nullptr;
			}
			int len = strlen(desc);
			description = new char[len + 1];
			strcpy(description, desc);
			time = g_sysClock;
		}
	}

	Event::~Event() {
		delete[] description;
		description = nullptr;
	}

	Event::Event(const Event& cp) {
		if (cp.description == nullptr || cp.description[0] == '\0') {
			setEmpty();
		}
		else {
			int len = strlen(cp.description);
			description = new char[len + 1];
			strcpy(description, cp.description);
		}
		time = cp.time;
	}

	Event& Event::operator=(const Event& assign) {
		if (&assign != this) {
			delete[] description;
			setEmpty();
			if (assign.description != nullptr && assign.description[0] != '\0') {
				int len = strlen(assign.description);
				description = new char[len + 1];
				strcpy(description, assign.description);
			}
			time = assign.time;
		}
		return *this;
	}
}