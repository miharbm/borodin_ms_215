#ifndef ARRAY_H
#define ARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

#include "./lib_int_algebra.h"
#include "./lib_float_algebra.h"

#define bool _Bool

typedef struct array_t {

    size_t elementSize;
    size_t num; //кол-во элементов
    void* elements; //ссылка на первый элемент
    int (*compare)(const void* left, const void* right); //функция сравнения
    void (*print)(void * array); //функция вывода массива на экран
    bool (*sign)(void * element); //функция определения знака элемента
    void (*square)(void * element); //функция возведения в квадрат
    void (*mult2)(void * element); //функция умножения на два

} array_t;


void destructArray (array_t *array);
array_t * make_array_int();
array_t * make_copy_array_t(const array_t * array_original);
void print_array_int(void * array);
void print_array_float(void * array_tmp);
array_t * make_array_float();


#endif //ARRAY_H
