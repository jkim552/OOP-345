// Name: Junhee Kim
// Seneca Student ID: 159777184
// Seneca email: jkim552@myseneca.ca
// Date of completion: Nov 19 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include "Workstation.h"
using namespace std;

Workstation::Workstation(const std::string& str) : Station(str) {
	m_pNextStation = nullptr;
}// custom constructor

void Workstation::runProcess(std::ostream& os) {
	if (!m_orders.empty()) {
		m_orders.front().fillItem(*this, os);
	}
}// runs a single cycle of the assembly line

bool Workstation::moveOrder() {
	bool queue = true;
	// queue is empty
	if (m_orders.empty()) {
		queue = false;
	}
	else {
		// if the order does not require service
		if (m_orders.front().isItemFilled(getItemName()) && m_pNextStation != nullptr ) {
			*m_pNextStation += move(m_orders.front());
			m_orders.pop_front();
		}
		// if requres service
		else {
			queue = false;
		}
	}
	return queue;
}// Move the order to the next station (conditions apply)

void Workstation::setNextStation(Station& station) {
	// Convert the station object into a workstation object and assign
	m_pNextStation = (Workstation *)(&station);
}// store the parameter into the pointer

const Workstation* Workstation::getNextStation() const {
	return m_pNextStation;
}// return the next station

bool Workstation::getIfCompleted(CustomerOrder& order) {
	bool queue = true;
	if (m_orders.empty()) {
		queue = false;
	}
	else {
		if (m_orders.front().isOrderFilled()) {
			order = move(m_orders.front());
			m_orders.pop_front();
		}
		else {
			queue = false;
		}
	}
	return queue;
}// remove the order queue if it is completed

void Workstation::display(std::ostream& os) {
	os << getItemName() << " --> ";
	if (m_pNextStation == nullptr) {
		os << "END OF LINE" << endl;
	}
	else {
		os << getNextStation()->getItemName() << endl;
	}
}// ostream (display)

Workstation& Workstation::operator+=(CustomerOrder&& c) {
	m_orders.push_back(move(c));
	return *this;
}// move the parameter back on the queue




