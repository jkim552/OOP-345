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
using namespace std;
namespace sdds{
    Car::Car(std::istream& is){
        string temp;
        getline(is, temp, '\n');
        
        c_maker = temp.substr(0, temp.find(','));
        temp.erase(0, temp.find(',') +1 );
        c_maker.erase(c_maker.find_last_not_of(' ') + 1);
        c_maker.erase(0, c_maker.find_first_not_of(' '));
        
        c_condition = temp.substr(0, temp.find(','));
        temp.erase(0, temp.find(',') +1 );
        c_condition.erase(c_condition.find_last_not_of(' ') + 1);
        c_condition.erase(0, c_condition.find_first_not_of(' '));
        
        try{
            c_topSpeed = stod(temp.substr(0, temp.find(',')));
            temp.erase(0, temp.find(',') +1 );
        }
        catch (exception &invalid){
            throw "The number is invalid.";
        }
        
        
        if (c_maker != "c" && c_maker != "C"){
            c_maker = "";
            c_condition = "";
            c_topSpeed = 0;
        }
        
        switch(c_condition[0]){
            case 'n':
                c_condition = "new";
                break;
            case 'u':
                c_condition = "used";
                break;
            case 'b':
                c_condition = "broken";
                break;
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
        out << right << fixed << setprecision(2) << c_topSpeed << " |" << endl;
    }
}
