// Name: Junhee Kim
// Seneca Student ID: 159777184
// Seneca email: jkim552@myseneca.ca
// Date of completion: Nov 19 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef Workstation_H
#define Workstation_H
#include <iostream>
#include <vector>
#include <deque>
#include "CustomerOrder.h"
#include "Station.h"

class Workstation : public Station {
	std::deque<CustomerOrder> m_orders;						// double ended queue
	Workstation* m_pNextStation;							// a pointer to the next station
public:
	Workstation(const std::string&);						// custom constructor
	Workstation(const Workstation&) = delete;				// no copy
	Workstation& operator=(const Workstation&) = delete;	// no copy assignment
	Workstation(Workstation&&) = delete;					// no move
	Workstation& operator=(Workstation&&) = delete;			// no move operator
	void runProcess(std::ostream&);							// runs a single cycle of the assembly line
	bool moveOrder();										// Move the order to the next station (conditions apply)
	void setNextStation(Station& station);					// store the parameter into the pointer
	const Workstation* getNextStation() const;				// return the next station
	bool getIfCompleted(CustomerOrder& order);				// remove the order queue if it is completed
	void display(std::ostream&);							// ostream (display)
	Workstation& operator+=(CustomerOrder&&);				// move the parameter back on the queue
};
#endif 