// Name: Junhee Kim
// Seneca Student ID: 159777184
// Seneca email: jkim552@myseneca.ca
// Date of completion: Oct 30 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <algorithm>
#include "Utilities.h"
using namespace std;

// Static member variable
char Utilities::m_delimiter = ' ';

// Sets the field width to the parameter
void Utilities::setFieldWidth(size_t newWidth){
	m_widthField = newWidth;
}

// Returns the field width;
size_t Utilities::getFieldWidth() const {
	return m_widthField;
}

// Extracts tokens from the first parameter
std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
	std::string tempStr = "";
	size_t start_pos = next_pos;
	// delimiter to extract the next token from str starting at next_pos.
	next_pos = str.find(m_delimiter, start_pos);

	if (next_pos == string::npos) {
		more = false;
		tempStr = str.substr(start_pos);
		m_widthField = (tempStr.length() > m_widthField) ? tempStr.length() : m_widthField;
	}
	else if (start_pos == next_pos) {
		more = false;
		throw "there are two delimiters with no token between them.";
	}
	else {
		more = true;
		size_t new_pos = next_pos - start_pos;
		tempStr = str.substr(start_pos, new_pos);
		m_widthField = (tempStr.length() > m_widthField) ? tempStr.length() : m_widthField;
	}
	next_pos++;
	return tempStr;
}

// Sets the delimiter for this class to the character received
void Utilities::setDelimiter(char newDelimiter) {
	m_delimiter = newDelimiter;
}

// Returns the delimiter character
char Utilities::getDelimiter() {
	return m_delimiter;
}