//
//  Utilities.cpp
//  ws6
//
//  Created by kim junhee on 2020-11-05.
//  Copyright © 2020 kim junhee. All rights reserved.
//

#include "Utilities.h"
#include "Racecar.h"
#include <iostream>
#include <cstring>
#include <sstream>
using namespace std;

namespace sdds{
    Vehicle* createInstance(std::istream& in){
        stringstream ss;
        string temp;
        getline(in, temp, '\n');
        ss << temp;
        
        temp = temp.substr(0, temp.find(','));
        temp.erase(temp.find_last_not_of(' ') + 1);
        temp.erase(0, temp.find_first_not_of(' '));
        
        Car* newCar = nullptr;
        Racecar* newrc = nullptr;
        if (temp.empty()) {
            return nullptr;
        }

        if (temp[0] != 'c' && temp[0] != 'C' && temp[0] != 'r' && temp[0] != 'R') {
            throw temp[0];
        }
        if (temp[0] == 'c' || temp[0] == 'C'){
            newCar = new Car(ss);
            return newCar;
        }
        else if (temp[0] == 'r' || temp[0] == 'R') {
            newrc = new Racecar(ss);
            return newrc;
        }
    }
}
