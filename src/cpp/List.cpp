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
            last->unit.number + " " 
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

void List::remove (const int index) {
    if (this->first == nullptr) {
        throw std::logic_error("List is empty");
    }
    else if (index < 0 || index > this->last->index) {
        throw std::out_of_range("Index is out of range");
    }
    else {
        Node* thisNode = this->first;
        while (thisNode->next != nullptr) {
            thisNode = thisNode->next;
        }
        if (thisNode->next->next == nullptr) {
            delete thisNode->next;
            thisNode->next = nullptr;
            this->last = thisNode;
        }
        else {
            Node* Next= thisNode->next->next;
            delete thisNode->next;
            thisNode->next = Next;
        }
    }
}

void List::edit (const int index, const student& unit) {
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
