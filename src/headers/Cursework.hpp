#ifndef CURSEWORK_CURSEWORK_HPP
#define CURSEWORK_CURSEWORK_HPP


#include <List.hpp>
#include <sstream>
#include <iostream>
#include <string>
#include <fstream>


class Cursework {
private:
    List database;

public:
    Cursework ();
    Cursework (const Cursework& unit);
    Cursework (const std::string filename);
    Cursework& operator= (const Cursework& unit);
    friend std::ostream& operator<< (std::ostream& os, const Cursework& unit);
    ~Cursework ();
    void append (student unit);
    void remove (const unsigned int index);
    
};

#endif // CURSEWORK_CURSEWORK_HPP