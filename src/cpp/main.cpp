#include <iostream>
#include <List.hpp>
#include <Cursework.hpp>


int main () {
    Cursework::decrypt("data.enc", "data.txt", "1234567890123456");
    Cursework unit("data.txt");
    std::pair p = unit.split("BBBO-00-23");
    std::cout << "FIRST GROUP:" << std::endl;
    for (int i = 0; i < p.first.length(); ++i) {
        std::cout << p.first[i].first_name << std::endl;
    }
    std::cout << std::endl << "SECOND GROUP:" << std::endl;
    for (int i = 0; i < p.second.length(); ++i) {
        std::cout << p.second[i].first_name << std::endl;
    }
    std::cout << std::endl << "MOSTLY GOOD STUDENTS:" << std::endl;
    List <student> good = unit.findGoodStudents();
    for (int i = 0; i < good.length(); ++i) {
        std::cout << good[i].first_name << std::endl;
    }
    std::cout << std::endl << "MOSTLY BAD STUDENTS:" << std::endl;
    List <student> bad = unit.findBadStudents();
    for (int i = 0; i < bad.length(); ++i) {
        std::cout << bad[i].first_name << std::endl;
    }
    Cursework::encrypt("data.txt", "data.enc", "1234567890123456");
    return 0;
}