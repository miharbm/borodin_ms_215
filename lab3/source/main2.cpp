#include <iostream>
#include <ctime>
#include "./set/set.h"
#include "./set/set.tpp"
#include "extrafunctions/extrafunctions.h"
#include "./person/person.h"

using namespace std;

const char *MENU_MAIN[] = {"Type of sets",
                           "Quit",
                           "Integer",
                           "Float",
                           "String",
                           "Person",
};
const int MENU_MAIN_SIZE = sizeof(MENU_MAIN) / sizeof(MENU_MAIN[0]);


int dialog(const char **msgs, int n) {
    int choice;
    char temp;
    do {
        for (int i = 0; i < n; ++i)
            std::cout << i <<". "<< msgs[i] << std::endl;
        std::cout << "> " << std::endl;


        do {
            std::cin >> temp;

        } while (temp == '\n');

        choice = temp - '0';
        while (getchar() != '\n');
        if (choice < 0 || choice >= n)
            printf("You're wrong. Try again!\n");

//        delay(500);
        printf("\033[0d\033[2J");

    } while (choice < 0 || choice >= n);

    return choice;
}

int main() {
    srand(time(NULL));

    int mode;

    auto *setInt1 = new Set<int>;
    auto *setInt2 = new Set<int>;
    int nInt;

    auto *setFloat1 = new Set<float>;
    auto *setFloat2 = new Set<float>;
    float nFloat;

    auto *setString1 = new Set<string>;
    auto *setString2 = new Set<string>;
    string nString;

    auto *setPerson1 = new Set<Person>;
    auto *setPerson2 = new Set<Person>;
    Person nPerson;

    int menu;
    do {

        menu = dialog(MENU_MAIN, MENU_MAIN_SIZE);

        switch (menu) {
            case 0: //Отмена
                break;
            case 1: {//integer

            }
            case 2: {//double

            }
            case 3: {//string

            }
            case 4: {//person

            }

            default:
                printf("***Error, please try again***\n");
                break;
        }
    } while (menu != 0);
}