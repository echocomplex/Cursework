#include <List.hpp>

List::List () {
    this->first = nullptr;
    this->last = nullptr;
}

List::List (const List& unit) {
    if (unit.first == nullptr) {
        this->first = nullptr;
        this->last = nullptr;
    }
    else {
        Node* thisNode = new Node;
        this->first = thisNode;
        Node* unitNode = unit.first;
        while (true) {
            thisNode->unit = unitNode->unit;
            thisNode->index = unitNode->index;
            if (unitNode->next == nullptr) {
                thisNode->next = nullptr;
                this->last = thisNode;
                break;
            }
            else {
                thisNode->next = new Node;
                unitNode = unitNode->next;
                thisNode = thisNode->next;
            }
        }
    }
}

List& List::operator= (const List& unit) {
    if (this != &unit) {
        while (this->first != nullptr) {
            Node* temp = this->first;
            this->first = this->first->next;
            delete temp;
        }

        if (unit.first == nullptr) {
            this->first = nullptr;
            this->last = nullptr;
        }
        else {
            Node* thisNode = new Node;
            this->first = thisNode;
            Node* unitNode = unit.first;
            while (true) {
                thisNode->unit = unitNode->unit;
                thisNode->index = unitNode->index;
                if (unitNode->next == nullptr) {
                    thisNode->next = nullptr;
                    this->last = thisNode;
                    break;
                }
                else {
                    thisNode->next = new Node;
                    unitNode = unitNode->next;
                    thisNode = thisNode->next;
                }
            }
        }
    }
    return *this;
}

std::ostream& operator<< (std::ostream& os, const List& obj) {
    std::string toOut = "";
    Node* last = obj.first;
    while (last != nullptr) {
        std::string row = 
            std::to_string(last->index) + " " 
            + last->unit.number + " " 
            + last->unit.first_name + " " 
            + last->unit.last_name + " " 
            + last->unit.middle_name + " " 
            + last->unit.birthday + " " 
            + last->unit.faculty + " "
            + last->unit.department + " "
            + last->unit.group + " " 
            + last->unit.gender + " "
            + last->unit.result.subject + " " 
            + last->unit.result.date + " " 
            + std::to_string(last->unit.result.mark) + "\n";
        toOut = toOut + row;
        last = last->next;
    }
    os << toOut;
    return os;
}

List::~List () {
    if (this->first == nullptr) {
        return;
    }
    Node* toDelete;
    while (this->first->next != nullptr) {
        toDelete = this->first;
        this->first = this->first->next;
        delete toDelete;
    }
    this->first = nullptr;
}

void List::append (const student& newData) {
    Node* newNode = new Node;
    newNode->unit = newData;
    newNode->next = nullptr;
    if (this->first == nullptr) {
        newNode->index = 0;
        this->first = newNode;
    }
    else {
        newNode->index = this->last->index + 1;
        this->last->next = newNode;
    }
    this->last = newNode;
}

void List::remove (const unsigned int index) {
    if (this->first == nullptr) {
        throw std::logic_error("List is empty");
    }
    else if (index < 0 || index > this->last->index) {
        throw std::out_of_range("Index is out of range");
    }
    else if (index == 0) {
        if (this->first->next == nullptr) {
            delete this->first;
            this->first = nullptr;
            this->last = nullptr;
        }
        else {
            Node* thisNode = this->first->next;
            delete this->first;
            this->first = thisNode;
            while (thisNode != nullptr) {
                thisNode->index = thisNode->index - 1;
                thisNode = thisNode->next;
            }
        }
    }
    else {
        Node* thisNode = this->first;
        if (this->last->index == index) {
            while (thisNode->next->next != nullptr) {
                thisNode = thisNode->next;
            }
            delete thisNode->next;
            thisNode->next = nullptr;
            this->last = thisNode;
        }
        else {
            Node* lastNode = nullptr;
            Node* toDelete = nullptr;
            bool changeIndex = false;
            while (thisNode->next != nullptr) {
                if (changeIndex) {
                    thisNode->index = thisNode->index - 1;
                    thisNode = thisNode->next;
                }
                else {
                    if (thisNode->next->index == index) {
                        lastNode = thisNode;
                        toDelete = thisNode->next;
                        changeIndex = true;
                    }
                    thisNode = thisNode->next;
                }
            }
            thisNode->index = thisNode->index - 1; 
            lastNode->next = toDelete->next;
            delete toDelete;
        }
    }
}

void List::edit (const unsigned int index, const student& unit) {
    std::cout << index << std::endl;
    if (this->first == nullptr) {
        throw std::logic_error("List is empty");
    }
    else if (index < 0 || index > this->last->index) {
        throw std::out_of_range("Index is out of range");
    }
    else {
        Node* thisNode = this->first;
        while (thisNode->index != index) {
            thisNode = thisNode->next;
        }
        thisNode->unit = unit;
    }
}

unsigned int List::length () {
    if (this->last == nullptr) {
        return 0;
    }
    else {
        return this->last->index + 1;
    }    
}

student List::getElement (const unsigned int index) {
    if (this->first == nullptr) {
        throw std::logic_error("List is empty");
    }
    else if (index < 0 || index > this->last->index) {
        throw std::out_of_range("Index is out of range");
    }
    else {
        Node* thisNode = this->first;
        while (thisNode->index != index) {
            thisNode = thisNode->next;
        }
        return thisNode->unit;
    }
}