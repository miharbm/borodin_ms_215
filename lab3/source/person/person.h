#ifndef LAB3_PERSON_H
#define LAB3_PERSON_H


#include<iostream>
#include<string>

class Person {
private:
    int ID;
    std::string name;
    std::string surname;
public:
    Person(int ID = 0, std::string name = "", std::string surname = "") {
        this->ID = ID;
        this->name = name;
        this->surname = surname;
    }
    Person(const Person& p) {
        ID = p.ID;
        name = p.name;
        surname = p.surname;
    }

    void Set(int ID = 0, std::string name = "", std::string surname = "") {
        this->ID = ID;
        this->name = name;
        this->surname = surname;
    }
    int GetID() {
        return ID;
    }
    std::string GetName() {
        return name;
    }
    std::string GetSurname() {
        return surname;
    }
    bool operator!=(const Person &p) {
        if (this->ID == p.ID)
            return false;
        return true;
    }
    bool operator==(const Person &p) {
        if (this->ID == p.ID)
            return true;
        return false;
    }
    bool operator<(const Person &p) {
        if (this->ID < p.ID)
            return true;
        return false;
    }
    bool operator>(const Person &p) {
        if (this->ID > p.ID)
            return true;
        return false;
    }

    friend std::ostream& operator<< (std::ostream &out, const Person &p) {
        out << "( ID : " << p.ID << ", name : " << p.name << ", surname : " << p.surname << " )";
        return out;
    }
};

Person randomPerson() {
    int max = 10e8;
    int ID = rand() % max;
    int len = rand() % 7 + 1;
    std::string name = "";
    for (int i = 0; i < len; ++i) {
        char ch = (48 + rand() % (122 - 48 + 1));
        std::string current(1, ch);
        name += ch;
    }
    std::string surname = "";
    for (int i = 0; i < len; ++i) {
        char ch = (48 + rand() % (122 - 48 + 1));
        std::string current(1, ch);
        surname += ch;
    }
    Person p(ID, name, surname);
    return p;
}
std::string to_string(Person &p) {
    return "( ID : " + std::to_string(p.GetID()) + ", name : " + p.GetName() + ", surname : " + p.GetSurname() + " )";
}

#endif //LAB3_PERSON_H
