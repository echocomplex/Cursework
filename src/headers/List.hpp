#ifndef CURSEWORK_LIST_HPP
#define CURSEWORK_LIST_HPP


#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>


struct grade {
    std::string subject;
    std::string date;
    int mark;
};


struct student {
    std::string number;
    std::string first_name;
    std::string middle_name;
    std::string last_name;
    std::string birthday;
    std::string faculty;
    std::string department;
    std::string group;
    std::string gender;
    grade result;
};


struct Node {
    student unit;
    int index;
    Node* next;
};

class List {
private:
    Node* first;
    Node* last;

public:
    List ();
    List (const List& unit);
    List& operator= (const List& unit);
    friend std::ostream& operator<< (std::ostream& os, const List& obj);
    ~List ();
    void append (const student& newData);
    void remove (const int index);
    void edit (const int index, const student& unit);
};




#endif // CURSEWORK_LIST_HPP