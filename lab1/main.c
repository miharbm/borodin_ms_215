#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

#define bool _Bool


#include "./library/array.h"
#include "./library/lib_int_algebra.h"
#include "./library/lib_float_algebra.h"

#include "./library/array.c"
#include "./library/lib_int_algebra.c"
#include "./library/lib_float_algebra.c"


const char * MENU_MAIN[] = {"0. Отмена",
                            "1. Целые числа",
                            "2. Действительные числа"};
const int MENU_MAIN_SIZE = sizeof(MENU_MAIN) / sizeof(MENU_MAIN[0]);

const char * MENU_SECOND[] = {"0. Отмена",
                              "1. Сортировка",
                              "2. map",
                              "3. where",
                              "4. Конкатенация"};
const int MENU_SECOND_SIZE = sizeof(MENU_SECOND) / sizeof(MENU_SECOND[0]);

const char * MENU_MAP[] = {"0. Отмена",
                           "1. square",
                           "2. mult by 2"};
const int MENU_MAP_SIZE = sizeof(MENU_MAP) / sizeof(MENU_MAP[0]);

const char * MENU_WHERE[] = {"0. Отмена",
                             "1. positive"};
const int MENU_WHERE_SIZE = sizeof(MENU_WHERE) / sizeof(MENU_WHERE[0]);

const char * MENU_OUTPUT[] = {"0. Отмена",
                              "1. вывод в терминал"
                              "2. вывод в файл"};
const int MENU_OUTPUT_SIZE = sizeof(MENU_OUTPUT) / sizeof(MENU_OUTPUT[0]);


int dialog (const char *msgs[], int n);
void delay (int milli_seconds);

void second_menu(array_t * array, int type_ar);
void map_menu(array_t * array);
void where_menu(array_t * array);
array_t * map(void (*func)(void *element),  array_t *array_original);
array_t * where(bool (*func)(void *element),  array_t *array_original);
array_t * concatenation(array_t * array1, array_t * array2);
void output_menu(array_t * array);



int main() {

    int menu, type_ar = 0;

    do {

        menu = dialog(MENU_MAIN, MENU_MAIN_SIZE);

        switch(menu) {
            case 0: break;

            case 1: {
                array_t * array = make_array_int();
                type_ar = 1;
                second_menu(array, type_ar);

            } break;

            case 2: {
                array_t * array = make_array_float();
                type_ar = 2;
                second_menu(array, type_ar);
            } break;

            default:
                printf("***Error, please try again***\n");
                break;
        }
    } while (menu != 0);

    return 0;
}

void second_menu(array_t * array, int type_ar) {

    int menu;
    do{
        menu = dialog(MENU_SECOND, MENU_SECOND_SIZE);
        switch(menu) {
            case 0: break;

            case 1: {
                qsort(array->elements,
                      array->num,
                      array->elementSize,
                      array->compare);

                printf("Результат:\n");
                array->print(array);
            } break;

            case 2: {
                map_menu(array);
            } break;

            case 3: {
                where_menu(array);
            } break;

            case 4: {
                array_t * array2;
                if (type_ar == 1) {
                    array2 = make_array_int();
                } else if (type_ar == 2) {
                    array2 = make_array_float();
                } else {
                    printf("Error in type\n");
                    delay(500);
                    return;
                }
                array_t * array3 = concatenation(array, array2);
                printf("Результат:\n");
                array->print(array3);
                destructArray(array2);
                destructArray(array3);
            } break;

            default:
                printf("***Error, please try again***\n");
                break;
        }
    } while (menu != 0);

    destructArray(array);
}

void where_menu(array_t * array) {

    array_t * array2;
    int menu;
    do{

        menu = dialog(MENU_WHERE, MENU_WHERE_SIZE);

        switch(menu) {
            case 0: break;

            case 1: {
                array2 = where(array->sign, array);
                printf("Результат:\n");
                array2->print(array2);
                destructArray(array2);
            }break;

            default:
                printf("***Error, please try again***\n");
                break;
        }
    } while(menu != 0);
}

void map_menu(array_t * array) {

    array_t * array2;
    int menu;
    do {

        menu = dialog(MENU_MAP, MENU_MAP_SIZE);

        switch(menu) {
            case 0: break;

            case 1: {
                array2 = map(array->square, array);
                printf("Результат:\n");
                array->print(array2);
            } break;

            case 2: {
                array2 = map(array->mult2, array);                printf("Результат:\n");
                array->print(array2);
            } break;

            default:
                printf("***Error, please try again***\n");
                break;
        }
    } while (menu != 0);

    destructArray(array2);
}

array_t * map(void (*func)(void *element),  array_t *array_original) {

    array_t * array_result = make_copy_array_t(array_original);

    for(size_t i = 0; i < array_result->num; i++) {
        func(array_result->elements + i * array_result->elementSize);
    }

    return array_result;
}

array_t * where(bool (*func)(void *element),  array_t *array_original) {

    array_t * array_result = malloc(sizeof(array_t));
    array_result->elements = malloc(1);
    array_result->elementSize = array_original->elementSize;
    array_result->num = 0;

    for(size_t i = 0; i < array_original->num; i++) {
        bool condition;
        condition = func(array_original->elements + i * array_original->elementSize);
        if (condition) {
            array_result->num += 1;
            array_result->elements = realloc(array_result->elements, array_result->elementSize * array_result->num);
            memcpy(array_result->elements + array_result->elementSize * (array_result->num - 1),
                    array_original->elements + i * array_original->elementSize,
                    array_original->elementSize);
        }
    }
    return array_result;
}

array_t * concatenation(array_t * array1, array_t * array2) {

    array_t * array_result = malloc(sizeof(array_t));

    array_result->elementSize = array1->elementSize;
    array_result->num = array1->num + array2->num;

    array_result->elements = malloc(array_result->num * array_result->elementSize);

    memcpy(array_result->elements,
            array1->elements,
            array1->num * array1->elementSize);
    memcpy(array_result->elements + array1->num * array1->elementSize ,
            array2->elements,
            array2->num * array2->elementSize);

    return array_result;
}

int dialog (const char *msgs[], int n) {
    int choice;
    char temp;
    do {
        for (int i = 0; i < n; ++i)
            puts(msgs[i]);
        printf("> ");

        do {
            temp = getchar();
        } while(temp == '\n');

        choice = temp - '0';
        while (getchar() != '\n');
        if (choice < 0 || choice >= n)
            printf("You're wrong. Try again!\n");

        delay(500);
        printf("\033[0d\033[2J");

    } while (choice < 0 || choice >= n);

    return choice;
}

void delay (int milli_seconds) {

    int nano_seconds = 1000 * milli_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + nano_seconds);
}

void output_menu(array_t * array) {

    int menu;
    do {
        menu = dialog(MENU_OUTPUT, MENU_OUTPUT_SIZE);

        switch(menu) {
            case 0: break;

            case 1: {
                array->print(array);
            } break;

            case 2: {

            } break;

            default:
                printf("***Error, please try again***\n");
                break;
        }
    } while(menu != 0);
}
