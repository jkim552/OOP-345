// Name: Junhee Kim
// Seneca Student ID: 159777184
// Seneca email: jkim552@myseneca.ca
// Date of completion: Nov 8 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef CustomerOrder_H
#define CustomerOrder_H
#include "Station.h"
#include "Utilities.h"
#include <iostream>
struct Item
{
	std::string m_itemName;
	unsigned int m_serialNumber = 0;
	bool m_isFilled = false;

	Item(const std::string& src) : m_itemName(src) {};
};


class CustomerOrder {
	std::string m_name;
	std::string m_product;
	unsigned int m_cntItem;
	Item** m_lstItem;
	static size_t m_widthField;
public:
	// Default Constructor
	CustomerOrder();

	// 1 arg constructor
	CustomerOrder(const std::string&);

	// No copy operation -> throw an exception if called.
	CustomerOrder(const CustomerOrder& c) {
		throw "Copy constructor is not allowed.";
	};

	// Delete copy operator (=)
	CustomerOrder& operator=(const CustomerOrder& c) = delete;

	// Move constructor -> "promise" no exception
	CustomerOrder(CustomerOrder&& copy) noexcept {
		m_name = copy.m_name;
		m_product = copy.m_product;
		m_cntItem = copy.m_cntItem;
		m_lstItem = copy.m_lstItem;
		copy.m_lstItem = nullptr;
	}

	// Move assignment operator -> "promise" no exception
	CustomerOrder& operator=(CustomerOrder&& copy) noexcept {
		if (&copy != this) {
			if (m_lstItem != nullptr) {
				for (unsigned int i = 0; i < m_cntItem; i++) {
					delete m_lstItem[i];
				}
				delete[] m_lstItem;
			}
			m_name = copy.m_name;
			m_product = copy.m_product;
			m_cntItem = copy.m_cntItem;
			m_lstItem = copy.m_lstItem;
			copy.m_lstItem = nullptr;
		}
		return *this;
	}

	// Destructor
	~CustomerOrder();

	// Returns true  if all the items in the order have been filled
	bool isOrderFilled() const;

	// Returns the ItemInfo::m_fillState
	bool isItemFilled(const std::string& itemName) const;

	// Ostream
	void fillItem(Station& station, std::ostream& os);

	// Display
	void display(std::ostream& os) const;
};


#endif //CustomerOrder_H