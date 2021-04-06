// Name: Junhee Kim
// Seneca Student ID: 159777184
// Seneca email: jkim552@myseneca.ca
// Date of completion: Oct 30 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <iomanip>
#include "Utilities.h"
#include "Station.h"
using namespace std;
// Static member variable
size_t Station::s_widthField = 0;
int Station::id_generator = 0;
// 1 arg custom constructor
Station::Station(const std::string& str) {
	Utilities util;
	s_id = ++id_generator;
	size_t pos = 0;
	bool more = true;
	try {
		s_name = util.extractToken(str, pos, more);	
		s_next = stoi(util.extractToken(str, pos, more));
		s_current = stoi(util.extractToken(str, pos, more));
		s_widthField = util.getFieldWidth() > s_widthField ? util.getFieldWidth() : s_widthField;
		s_description = util.extractToken(str, pos, more);
	}
	catch (string& str) {
		cout << str;
	}
}

// Returns the name of the current Station object
const std::string& Station::getItemName() const {
	return s_name;
}

// Returns the next serial number
unsigned int Station::getNextSerialNumber() {
	return s_next++;
}

// Returns the remaining quantity of the current Station object
unsigned int Station::getQuantity() const {
	return s_current;
}

// Subtracts 1 from the available quantity; should not go below 0.
void Station::updateQuantity() {
	if (s_current != 0) {
		s_current--;
	}
}

// Inserts the content of the current object into first parameter.
void Station::display(std::ostream& os, bool full) const {
	ios init(NULL);
	os.copyfmt(cout);
	os << "[";
	os << right << setw(3) << setfill('0') << s_id;
	os << "] ";

	os << "Item: " << left << setw(s_widthField) << setfill(' ') << s_name;
	os << right << " [";
	os << setw(6) << setfill('0') << s_next;
	os << "]" << left;
	if (full == false) {
		os << endl;
	}
	else {
		os << " Quantity: ";
		os << setw(s_widthField) << setfill(' ') <<  s_current;

		os << " Description: ";
		os << s_description << endl;
	}
}