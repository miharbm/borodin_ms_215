#include "./lib_int_algebra.h"


int compare_int (const void *left, const void *right) {

    long compare;
    int result;

    compare = *(long*)left - *(long*)right;

    if (compare == 0){
        result =  0;
    } else if(compare > 0) {
        result =  1;
    } else {
        result = -1;
    }

    return result;
}

void square_int(void * element) {
    *(long*)element = (*(long*)element) * (*(long*)element);
}

bool sign_int(void * element) {
    bool res;
    if (*(long*)element >= 0) res = true ;
    else /*if (*(long*)element < 0)*/ false;
    return res;
}

void mult_two_int(void *element){
    *(long*)element = 2 * (*(long*)element);
}
