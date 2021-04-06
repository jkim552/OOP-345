/**********************************************************
 * Name:Junhee Kim
 * Student ID:159777184
 * Date: September 29 2020
 * Seneca email: jkim552@myseneca.ca
 * Section:NHH
I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.           
**********************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <chrono>
#include <iomanip>
#include "TimedEvents.h"

using namespace std;

namespace sdds{
    TimedEvents::TimedEvents() {
        current = 0;
    }

    void TimedEvents::startClock() {
        start = chrono::steady_clock::now();
    }
    
    void TimedEvents::stopClock() {
        end = chrono::steady_clock::now();
    }

    void TimedEvents::recordEvent(const char* event){
        if (MAX > current){
            eventRecord[current].eventName = event;
            eventRecord[current].unitsOftime = "nanoseconds";
            eventRecord[current].eventDuration = chrono::duration_cast<::chrono::nanoseconds>(end - start);
            auto duration = eventRecord[current].eventDuration;
            current++;
        }
    }

    ostream& operator<<(ostream& os, const TimedEvents& ev) {
        os << "--------------------------\n";
        os << "Execution Times:\n";
        os << "--------------------------\n";
        for (auto i = 0; i < ev.current; i++){
            os << setw(20) << left << ev.eventRecord[i].eventName;
            os << " " << setw(12) << right << ev.eventRecord[i].eventDuration.count();
            os << " " << ev.eventRecord[i].unitsOftime << "\n";
        }
        os << "--------------------------\n";
        return os;
    }
}
