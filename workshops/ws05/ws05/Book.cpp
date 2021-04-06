//
//  Book.cpp
//  ws5
//
//  Created by kim junhee on 2020-10-20.
//  Copyright © 2020 kim junhee. All rights reserved.
//
#define _CRT_SECURE_NO_WARNINGS
#include "Book.h"
#include <string>
#include <cstring>
#include <iostream>
#include <iomanip>

using namespace std;
namespace sdds{
    Book::Book(){
        p_author = "";
        p_title = "";
        p_country = "";
        p_year = 0;
        p_price = 0;
        p_description = "";
    }   // Default constructor

    const std::string& Book::title() const{
        return p_title;
    }   // Returns title

    const std::string& Book::country() const{
        return p_country;
    }   // Retruns country

    const size_t& Book::year() const{
        return p_year;
    }   // Returns year

    double& Book::price(){
        return p_price;
    }   // Returns price by reference
    Book::Book(const std::string& strBook){
        string temp = strBook;
        p_author = temp.substr(0, temp.find(','));
        temp.erase(0, temp.find(',') +1 );
        p_author.erase(p_author.find_last_not_of(' ') + 1);
        p_author.erase(0, p_author.find_first_not_of(' '));
        
        p_title = temp.substr(0, temp.find(','));
        temp.erase(0, temp.find(',') +1 );
        p_title.erase(p_title.find_last_not_of(' ') + 1);
        p_title.erase(0, p_title.find_first_not_of(' '));
        
        p_country = temp.substr(0, temp.find(','));
        temp.erase(0, temp.find(',') +1 );
        p_country.erase(p_country.find_last_not_of(' ') + 1);
        p_country.erase(0, p_country.find_first_not_of(' '));
        
        p_price = stod(temp.substr(0, temp.find(',')));
        temp.erase(0, temp.find(',') + 1);

        p_year = stoi(temp.substr(0, temp.find(',')));
        temp.erase(0, temp.find(',') + 1);
              
        p_description = temp.substr(0, temp.find('.') + 1);
        temp.erase(0, temp.find('.') +1 );
        p_description.erase(p_description.find_last_not_of(' ') + 1);
        p_description.erase(0, p_description.find_first_not_of(' '));
    }   // Extract information from the string
    
    std::ostream& operator<<(std::ostream& os, const Book& b){
        os << setw(20) << b.p_author << " | ";
        os << setw(22) << b.p_title << " | ";
        os << setw(5) << b.p_country << " | ";
        os << setw(4) << b.p_year << " | ";
        os << setw(6) << fixed << setprecision(2) << b.p_price << " | ";
        os << b.p_description << endl;
        return os;
    }

    void Book::priceChange(double value) {
        p_price = value;
    }
}
