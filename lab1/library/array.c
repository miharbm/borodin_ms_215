#include "./array.h"

void destructArray (array_t *array) {

    free(array->elements);
    free(array);
}

array_t * make_array_int() {

    printf("Введите кол-во элементов: ");
    size_t num = 0;
    do {
        scanf("%lu", &num);
        if(num <= 0)
            printf("Error, invalid length, please, try again\n");
    } while(num <= 0);

    printf("Введите элементы:\n");

    long *Arr = malloc(sizeof(long) * num);

    for(int i = 0; i < num; i++) {
        printf("[%d] = ", i);
        scanf("%ld", Arr + i);
    }

    array_t *  array = malloc(sizeof(array_t));

    array->elementSize = sizeof(long);
    array->num = num;
    array->elements = Arr;
    array->compare = (int(*)(const void *, const void *))compare_int;
    array->print = (void(*)(void * array))print_array_int;
    array->sign = (bool(*)(void * element))sign_int;
    array->square = (void(*)(void * element))square_int;
    array->mult2 = (void(*)(void * element))mult_two_int;


    getchar();

    return array;
}

array_t * make_array_float() {

    printf("Введите кол-во элементов: ");
    size_t num = 0;
    do {
        scanf("%lu", &num);
        if(num <= 0)
            printf("Error, invalid length, please, try again\n");
    } while(num <= 0);

    printf("Введите элементы:\n");

    double *Arr = malloc(sizeof(double) * num);

    for(int i = 0; i < num; i++) {
        printf("[%d] = ", i);
        scanf("%lf", Arr + i);
    }

    array_t *  array = malloc(sizeof(array_t));

    array->elementSize = sizeof(double);
    array->num = num;
    array->elements = Arr;
    array->compare = (int(*)(const void *, const void *))compare_float;
    array->print = (void(*)(void * array))print_array_float;
    array->sign = (bool(*)(void * element))sign_float;
    array->square = (void(*)(void * element))square_float;
    array->mult2 = (void(*)(void * element))mult_two_float;


    getchar();

    return array;
}

array_t * make_copy_array_t(const array_t * array_original) {

    array_t * array_result = malloc(sizeof(array_t));

    array_result->elementSize = array_original->elementSize;
    array_result->num = array_original->num;
    array_result->elements = malloc(array_result->elementSize * array_result->num);
    memcpy(array_result->elements, array_original->elements, array_result->elementSize * array_result->num);
    array_result->compare = array_original->compare;
    array_result->print = array_original->print;
    array_result->sign = array_original->sign;
    array_result->square = array_original->square;
    array_result->mult2 = array_original->mult2;


    return array_result;
}

void print_array_int(void * array_tmp) {
    array_t * array = array_tmp;
    for(size_t i = 0; i < array->num; i++)
        printf("[%lu] = %ld\n",i, *((long*)(array->elements + i * array->elementSize)));
}

void print_array_float(void * array_tmp) {
    array_t * array = array_tmp;
    for(size_t i = 0; i < array->num; i++)
        printf("[%lu] = %lf\n",i, *((double*)(array->elements + i * array->elementSize)));
}
