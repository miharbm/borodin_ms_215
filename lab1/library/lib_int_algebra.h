#ifndef INT_ALGEBRA_H
#define INT_ALGEBRA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define bool _Bool

#include "./array.h"


int compare_int (const void *left, const void *right);
void square_int(void * element);
bool sign_int(void * element);
void mult_two_int(void *element);

#endif //INT_ALGEBRA_H
