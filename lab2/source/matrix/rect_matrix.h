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

    ArraySequence<ArraySequence<T>>* elements_;
public:

    RectMatrix();
    RectMatrix(int num_rows, int num_columns);

    void Set(int num_rows, int num_columns);
    int& At(int row, int column);


    [[nodiscard]] size_t GetNumColumns() const;
    [[nodiscard]] size_t GetNumRows() const;


};


#include "rect_matrix.tpp"
#endif //LAB2_RECT_MATRIX_H