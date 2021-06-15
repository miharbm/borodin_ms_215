#ifndef LAB2_RECT_MATRIX_H
#define LAB2_RECT_MATRIX_H

#include <iostream>
#include "../sequence/sequence.h"
#include "../sequence/array_sequence.h"

template<class T>
class RectMatrix{
private:
    size_t num_columns_{};
    size_t num_rows_{};

    ArraySequence<ArraySequence<T>> elements_;
public:

    RectMatrix();
    RectMatrix(int num_rows, int num_columns);
    RectMatrix(const RectMatrix<T> &matrix);

    void Set(int num_rows, int num_columns);
    T &At(int row, int column);

    RectMatrix<T> &transpose();
    ArraySequence<T> &operator[] (int i);
    ArraySequence<T> &operator[] (int i) const;
    [[nodiscard]] size_t GetNumColumns() const;
    [[nodiscard]] size_t GetNumRows() const;

    RectMatrix<T>& operator=(const RectMatrix<T>& matrix);
    template <typename U>
    friend RectMatrix<U> operator+(const RectMatrix<U>& one, const RectMatrix<U>& two);
    template <typename U>
    friend bool operator==(const RectMatrix<U>& one, const RectMatrix<U>& two);
    template <typename U>
    friend std::istream& operator>>(std::istream& in,RectMatrix<U>&RectMatrix);
    template <typename U>
    friend std::ostream& operator<<(std::ostream& out, /*const*/ RectMatrix<U> &RectMatrix);
    template <class U>
    friend RectMatrix<U> operator*(U lambda, const RectMatrix<U>&RectMatrix);


};


#include "rect_matrix.tpp"
#endif //LAB2_RECT_MATRIX_H