//
//  Car.hpp
//  ws6
//
//  Created by kim junhee on 2020-11-05.
//  Copyright © 2020 kim junhee. All rights reserved.
//

#ifndef SDDS_Car_h
#define SDDS_Car_h
#include "Vehicle.h"
#include <iostream>
namespace sdds{
    class Car : public Vehicle{
        std::string c_maker;
        std::string c_condition;
        double c_topSpeed;
    public:
        Car(std::istream&);
        std::string condition() const;
        double topSpeed() const;
        void display(std::ostream& out) const;
    };
}

#endif /* Car_hpp */
