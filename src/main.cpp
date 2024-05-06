#include <iostream>
#include "List.hpp"
#include "Cursework.hpp"
#include "Student.hpp"


void addStudent (Cursework& unit) {
    std::string studentInfo;
    std::cout << std::endl << "Enter student info splitted by « ». Rows: 1) number" << std::endl << 
        "2) first_name" << std::endl << "3) middle_name" << std::endl << "4) last_name" << std::endl << 
        "5) year" << std::endl << "6) birthday" << std::endl << "7) faculty" << std::endl << 
        "8) department" << std::endl << "9) group" << std::endl << "10) gender" << std::endl << 
        "11) subject" << std::endl << "12) date" << std::endl << "13) mark" << std::endl << ">>> ";
    std::cin >> studentInfo;
    std::istringstream iss(studentInfo);
    std::string token;
    unsigned int count = 0;
    Student student;
    grade g;
    while (std::getline(iss, token, ' ')) {
        if (count == 0) { student.setNumber(token); }
            else if (count == 1) { student.setFirstName(token); }
            else if (count == 2) { student.setMiddleName(token); }
            else if (count == 3) { student.setLastName(token); }
            else if (count == 4) { student.setYear(std::stoi(token)); }
            else if (count == 5) { student.setBirthday(token); }
            else if (count == 6) { student.setFaculty(token); }
            else if (count == 7) { student.setDepartment(token); }
            else if (count == 8) { student.setGroup(token); }
            else if (count == 9) { student.setNumber(token); }
            else if (count == 10) { g.subject = token; }
            else if (count == 11) { g.date = token; }
            else if (count == 12) { g.mark = std::stoi(token); }
            ++count;
    }
    student.appendGrade(g);
    unit.append(student);
    std::cout << "Success!" << std::endl;
}

void deleteStudent (Cursework& unit) {
    std::string number;
    std::cout << "Enter student's number >>> ";
    std::cin >> number;
    Student student;
    student.setNumber(number);
    if (unit.isExists(student)) {
        unit.remove(unit.find(student));
        std::cout << "Success!" << std::endl;
    }
    else {
        std::cerr << "Student does not exists!" << std::endl;
    }
}

void findGoodStudents (Cursework& unit) {
    std::cout << "Good students:" << std::endl;
    List <Student> good = unit.findGoodStudents();
    for (int i = 0; i < good.length(); ++i) {
        std::cout << good[i].getFirstName() << std::endl;
    }
}

void findBadStudents (Cursework& unit) {
    std::cout << "Bad students:" << std::endl;
    List <Student> good = unit.findBadStudents();
    for (int i = 0; i < good.length(); ++i) {
        std::cout << good[i].getFirstName() << std::endl;
    }
}

void splitGroup (Cursework& unit) {
    std::string group;
    std::cout << "Enter group number >>> ";
    std::cin >> group;
    Student student;
    try {
        std::pair <List <Student>, List <Student>> p = unit.split(group);
        std::cout << "FIRST GROUP:" << std::endl;
        for (int i = 0; i < p.first.length(); ++i) {
            std::cout << p.first[i].getFirstName() << std::endl;
        }
        std::cout << std::endl << "SECOND GROUP:" << std::endl;
        for (int i = 0; i < p.second.length(); ++i) {
            std::cout << p.second[i].getFirstName() << std::endl;
        }
    }
    catch (std::logic_error) {
        std::cerr << "Group does not exist!" << std::endl;
    }
}


int main () {
    Cursework::decrypt("data.enc", "data.txt");
    Cursework unit("data.txt");

    int choice;
    std::cout << 
        "1. Add student" << std::endl << 
        "2. Delete student" << std::endl << "3. Find mostly good students" << std::endl << 
        "4. Find mostly bad students" << std::endl << "5. Split group" << std::endl << 
        "6. Show table" << std::endl << std::endl << "Enter your choice >>> ";
    std::cin >> choice;
    if (std::cin.fail()) {
        std::cerr << "You entered not num! Try again." << std::endl;
        return 1;
    }

    switch (choice) {
    case 1:
        addStudent(unit);
        break;
    case 2:
        deleteStudent(unit);
        break;
    case 3:
        findGoodStudents(unit);
        break;
    case 4:
        findBadStudents(unit);
        break;
    case 5:
        splitGroup(unit);
        break;
    case 6:
        std::cout << unit << std::endl;
        break;
    default:
        std::cerr << "You entered wrong num! Try again." << std::endl;
        return 1;
    }

    return 0;
}