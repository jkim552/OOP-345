// Name: Junhee Kim
// Seneca Student ID: 159777184
// Seneca email: jkim552@myseneca.ca
// Date of completion: Nov 19 2020
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <iostream>
#include "LineManager.h"
#include <fstream>
#include <string>
using namespace std;


LineManager::LineManager(const std::string& file, std::vector<Workstation*>& w, std::vector<CustomerOrder>& c){
	fstream fs(file);
	Utilities util;
	size_t pos = 0;
	bool more = true;
	string line, item, next_item;
	m_cntCustomerOrder = c.size();
	// Template re-used from ms3.cpp file
	if (!fs){
		throw string("Unable to open [") + file + "] file.";
	}
	while (!fs.eof())
	{
		std::getline(fs, line);
		item = util.extractToken(line, pos, more);
		for (size_t i = 0; i < w.size(); i++) {
			if (item == w[i]->getItemName()) {
				if (more) {
					next_item = util.extractToken(line, pos, more);
					for (size_t j = 0; j < w.size(); j++) {
						if (next_item == w[j]->getItemName()) {
							w[i]->setNextStation(*w[j]);
						}
					}
				}
				// Vector for sorted station
				Sorted.push_back(w[i]);
			}
			
		}
	}
	// Move all the CustomerOrder objects onto the back of the ToBeFilled queue
	ToBeFilled = deque<CustomerOrder>(m_cntCustomerOrder);
	for (size_t i = 0; i < m_cntCustomerOrder; i++) {
		ToBeFilled[i] = move(c[i]);
	}
	// Copy all the Workstation objects into the AssemblyLine container
	AssemblyLine = w;
}

bool LineManager::run(ostream& os) {
	static size_t called = 0;
	os << "Line Manager Iteration: " << ++called << endl;

	if (!ToBeFilled.empty()) {
		// move the one at the front of the queue onto 
		//the starting point of the AssemblyLine
		*Sorted.at(0) += move(ToBeFilled.front());
		ToBeFilled.pop_front();
	}

	// Loop through all stations on the assembly line 
	// and run one cycle of the station's process
	for (size_t i = 0; i < AssemblyLine.size(); i++){
		AssemblyLine[i]->runProcess(os);
	}

	CustomerOrder c;
	// Loop through all stations on the assembly lineand move the CustomerOrder objects down the line.
	for (size_t i = 0; i < AssemblyLine.size(); i++) {
		AssemblyLine[i]->moveOrder();
		if (AssemblyLine[i]->getIfCompleted(c)) {
			// completed orders should be moved into the Completed queue.
			Completed.push_back(move(c));
		}
	}
	// return true if all customer orders have been filled, otherwise returns false.
	return Completed.size() == m_cntCustomerOrder;
}

	
// displays all the orders that were completed
void LineManager::displayCompletedOrders(std::ostream& os) const {
	for (size_t i = 0; i < Completed.size(); i++) {
		Completed[i].display(os);
	}
}

// display all stations on the assembly line in the order they were received from the client
void LineManager::displayStations() const {
	for (size_t i = 0; i < AssemblyLine.size(); i++) {
		AssemblyLine[i]->display(cout);
	}
}

// display all stations on the assembly line in the order they are linked.
void LineManager::displayStationsSorted() const {
	for (size_t i = 0; i < Sorted.size(); i++) {
		Sorted[i]->display(cout);
	}
}

