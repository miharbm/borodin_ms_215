#ifndef FLOAT_ALGEBRA_H
#define FLOAT_ALGEBRA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define bool _Bool

#include "./array.h"


int compare_float (const void *left, const void *right);
void square_float(void * element);
int sign_float(void * element);
void mult_two_float(void *element);

#endif //FLOAT_ALGEBRA_H
