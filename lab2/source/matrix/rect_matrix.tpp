#ifndef LAB2_RECT_MATRIX_TPP
#define LAB2_RECT_MATRIX_TPP

#include "rect_matrix.h"


template<class T>
RectMatrix<T>::RectMatrix(): num_rows_(0), num_columns_(0), elements_(0) {};
template<class T>
RectMatrix<T>::RectMatrix(int num_rows_, int num_columns_) {
    num_columns_ = 0;
    num_rows_ = 0;
    elements_ = new  ArraySequence<ArraySequence<T>>;
};

template<class T>
void RectMatrix<T>::Set(int num_rows, int num_columns) {
    if (num_rows < 0) {
        throw std::out_of_range("from RectMatrix<T>::Set()");
    }
    if (num_columns < 0) {
        throw std::out_of_range("from RectMatrix<T>::Set()");
    }
    if (num_rows == 0 || num_columns == 0) {
        num_rows = num_columns = 0;
    }

    num_rows_ = num_rows;
    num_columns_ = num_columns;

    elements_->resize(num_rows_);
    for (int i = 0; i < num_rows_; ++i) {
        elements_[i]->resize(num_columns_);
    }
}

template<class T>
int &RectMatrix<T>::At(int row, int column) {
    return elements->at(row).at(column);
}

template<class T>
int RectMatrix<T>::At(int row, int column) const {
    return elements_->at(row).at(column);
}

template<class T>
[[nodiscard]] size_t RectMatrix<T>::GetNumColumns() const {
    return num_columns_;
}

template<class T>
[[nodiscard]] size_t RectMatrix<T>::GetNumRows() const {
    return num_rows_;
}
#endif //LAB2_RECT_MATRIX_TPP
