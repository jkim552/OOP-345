// Name: Junhee Kim
// Seneca Student ID: 159777184
// Seneca email: jkim552@myseneca.ca
// Date of completion: Oct 30 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef Station_H
#define Station_H
#include <iostream>

class Station {
	int s_id;						// ID of a station
	std::string s_name;				// Name of the item
	std::string s_description;		// Description of the station
	int s_next;						// Next serial number
	int s_current;					// Number of current items
	static size_t s_widthField;
	static int id_generator;

public:
	// 1 arg custom constructor
	Station(const std::string&);

	// Returns the name of the current Station object
	const std::string& getItemName() const;

	// Returns the next serial number
	unsigned int getNextSerialNumber();

	// Returns the remaining quantity of the current Station object
	unsigned int getQuantity() const;

	// Subtracts 1 from the available quantity; should not go below 0.
	void updateQuantity();

	// Inserts the content of the current object into first parameter.
	void display(std::ostream& os, bool full) const;
};
#endif // !Station_H
