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
    stud.year = 2024;
    stud.result.subject = "KARAMBA";
    List <student> unit;
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
    stud1.year = 2024;
    stud1.result.subject = "MAMBA";
    unit.append(stud1);
    unit.append(stud);
    for (int i = 0; i < unit.length(); i++) {
        std::cout << unit[i].number << " " << unit[i].first_name << " " << unit[i].middle_name << " " << unit[i].last_name << " " << unit[i].year << " " << unit[i].birthday << " " << unit[i].faculty << " " << unit[i].department << " " << unit[i].group << " " << unit[i].gender << " " << unit[i].result.subject << " " << unit[i].result.date << " " << unit[i].result.mark << std::endl;
    }
    std::cout << std::endl;
    unit.remove(2);
    for (int i = 0; i < unit.length(); i++) {
        std::cout << unit[i].number << " " << unit[i].first_name << " " << unit[i].middle_name << " " << unit[i].last_name << " " << unit[i].year << " " << unit[i].birthday << " " << unit[i].faculty << " " << unit[i].department << " " << unit[i].group << " " << unit[i].gender << " " << unit[i].result.subject << " " << unit[i].result.date << " " << unit[i].result.mark << std::endl;
    }
    std::cout << std::endl;
    unit[0] = stud1;
    List <student> unit1(unit);
    for (int i = 0; i < unit1.length(); i++) {
        std::cout << unit1[i].number << " " << unit1[i].first_name << " " << unit1[i].middle_name << " " << unit1[i].last_name << " " << unit1[i].year << " " << unit1[i].birthday << " " << unit1[i].faculty << " " << unit1[i].department << " " << unit1[i].group << " " << unit1[i].gender << " " << unit1[i].result.subject << " " << unit1[i].result.date << " " << unit1[i].result.mark << std::endl;
    }
    std::cout << std::endl;
    List <student> unit2 = unit1;
    unit2.append(unit2[0]);
    unit2.remove(0);
    unit2[0].gender = "MAMUIBAL";
    for (int i = 0; i < unit2.length(); i++) {
        std::cout << i << " " << unit2[i].number << " " << unit2[i].first_name << " " << unit2[i].middle_name << " " << unit2[i].last_name << " " << unit2[i].year << " " << unit2[i].birthday << " " << unit2[i].faculty << " " << unit2[i].department << " " << unit2[i].group << " " << unit2[i].gender << " " << unit2[i].result.subject << " " << unit2[i].result.date << " " << unit2[i].result.mark << std::endl;
    }
    std::cout << std::endl;
    std::cout << unit2.length() << std::endl;

    std::cout << unit2[1].first_name << std::endl;

    return 0;
}