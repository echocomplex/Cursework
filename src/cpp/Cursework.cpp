#include <Cursework.hpp>

bool student::operator== (student& unit) const {
    return (this->number == unit.number);
}

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
                else if (count == 12) { unit.result.mark = std::stoi(word); }
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
    return *this;
}

std::ostream& operator<< (std::ostream& os, Cursework& unit) {
    std::string toOut = "";
    for (int i = 0; i < unit.database.length(); ++i) {
        std::string row = 
            unit.database[i].number + " " + 
            unit.database[i].first_name + " " + 
            unit.database[i].middle_name + " " + 
            unit.database[i].last_name + " " + 
            std::to_string(unit.database[i].year) + " " + 
            unit.database[i].birthday + " " + 
            unit.database[i].faculty + " " + 
            unit.database[i].department + " " + 
            unit.database[i].group + " " + 
            unit.database[i].gender + " " + 
            unit.database[i].result.subject + " " + 
            unit.database[i].result.date + " " + 
            std::to_string(unit.database[i].result.mark) + "\n";
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

std::pair <List <student>, List <student>> Cursework::split (std::string group) {
    List <std::string> added;
    std::map <unsigned short, unsigned short> count;
    for (int i = 0; i < this->database.length(); ++i) {
        if (this->database[i].group == group) {
            if (count.find(this->database[i].year) == count.end()) {
                count[this->database[i].year] = 1;
                added.append(this->database[i].number);
            }
            else {
                if (!added.isExists(this->database[i].number)) {
                    ++count[this->database[i].year];
                    added.append(this->database[i].number);
                }
            }
        }
    }
    unsigned short max = count.begin()->first;
    for (std::map<unsigned short, unsigned short>::iterator it = count.begin(); it != count.end(); ++it) {
        if (it->second > count[max]) {
            max = it->first;
        }
    }
    List <student> main, other;
    List <std::string> addedFinally;
    for (int i = 0; i < this->database.length(); ++i) {
        if (this->database[i].group == group) {
            if (!addedFinally.isExists(this->database[i].number)) {
                if (this->database[i].year == max) {
                    main.append(this->database[i]);
                }
                else {
                    other.append(this->database[i]);
                }
                addedFinally.append(this->database[i].number);
            }
        }
    }
    return std::make_pair(main, other);
}

List<student> Cursework::findBadStudents () {
    std::map <std::string, bool> studentsStatuses;
    for (int i = 0; i < this->database.length(); ++i) {
        studentsStatuses[this->database[i].number] = true;
    }
    for (int i = 0; i < this->database.length(); ++i) {
        if (this->database[i].result.mark != 2) {
            studentsStatuses[this->database[i].number] = false; 
        }
    }
    List <student> badStudents;
    for (std::map<std::string, bool>::iterator it = studentsStatuses.begin(); it != studentsStatuses.end(); ++it) {
        if (it->second) {
            for (int i = 0; i < this->database.length(); ++i) {
                if (this->database[i].number == it->first) {
                    badStudents.append(this->database[i]); 
                    break;
                }  
            }
        }
    }
    return badStudents;
}

List<student> Cursework::findGoodStudents () {
    std::map <std::string, bool> studentsStatuses;
    for (int i = 0; i < this->database.length(); ++i) {
        studentsStatuses[this->database[i].number] = true;
    }
    for (int i = 0; i < this->database.length(); ++i) {
        if (this->database[i].result.mark != 5) {
            studentsStatuses[this->database[i].number] = false; 
        }
    }
    List <student> goodStudents;
    for (std::map<std::string, bool>::iterator it = studentsStatuses.begin(); it != studentsStatuses.end(); ++it) {
        if (it->second) {
            for (int i = 0; i < this->database.length(); ++i) {
                if (this->database[i].number == it->first) {
                    goodStudents.append(this->database[i]); 
                    break;
                }   
            }
        }
    }
    return goodStudents;
}

void Cursework::encrypt (std::string filenameIn, std::string filenameOut, std::string key) {
    std::string command = "openssl aes-128-cbc -salt -in " + filenameIn + " -out " + filenameOut + " -pass pass:" + key;
    std::system(command.c_str());
    if (std::remove(filenameIn.c_str()) != 0) {
        std::cerr << "CANNOT DELETE >>> " + filenameIn << std::endl;
    }
}

void Cursework::decrypt (std::string filenameIn, std::string filenameOut, std::string key) {
    std::string command = "openssl aes-128-cbc -d -in " + filenameIn + " -out " + filenameOut + " -pass pass:" + key;
    std::system(command.c_str());
    if (std::remove(filenameIn.c_str()) != 0) {
        std::cerr << "CANNOT DELETE >>> " + filenameIn << std::endl;
    }
}