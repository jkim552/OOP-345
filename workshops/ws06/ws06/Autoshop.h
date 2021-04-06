//
//  Autoshop.hpp
//  ws6
//
//  Created by kim junhee on 2020-11-05.
//  Copyright © 2020 kim junhee. All rights reserved.
//

#ifndef SDDS_Autoshop_h
#define SDDS_Autoshop_h
#include <iostream>
#include <vector>
#include <functional>
#include <list>
#include "Vehicle.h"

namespace sdds{
    class Autoshop{
        std::vector<Vehicle*> m_vehicles;
    public:
        Autoshop& operator+=(Vehicle* theVehicle);    
        void display(std::ostream& out) const;
        ~Autoshop();
        template <class T>
        void select(T test, std::list<const Vehicle*>& vehicles) {
            for (auto vehicle = m_vehicles.begin(); vehicle < m_vehicles.end(); vehicle++) {
                if (test(*vehicle)) {
                    vehicles.push_back(*vehicle);
                }
            }
        }
    };
}

#endif /* Autoshop_hpp */
