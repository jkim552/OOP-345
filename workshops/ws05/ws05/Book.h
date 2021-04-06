//
//  Book.hpp
//  ws5
//
//  Created by kim junhee on 2020-10-20.
//  Copyright © 2020 kim junhee. All rights reserved.
//

#ifndef SDDS_Book_h
#define SDDS_Book_h

#include <iostream>
#include <string>
#include "SpellChecker.h"
namespace sdds{
    class Book{
        std::string p_author;
        std::string p_title;
        std::string p_country;
        size_t p_year = 0;
        double p_price;
        std::string p_description;
    public:
        Book();                             // Default constructor
        const std::string& title() const;   // Returns title
        const std::string& country() const; // Retruns country
        const size_t& year() const;         // Returns year
        double& price();                    // Returns price by reference
        Book(const std::string& strBook);   // Extract information from the string
        friend std::ostream& operator<<(std::ostream& os, const Book& b);
        void priceChange(double value);
        
        template<class T>
        void fixSpelling(T spellChecker) {
            spellChecker(p_description);
        }
    };
}

#endif /* Book_hpp */
