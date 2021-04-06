/**********************************************************
 * Name:Junhee Kim
 * Student ID:159777184
 * Date: November 23 2020
 * Seneca email:jkim552@myseneca.ca
 * Section:NHH
 I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 **********************************************************/
#ifndef SDDS_EVENT_H
#define SDDS_EVENT_H
#include <iostream>

extern unsigned int g_sysClock;
namespace sdds {
	class Event {
		char* description;							// C-style null-terminated string (up to 128 char)
		unsigned int time;							// Integer between 0 and 86400
	
	public:
		Event();									// Default Constructor
		void setEmpty();									// Resets to an empty state
		void display();								// A query that displays the content of an instance
		void setDescription(const char* desc);		// Sets the event of the current instance to the given parameter
		~Event();									// Destructor
		Event(const Event& cp);						// Copy
		Event& operator=(const Event& assign);		// assign
	};
}
#endif
