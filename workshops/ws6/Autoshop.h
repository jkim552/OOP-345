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
#include "Vehicle.h"

namespace sdds{
    class Autoshop{
        std::vector<Vehicle*> m_vehicles;
    public:
        Autoshop& operator+=(Vehicle* theVehicle);
        void display(std::ostream out) const;
    };
}

#endif /* Autoshop_hpp */
