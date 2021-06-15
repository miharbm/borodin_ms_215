#include <iostream>
#include "matrix/rect_matrix.h"




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



const char * MENU_MAIN[] = {"Выход",
                            "Создать матрицу с целыми значениями",
                            "Создать матрицу с вещественными значениями",
                            "Сложить матрицы",
                            "Умножение матрицы на скаляр",
                            "Транспонирование матрицы"};
const int MENU_MAIN_SIZE = sizeof(MENU_MAIN) / sizeof(MENU_MAIN[0]);



int main() {

    int menu;

    do {

        menu = dialog(MENU_MAIN, MENU_MAIN_SIZE);

        switch (menu) {
            case 0: //Отмена
                break;

            case 1: { // "Создать матрицу с целыми значениями",
                RectMatrix<int> matrix1;
                std::cin >> matrix1;
                std::cout <<"matrix:"<<std::endl<< matrix1;

            } break;
            case 2: { //Создать матрицу с вещественными значениями
                RectMatrix<double> matrix1;
                std::cin >> matrix1;
                std::cout <<"matrix:"<<std::endl<< matrix1;
            } break;
            case 3: { //Сложить матрицы
                RectMatrix<int> matrix1;
                std::cin >> matrix1;

                RectMatrix<int> matrix2;
                std::cin >> matrix2;

                std::cout <<"matrix:"<<std::endl<< matrix1;
                std::cout <<"matrix:"<<std::endl<< matrix2;

                RectMatrix<int> matrix3 = RectMatrix(matrix1 + matrix2) ;
                std::cout <<"matrix:"<<std::endl<< matrix3;

            } break;
            case 4: { //Умножить на скаляр
                RectMatrix<int> matrix1;
                std::cin >> matrix1;

                int lambda;
                std::cin >> lambda;
                RectMatrix<int> matrix3 = lambda * matrix1 ;
                std::cout <<"result:"<<std::endl<< matrix3;
            } break;
            case 5: { //Транспонирование
                RectMatrix<int> matrix1;
                std::cin >> matrix1;

                RectMatrix<int> matrix3 = matrix1.transpose();
                std::cout <<"result:"<<std::endl<< matrix3;

            }

            default:
                printf("***Error, please try again***\n");
                break;
        }
    } while (menu != 0);


    return 0;
}



