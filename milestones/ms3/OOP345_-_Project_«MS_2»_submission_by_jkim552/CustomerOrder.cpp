// Name: Junhee Kim
// Seneca Student ID: 159777184
// Seneca email: jkim552@myseneca.ca
// Date of completion: Nov 8 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#define _CRT_SECURE_NO_WARNINGS
#include "CustomerOrder.h"
#include "Station.h"
#include "Utilities.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
size_t CustomerOrder::m_widthField = 0;

// Default Constructor
CustomerOrder::CustomerOrder() {
	m_name = "";
	m_product = "";
	m_cntItem = 0;
	m_lstItem = nullptr;
}

// 1 arg Constructor
CustomerOrder::CustomerOrder(const std::string& str) : m_cntItem(0), m_lstItem{nullptr} {
	Utilities util;
	size_t pos = 0;
	bool more = true;
	Item* tempList[100];  // Used to find the unknown size of m_lstItem
	try {
		m_name = util.extractToken(str, pos, more);
		m_product = util.extractToken(str, pos, more);
		std::string temp;
		while (more) {
			temp = util.extractToken(str, pos, more);
			tempList[m_cntItem] = new Item(temp);
			m_cntItem++;
		}
		m_lstItem = new Item * [m_cntItem];
		// Assign the temporary list items into the m_lstItem
		for (unsigned int i = 0; i < m_cntItem; i++) {
			m_lstItem[i] = tempList[i];
		}
		m_widthField = util.getFieldWidth() > m_widthField ? util.getFieldWidth() : m_widthField;
		
	}
	catch (string& str) {
		cout << str;
	}
}

// Destructor
CustomerOrder::~CustomerOrder() {
	if (m_lstItem != nullptr) {
		for (unsigned int i = 0; i < m_cntItem; i++) {
			delete m_lstItem[i];
		}
		delete[] m_lstItem;
	}
}

// Returns true if all the items in the order have been filled
bool CustomerOrder::isOrderFilled() const {
	bool filled = true;
	for (unsigned int i = 0; i < m_cntItem; i++) {
		if (m_lstItem[i]->m_isFilled == false) {
			filled = false;
		}
	}
	return filled;
}

// Returns the ItemInfo::m_fillState
bool CustomerOrder::isItemFilled(const std::string& itemName) const {
	bool notFilled = true;
	for (unsigned int i = 0; i < m_cntItem; i++) {
		if (m_lstItem[i]->m_itemName == itemName) {
			notFilled = m_lstItem[i]->m_isFilled;
		}
	}
	return notFilled;
}

// Ostream 
void CustomerOrder::fillItem(Station& station, std::ostream& os) {
	for (unsigned int i = 0; i < m_cntItem; i++) {
		// if Order contains item
		if (m_lstItem[i]->m_itemName == station.getItemName()) {
			// At least one element
			if (station.getQuantity() > 0) {
				station.updateQuantity();
				m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
				m_lstItem[i]->m_isFilled = true;
				os << "    Filled " << m_name << ", " << m_product << " [" << station.getItemName() << "]" << endl;
			}
			// No element
			else {
				os << "Unable to fill " << m_name << ", " << m_product << " [" << station.getItemName() << "]" << endl;
			}
		}
	}
}

// display
void CustomerOrder::display(std::ostream& os) const {
	os << m_name << " - " << m_product << endl;
	for (unsigned int i = 0; i < m_cntItem; i++) {
		os << "[" << setfill('0') << setw(6) << m_lstItem[i]->m_serialNumber;
		os << "] " << setfill(' ') << setw(m_widthField) << m_lstItem[i]->m_itemName;
		os << " - " << (m_lstItem[i]->m_isFilled ? "FILLED" : "MISSING") << endl;
	}
}
