#include <iostream>
#include <ctime>
#include "matrix/rect_matrix.h"




int dialog(const char *msgs[], int n);

void delay(int milli_seconds);

const char * MENU_MAIN[] = {"0. Отмена",
                            "1. Целые числа",
                            "2. Действительные числа"};
const int MENU_MAIN_SIZE = sizeof(MENU_MAIN) / sizeof(MENU_MAIN[0]);



int main() {

    int menu, type_ar = 0;

    do {

        menu = dialog(MENU_MAIN, MENU_MAIN_SIZE);

        switch (menu) {
            case 0:
                break;

            case 1: {

            }
                break;

            case 2: {

            }
                break;

            default:
                printf("***Error, please try again***\n");
                break;
        }
    } while (menu != 0);


    RectMatrix<int> matrix1;
    //    matrix1.
    std::cout << matrix1.GetNumColumns()<< std::endl;

    return 0;
}

int dialog(const char *msgs[], int n) {
    int choice;
    char temp;
    do {
        for (int i = 0; i < n; ++i)
            puts(msgs[i]);
        std::cout << "> " << std::endl;
//        printf("> ");

        do {
            std::cin >> temp;
//            temp = getchar();
        } while (temp == '\n');

        choice = temp - '0';
        while (getchar() != '\n');
        if (choice < 0 || choice >= n)
            printf("You're wrong. Try again!\n");

        delay(500);
        printf("\033[0d\033[2J");

    } while (choice < 0 || choice >= n);

    return choice;
}

void delay(int milli_seconds) {

    int nano_seconds = 1000 * milli_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + nano_seconds);
}