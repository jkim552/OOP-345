//
//  Utilities.hpp
//  ws6
//
//  Created by kim junhee on 2020-11-05.
//  Copyright © 2020 kim junhee. All rights reserved.
//

#ifndef SDDS_Utilities_h
#define SDDS_Utilities_h

#include <iostream>
#include "Car.h"
#include "Vehicle.h"

namespace sdds{
    Vehicle* createInstance(std::istream& in); // Extract data from the parameter
}

#endif /* Utilities_hpp */
