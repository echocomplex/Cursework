#ifndef CURSEWORK_CURSEWORK_HPP
#define CURSEWORK_CURSEWORK_HPP


#include <List.hpp>
#include <sstream>
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <cstdio>


struct grade {
    std::string subject;
    std::string date;
    short mark;
};


struct student {
    std::string number;
    std::string first_name;
    std::string middle_name;
    std::string last_name;
    unsigned short year;
    std::string birthday;
    std::string faculty;
    std::string department;
    std::string group;
    std::string gender;
    grade result;
    bool operator== (student& unit) const;
};


class Cursework {
private:
    List <student> database;
public:
    Cursework ();
    Cursework (const Cursework& unit);
    Cursework (const std::string filename);
    Cursework& operator= (const Cursework& unit);
    friend std::ostream& operator<< (std::ostream& os, Cursework& unit);
    ~Cursework ();
    void append (const student unit);
    void remove (const unsigned int index);
    std::pair <List <student>, List <student>> split (std::string group);
    List <student> findBadStudents ();
    List <student> findGoodStudents ();
    static void encrypt (std::string filenameIn, std::string filenameOut, std::string key);
    static void decrypt (std::string filenameIn, std::string filenameOut, std::string key);
};

#endif // CURSEWORK_CURSEWORK_HPP