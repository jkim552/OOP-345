//
//  Autoshop.cpp
//  ws6
//
//  Created by kim junhee on 2020-11-05.
//  Copyright © 2020 kim junhee. All rights reserved.
//
#define _CRT_SECURE_NO_WARNINGS
#include "Autoshop.h"
#include <iostream>
using namespace std;
namespace sdds{
    Autoshop &Autoshop::operator+=(Vehicle* theVehicle){
        m_vehicles.push_back(theVehicle);
        return *this;
    }

    void Autoshop::display(std::ostream& out) const{
        out << "--------------------------------" << endl;
        out << "| Cars in the autoshop!        |" << endl;
        out << "--------------------------------" << endl;
        for (auto vehicle = m_vehicles.begin(); vehicle < m_vehicles.end(); vehicle++) {
            (*vehicle)->display(out);
            out << endl;
        }
        out << "--------------------------------" << endl;
    }

    Autoshop::~Autoshop() {
        for (auto vehicle = m_vehicles.begin(); vehicle < m_vehicles.end(); vehicle++) {
            delete* vehicle;
        }
    }
}
