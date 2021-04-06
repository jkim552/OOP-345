/**********************************************************
 * Name:Junhee Kim
 * Student ID:159777184
 * Date: September 29 2020
 * Seneca email: jkim552@myseneca.ca
 * Section:NHH
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
**********************************************************/
//
//  RecordSet.cpp
//  WorkShop2
//
//  Created by kim junhee on 2020-09-27.
//  Copyright ?2020 kim junhee. All rights reserved.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "RecordSet.h"

using namespace std;

namespace sdds {
    RecordSet::RecordSet(){
        strings = nullptr;
        numOfStrings = 0;
    }
    
    RecordSet::RecordSet(const char* file){
        RecordSet();
        ifstream fs(file);
        int length = 0;
        string temp;
        if (fs){
            // Do this to find the length of the dynamic allocated string
            while(!fs.eof()){
                // get the string with a delimeter of a single space
                getline(fs, temp, ' ');
                length++;
            }
            strings = new string[length + 1];
            fs.close();
            fs.open(file);
            string temp2;
            int index = 0;
            while (getline(fs, temp2, ' ')){
                strings[index] = temp2;
                index++;
            }
            numOfStrings = index;
        }
    }

    RecordSet::RecordSet(const RecordSet& r){
        *this = r;
    }

    RecordSet& RecordSet::operator=(const RecordSet& r){
        numOfStrings = r.numOfStrings;
        strings = new string[numOfStrings];
        for (int i = 0; i < numOfStrings; i++){
            strings[i] = r.strings[i];
        }
        
        return *this;
    }

    size_t RecordSet::size(){
        return numOfStrings;
    }

    string RecordSet::getRecord(size_t s_t){
        string output = "";
        if (strings != nullptr){
            if (s_t >= 0 && size() > s_t){
                output = strings[s_t];
            }
        }
        return output;
    }

    RecordSet::~RecordSet(){
        delete[] strings;
        strings = nullptr;
    }
    
    // Part 2 modifications ( move constructor and move assignment operator )
    RecordSet::RecordSet(RecordSet&& mv)
	: strings(nullptr)
	, numOfStrings(0)
    {
	// assign the mv object the the source object
	strings = mv.strings;
	numOfStrings = mv.numOfStrings;

	// since the mv object is no longer in use, free the memory
	// In this way, it prevents the destructor being called multiple times
	mv.strings = nullptr;
	mv.numOfStrings = 0;
    }

    RecordSet& RecordSet::operator=(RecordSet&& mv){
	// conditional statement that does nothing if it is a self-assign
	if (this != &mv){
	    // free source object
	    delete[] strings;
	    strings = mv.strings;
	    numOfStrings = mv.numOfStrings;
	    
	    // Again prevent from destructor being called multiple times
	    mv.strings = nullptr;
	    mv.numOfStrings = 0;
	}
	return *this;
    }
}
                            


