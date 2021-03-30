int compare_float (const void *left, const void *right) {

    double compare;
    int result;

    compare = *(double*)left - *(double*)right;

    if (fabs(compare) < 0.0000001){
        result =  0;
    } else if(compare > 0) {
        result =  1;
    } else {
        result = -1;
    }

    return result;
}

void square_float(void * element) {
    *(double*)element = (*(double*)element) * (*(double*)element);
}

int sign_float(void * element) {
    int res;
    if (*(double*)element >= 0) res = 1 ;
    else /*if (*(long*)element < 0)*/ res = -1;
    return res;
}

void mult_two_float(void *element){
    *(double*)element = 2 * (*(double*)element);
}
