#ifndef CURSEWORK_STUDENT_HPP
#define CURSEWORK_STUDENT_HPP


#include <List.hpp>
#include <string>
#include <ostream>


struct grade {
    std::string subject;
    std::string date;
    unsigned short mark;
};


class Student {
private:
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
    List <grade> grades;

public:
    Student () {};
    Student (const Student& unit);
    Student (
        const std::string number, const std::string first_name, const std::string middle_name, const std::string last_name,
        const unsigned short year, const std::string birthday, const std::string faculty, const std::string department,
        const std::string group, const std::string gender, const List <grade> grades
    );
    Student& operator= (Student& unit);
    std::string getNumber () { return this->number; }
    std::string getFirstName () { return this->first_name; }
    std::string getMiddleName () { return this->middle_name; }
    std::string getLastName () { return this->last_name; }
    unsigned short getYear () { return this->year; }
    std::string getBirthday () { return this->birthday; }
    std::string getFaculty () { return this->faculty; }
    std::string getDepartment () { return this->department; }
    std::string getGroup () { return this->group; }
    std::string getGender () { return this->gender; }
    List <grade> getGrades () { return this->grades; }
    void setNumber (std::string data) { this->number = data; }
    void setFirstName (std::string data) { this->first_name = data; }
    void setMiddleName (std::string data) { this->middle_name = data; }
    void setLastName (std::string data) { this->last_name = data; }
    void setYear (unsigned short data) { this->year = data; }
    void setBirthday (std::string data) { this->birthday = data; }
    void setFaculty (std::string data) { this->faculty = data; }
    void setDepartment (std::string data) { this->department = data; }
    void setGroup (std::string data) { this->group = data; }
    void setGender (std::string data) { this->gender = data; }
    void setGrades (List <grade> data) { this->grades = data; }
};


#endif // CURSEWORK_STUDENT_HPP