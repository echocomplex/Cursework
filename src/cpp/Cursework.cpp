#include <Cursework.hpp>

Cursework::Cursework () {}

Cursework::Cursework (const Cursework& unit) {
    this->database = unit.database;
}

Cursework::Cursework (const std::string filename) {
    std::ifstream file (filename, std::ios::binary);
    if (file.is_open()) {
        std::string row;
        while (std::getline(file, row)) {
            std::istringstream iss(row);
            std::string word;
            student unit;
            int count = 0;
            while (iss >> word) {
                if (count == 0) { unit.number = word; }
                else if (count == 1) { unit.first_name = word; }
                else if (count == 2) { unit.middle_name = word; }
                else if (count == 3) { unit.last_name = word; }
                else if (count == 4) { unit.year = std::stoi(word); }
                else if (count == 5) { unit.birthday = word; }
                else if (count == 6) { unit.faculty = word; }
                else if (count == 7) { unit.department = word; }
                else if (count == 8) { unit.group = word; }
                else if (count == 9) { unit.gender = word; }
                else if (count == 10) { unit.result.subject = word; }
                else if (count == 11) { unit.result.date = word; }
                else if (count == 12) { unit.first_name = word; }
                else if (count == 13) { unit.result.mark = std::stoi(word); }
                count++;
            }
            this->append(unit);
        }
    }
    else {
        throw std::runtime_error("File does not exist");
    }
    file.close();
}

Cursework& Cursework::operator= (const Cursework& unit) {
    this->database = unit.database;
}

std::ostream& operator<< (std::ostream& os, const Cursework& unit) {
    std::string toOut = "";
    for (int i = 0; i < unit.database.length(); i++) {
        std::string row = 
            unit.database[i].number + " " + 
            unit.database[i].first_name + " " + 
            unit.database[i].middle_name + " " + 
            unit.database[i].last_name + " " + 
            unit.database[i].year + " " + 
            unit.database[i].birthday + " " + 
            unit.database[i].faculty + " " + 
            unit.database[i].department + " " + 
            unit.database[i].group + " " + 
            unit.database[i].gender + " " + 
            unit.database[i].result.subject + " " + 
            unit.database[i].result.date + " " + 
            unit.database[i].result.mark + "\n";
    }
    os << toOut;
    return os;
}

Cursework::~Cursework () {}

void Cursework::append (const student unit) {
    this->database.append(unit);
}

void Cursework::remove (const unsigned int index) {
    this->database.remove(index);
} 

std::pair <std::vector <student>, std::vector <student>> split (std::string group) {
    
}

std::pair <student, student> findUniqueStudents () {

}