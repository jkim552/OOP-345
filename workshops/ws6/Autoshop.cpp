//
//  Autoshop.cpp
//  ws6
//
//  Created by kim junhee on 2020-11-05.
//  Copyright © 2020 kim junhee. All rights reserved.
//

#include "Autoshop.h"
#include <iostream>
using namespace std;
namespace sdds{
    Autoshop &Autoshop::operator+=(Vehicle* theVehicle){
        m_vehicles.push_back(theVehicle);
        return *this;
    }

    void Autoshop::display(std::ostream out) const{
        out << "--------------------------------" << endl;
        out << "| Cars in the autoshop!        |" << endl;
        out << "--------------------------------" << endl;
        for (auto m_vehicle : m_vehicles){
            m_vehicle->display(out);
        }
        out << "--------------------------------" << endl;
    }
}
