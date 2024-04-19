#include <iostream>
#include <List.hpp>


int main () {
    student stud;
    stud.birthday = "aa";
    stud.department = "aa1";
    stud.faculty = "a3a";
    stud.first_name = "aa11";
    stud.gender = "aaS";
    stud.group = "1488";
    stud.middle_name = "aaUUU";
    stud.last_name = "a88888a";
    stud.number = "4jlksdjlkdsklj";
    stud.result.date = "VMAMAMAM";
    stud.result.mark = 1;
    stud.result.subject = "KARAMBA";
    List unit;
    unit.append(stud);
    unit.append(stud);
    student stud1;
    stud1.birthday = "aa";
    stud1.department = "aa1";
    stud1.faculty = "a3a";
    stud1.first_name = "aa11";
    stud1.gender = "aaS";
    stud1.group = "1488";
    stud1.middle_name = "aaUUU";
    stud1.last_name = "a88888a";
    stud1.number = "4jlksdjlkdsklj";
    stud1.result.date = "VOVOOVOV";
    stud1.result.mark = 1;
    stud1.result.subject = "MAMBA";
    unit.append(stud1);
    unit.append(stud);
    std::cout << unit << std::endl;
    unit.remove(2);
    std::cout << unit << std::endl;
    unit.edit(0, stud1);
    List unit1(unit);
    std::cout << unit1 << std::endl;
    List unit2 = unit1;
    std::cout << unit2 << std::endl;

    return 0;
}