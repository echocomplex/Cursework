#ifndef CURSEWORK_CURSEWORK_HPP
#define CURSEWORK_CURSEWORK_HPP


#include "List.hpp"
#include <sstream>
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <cstdio>
#include "Student.hpp"


class Cursework {
private:
    List <Student> database;
public:
    Cursework ();
    Cursework (const Cursework& unit);
    Cursework (const std::string filename);
    Cursework& operator= (const Cursework& unit);
    friend std::ostream& operator<< (std::ostream& os, Cursework& unit);
    ~Cursework ();
    void append (const Student unit);
    void remove (const unsigned int index);
    std::pair <List <Student>, List <Student>> split (std::string group);
    List <Student> findBadStudents ();
    List <Student> findGoodStudents ();
    static void encrypt (std::string filenameIn, std::string filenameOut, std::string key);
    static void decrypt (std::string filenameIn, std::string filenameOut, std::string key);
};

#endif // CURSEWORK_CURSEWORK_HPP