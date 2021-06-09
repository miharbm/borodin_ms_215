#ifndef LAB2_RECT_MATRIX_H
#define LAB2_RECT_MATRIX_H
#include <iostream>
#include "../sequence/sequence.h"
#include "../sequence/array_sequence.h"

template<class T>
class RectMatrix{
private:
    size_t num_columns_;
    size_t num_rows_;

    Sequence<T>* matrix;
public:
    RectMatrix(){
        num_columns_ = 0;
        num_rows_ = 0;
        matrix = new ArraySequence<T>;
    };

    size_t GetNumColumns() const {
        return this->num_columns_;
    }
};
#endif //LAB2_RECT_MATRIX_H