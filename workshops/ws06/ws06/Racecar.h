#ifndef SDDS_Racecar_H
#define SDDS_Racecar_h
#include <iostream>
#include "Car.h"

namespace sdds {
	class Racecar : public Car{
		double m_booster;
	public:
		Racecar(std::istream& in);				// Extracts from the stream
		void display(std::ostream& out) const;	// Display
		double topSpeed() const;				// Return top speed including booster effect
	};
}
#endif // !SDDS_Racecar_H
