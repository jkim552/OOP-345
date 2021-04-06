// Name: Junhee Kim
// Seneca Student ID: 159777184
// Seneca email: jkim552@myseneca.ca
// Date of completion: Oct 30 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef Utilities_H
#define Utilities_H
#include <iostream>
class Utilities {
	size_t m_widthField = 1;				// Length of the token extracted
	static char m_delimiter;				// Separates the tokens

public:
	// Sets the field width to the parameter
	void setFieldWidth(size_t newWidth);

	// Returns the field width;
	size_t getFieldWidth() const;

	// Extracts tokens from the first parameter
	std::string extractToken(const std::string& str, size_t& next_pos, bool& more);

	// Sets the delimiter for this class to the character received
	static void setDelimiter(char newDelimiter);

	// Returns the delimiter character
	static char getDelimiter();
};
#endif // !Utilities_H
