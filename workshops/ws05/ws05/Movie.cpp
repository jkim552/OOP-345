#define _CRT_SECURE_NO_WARNINGS
#include "Movie.h"
#include <string>
#include <cstring>
#include <iostream>
#include <iomanip>

using namespace std;
namespace sdds {
    Movie::Movie() {  
        m_title = ""; 
        m_year = 0;
        m_description = "";
    }   // Default constructor

    const std::string& Movie::title() const {
        return m_title;
    }   // Returns title

    Movie::Movie(const std::string& strMovie) {
        string temp = strMovie;

        m_title = temp.substr(0, temp.find(','));
        temp.erase(0, temp.find(',') + 1);
        m_title.erase(m_title.find_last_not_of(' ') + 1);
        m_title.erase(0, m_title.find_first_not_of(' '));

        m_year = stoi(temp.substr(0, temp.find(',')));
        temp.erase(0, temp.find(',') + 1);

        m_description = temp.substr(0, temp.find('.') + 1);
        temp.erase(0, temp.find('.') + 1);
        m_description.erase(m_description.find_last_not_of(' ') + 1);
        m_description.erase(0, m_description.find_first_not_of(' '));
    }   // Extract information from the string

    std::ostream& operator<<(std::ostream& os, const Movie& m) {
        os << setw(40) << m.m_title << " | ";
        os << setw(4) << m.m_year << " | ";
        os << m.m_description << endl;
        return os;
    }
}
