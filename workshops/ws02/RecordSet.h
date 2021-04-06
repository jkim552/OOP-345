kf/**********************************************************
 * Name:Junhee Kim
 * Student ID:159777184
 * Date: September 29 2020
 * Seneca email: jkim552@myseneca.ca
 * Section:NHH
I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.           
***********************************************************/
#ifndef SDDS_RECORDSET_H
#define SDDS_RECORDSET_H

#include <iostream>
#include <string>
using namespace std;

namespace sdds{
    class RecordSet{
        string* strings;
        int numOfStrings;
        
    public:
        RecordSet(); 				            // no argument constructor
        RecordSet(const char*); 		        // 1 argument constructor
        RecordSet(const RecordSet&); 		    // copy constructor
        RecordSet& operator=(const RecordSet&); //copy assignment operator;
        ~RecordSet(); 				            // destructor
        size_t size(); 				            // returns number of records stored
        string getRecord(size_t); 		        // returns the record at its index

	// Part 2 modification
	RecordSet(RecordSet&&); 		            // move constructor
	RecordSet& operator=(RecordSet&&); 	        // move assignment operator
    };
}


#endif /* SDDS_RECORDSET_H */
