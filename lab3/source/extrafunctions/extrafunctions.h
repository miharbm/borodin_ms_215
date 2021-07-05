#ifndef LAB3_EXTRAFUNCTIONS_H
#define LAB3_EXTRAFUNCTIONS_H
#include<iostream>
#include<string>
#include "../person/person.h"

using namespace std;

int INT_INF = 10e8;
float FLOAT_INF = 10e8;

int readInt(int &a) {
    int mode = 0;
    cin >> a;
    if (!cin) {
        cin.clear();
        cout << "Incorrect input. Please, enter one integer number.\n";
        mode = -1;
    }
    if (mode == 0) while (getchar() != '\n') {};
    return mode;
}

int readFloat(float &a) {
    int mode = 0;
    cin >> a;
    if (!cin) {
        cin.clear();
        cout << "Incorrect input. Please, enter one float number.\n";
        mode = -1;
    }
    if (mode == 0) while (getchar() != '\n') {};
    return mode;
}

int readPerson(Person &a) {
    int mode = 0;
    int ID;
    string name;
    string surname;

    cout << "Input ID (ine positive integer number): ";
    cin >> ID;
    if (!cin) {
        cin.clear();
        cout << "Incorrect input. Please, enter one integer number.\n";
        mode = -1;
        return mode;
    }
    cin.clear();

    cout << "Input name: ";
    cin >> name;
    if (!cin) {
        cin.clear();
        cout << "Incorrect input. Please, enter one integer number.\n";
        mode = -1;
        return mode;
    }
    cin.clear();

    cout << "Input surname: ";
    cin >> surname;
    if (!cin) {
        cin.clear();
        cout << "Incorrect input. Please, enter one integer number.\n";
        mode = -1;
        return mode;
    }
    cin.clear();
    a.Set(ID, name, surname);
    return mode;
}

int randomInt() {
    int max = 10e8;
    return rand() % max;
}

float randomFloat() {
    int max = 10e5;
    int del = rand() % max;
    while (del == 0) del = rand() % 7;
    return (rand() % max) * 1.0 / del;
}

string to_string(const string &a) {
    return a;
}

string randomString() {
    int len = rand() % 7 + 1;
    string s = "";
    for (int i = 0; i < len; ++i) {
        char ch = (48 + rand() % (122 - 48 + 1));
        string current(1, ch);
        s += ch;
    }
    return s;
}

int readString(string &s) {
    int mode = 0;
    cout << "Input string (end by enter)): ";
    getline(cin, s);
    if (!cin) {
        mode = -1;
        cout << "Something is wrong.\n";
    }
    return mode;
}

#endif //LAB3_EXTRAFUNCTIONS_H
