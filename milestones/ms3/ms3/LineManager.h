// Name: Junhee Kim
// Seneca Student ID: 159777184
// Seneca email: jkim552@myseneca.ca
// Date of completion: Nov 19 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef LineManager_h
#define LineManager_h
#include <iostream>
#include "Workstation.h"

class LineManager {
	std::vector<Workstation*> Sorted;		// Sorted AssemblyLine
	std::vector<Workstation*> AssemblyLine;	// container with all the references of the Workstation objects
	std::deque<CustomerOrder> ToBeFilled;	// A queue of customer orders to be filled
	std::deque<CustomerOrder> Completed;	// A queue of customer orders completed
	unsigned int m_cntCustomerOrder = 0;	// Starting number of customerOrder object
public:
	LineManager(const std::string&, std::vector<Workstation*>&, std::vector<CustomerOrder>&);

	bool run(std::ostream& os);
	// displays all the orders that were completed
	void displayCompletedOrders(std::ostream& os) const;

	// display all stations on the assembly line in the order they were received from the client
	void displayStations() const;

	// display all stations on the assembly line in the order they are linked.
	void displayStationsSorted() const;
};


#endif // !LineManager_h
