#ifndef CURSEWORK_STUDENT_HPP
#define CURSEWORK_STUDENT_HPP


#include <List.hpp>
#include <string>
#include <ostream>
#include <type_traits>


struct grade {
    std::string subject;
    std::string date;
    unsigned short mark;
};


enum studentField {
    NUMBER,
    FIRST_NAME,
    MIDDLE_NAME,
    LAST_NAME,
    YEAR,
    BIRTHDAY,
    FACULTY,
    DEPARTMENT,
    GROUP,
    GENDER,
    GRADE
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
    Student (const Student& unit);
    Student (
        const std::string number, const std::string first_name, const std::string middle_name, const std::string last_name,
        const unsigned short year, const std::string birthday, const std::string faculty, const std::string department,
        const std::string group, const std::string gender, const List <grade> grades
    );
    Student& operator= (Student& unit);
    auto get (studentField field);
    void set (studentField field, auto newData);
};


#endif // CURSEWORK_STUDENT_HPP