/**********************************************************
 * Name:Junhee Kim
 * Student ID:159777184
 * Date: September 29 2020
 * Seneca email: jkim552@myseneca.ca
 * Section:NHH
I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.           
**********************************************************/
#ifndef SDDS_TIMEDEVENTS_H
#define SDDS_TIMEDEVENTS_H

#include <iostream>
#include <chrono>
using namespace std;

namespace sdds{
    const int MAX = 7; 						// Max record objects of 7

    class TimedEvents{
        int current{}; 						// Number of records currently stored
        chrono::steady_clock::time_point start;			// Start time for current event
        chrono::steady_clock::time_point end;			// End time for current event
        
        // Array of records of annoymous structure type
        struct {
            string eventName{};					// Name of the event
            string unitsOftime{};				// predefind units of time
            chrono::steady_clock::duration eventDuration{};	// Duration of recorded event
        }eventRecord[MAX];					// Max record objects at 7
        
    public:
        TimedEvents();      					// Constructor
        void startClock();  					// starts the timer for an event
        void stopClock();   					// stops the timer for an event
        void recordEvent(const char*);				// updates the time-record in the array
        
	friend ostream& operator<<(ostream& os, const TimedEvents& ev);
        
    };
}

#endif /* SDDS_TIMEDEVENTS_H */
