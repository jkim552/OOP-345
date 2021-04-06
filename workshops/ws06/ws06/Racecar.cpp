#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Racecar.h"
using namespace std;
namespace sdds {
	Racecar::Racecar(std::istream& in) : Car(in) {
		char ch;
		in >> ch >> m_booster;
	}

	void Racecar::display(ostream& out) const {
		Car::display(out);
		out << "*";
	}
	double Racecar::topSpeed() const {
		return (Car::topSpeed()) * (1 + m_booster);
	}
}