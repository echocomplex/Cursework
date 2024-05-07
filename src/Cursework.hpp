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
#include <ctime>


class Cursework {
private:
    List <Student> database;
public:
    Cursework () {}
    Cursework (const Cursework& unit);
    Cursework (const std::string filename);
    Cursework& operator= (const Cursework& unit);
    friend std::ostream& operator<< (std::ostream& os, Cursework& unit);
    ~Cursework () {}
    void toFile (const std::string filename);
    void append (const Student unit);
    void remove (const unsigned int index);
    unsigned int find (const Student unit);
    Student get (const unsigned int index);
    bool isExists (const Student unit);
    std::pair <List <Student>, List <Student>> split (std::string group);
    List <Student> findBadStudents ();
    List <Student> findGoodStudents ();
    static void encrypt (const std::string filenameIn, const std::string filenameOut);
    static void decrypt (const std::string filenameIn, const std::string filenameOut);
};

#endif // CURSEWORK_CURSEWORK_HPP