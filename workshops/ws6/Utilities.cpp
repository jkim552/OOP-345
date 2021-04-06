//
//  Utilities.cpp
//  ws6
//
//  Created by kim junhee on 2020-11-05.
//  Copyright © 2020 kim junhee. All rights reserved.
//

#include "Utilities.h"
#include <iostream>
using namespace std;

namespace sdds{
    Vehicle* createInstance(std::istream& in){
        string temp;
        in >> temp;
        Car* newCar = nullptr;
        if (temp[0] == 'c' || temp[0] == 'C'){
            newCar = new Car(in);
        }
        return newCar;
    }
}
