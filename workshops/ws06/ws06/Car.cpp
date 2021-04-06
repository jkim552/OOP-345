//
//  Car.cpp
//  ws6
//
//  Created by kim junhee on 2020-11-05.
//  Copyright © 2020 kim junhee. All rights reserved.
//
#define _CRT_SECURE_NO_WARNINGS
#include "Car.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;
namespace sdds{
    Car::Car(std::istream& is){
        string make, cond, spd, vehicle;
        getline(is, vehicle, ',');
        getline(is, make, ',');
        getline(is, cond, ',');
        is >> spd;
        
        c_maker = make.substr(0, make.find(','));
        make.erase(0, make.find(',') +1 );
        c_maker.erase(c_maker.find_last_not_of(' ') + 1);
        c_maker.erase(0, c_maker.find_first_not_of(' '));
        
        c_condition = cond.substr(0, cond.find(','));
        cond.erase(0, cond.find(',') +1 );
        c_condition.erase(c_condition.find_last_not_of(' ') + 1);
        c_condition.erase(0, c_condition.find_first_not_of(' '));
        
        try{
            c_topSpeed = stod(spd);
        }
        catch (exception &invalid){
            throw "The number is invalid.";
        }

        bool valid = false;
        switch(c_condition[0]){
            case 'n':
                c_condition = "new";
                valid = true;
                break;
            case 'u':
                c_condition = "used";
                valid = true;
                break;
            case 'b':
                c_condition = "broken";
                valid = true;
                break;
        }
        if (c_condition.empty()) {
            c_condition = "new";
            valid = true;
        }
        if (!valid) {
            throw "Record is not valid";
        }
        
        
    }
    std::string Car::condition() const{
        return c_condition;
    }
    double Car::topSpeed() const{
        return c_topSpeed;
    }
    void Car::display(std::ostream& out) const{
        out << "| " << right << setw(10) << c_maker << " | ";
        out << left << setw(6) << c_condition << " | ";
        out << right << fixed << setprecision(2) << topSpeed() << " |";
    }
}
