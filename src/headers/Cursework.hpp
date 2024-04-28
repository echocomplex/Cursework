#ifndef CURSEWORK_CURSEWORK_HPP
#define CURSEWORK_CURSEWORK_HPP


#include <List.hpp>
#include <sstream>
#include <iostream>
#include <string>
#include <fstream>


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
};


class Cursework {
private:
    List <student> database;
public:
    Cursework ();
    Cursework (const Cursework& unit);
    Cursework (const std::string filename);
    Cursework& operator= (const Cursework& unit);
    friend std::ostream& operator<< (std::ostream& os, const Cursework& unit);
    ~Cursework ();
    void append (const student unit);
    void remove (const unsigned int index);
    std::pair <List <student>, List <student>> split ();
    std::pair <List <student>, List <student>> findUniqueStudents ();
};

#endif // CURSEWORK_CURSEWORK_HPP