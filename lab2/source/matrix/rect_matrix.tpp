#ifndef LAB2_RECT_MATRIX_TPP
#define LAB2_RECT_MATRIX_TPP

#include "rect_matrix.h"


template<class T>
RectMatrix<T>::RectMatrix(): num_rows_(0), num_columns_(0), elements_(0) {};

template<class T>
RectMatrix<T>::RectMatrix(int num_rows, int num_columns) {
    num_columns_ = num_columns;
    num_rows_ = num_rows;
    elements_ = new ArraySequence<ArraySequence<T>>;
};

template<class T>
RectMatrix<T>::RectMatrix(const RectMatrix<T> &matrix) {
    num_columns_ = matrix.num_columns_;
    num_rows_ = matrix.num_rows_;
//    this->Set(matrix.num_rows_, matrix.num_columns_);
    elements_ = matrix.elements_;
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

    elements_.Resize(num_rows_);
    for (int i = 0; i < num_rows_; ++i) {
        elements_[i].Resize(num_columns_);
    }
}

template<class T>
T &RectMatrix<T>::At(int row, int column) {
    return elements_.at(row).at(column);
}

template<class T>
ArraySequence<T> &RectMatrix<T>::operator[](int i) {
    return elements_[i];
}

template<class T>
ArraySequence<T> &RectMatrix<T>::operator[](int i) const {
    return elements_.at(i);
}

template<class T>
[[nodiscard]] size_t RectMatrix<T>::GetNumColumns() const {
    return num_columns_;
}

template<class T>
[[nodiscard]] size_t RectMatrix<T>::GetNumRows() const {
    return num_rows_;
}

template<class T>
RectMatrix<T> &RectMatrix<T>::transpose() {

    RectMatrix<T> result;
    result.num_rows_ = num_columns_;
    result.num_columns_ = num_rows_;
    result.Set(result.GetNumRows(), result.GetNumColumns());
    for (size_t row = 0; row < result.GetNumRows(); ++row) {
        for (size_t column = 0; column < result.GetNumColumns(); ++column) {
            result[row][column] = this->At(column, row) ;
        }
    }
//    std::cout<<"result"<<result<<std::endl;

    return result;
}

template<class T>
RectMatrix<T> &RectMatrix<T>::operator = (const RectMatrix<T> &matrix) {
    this->num_rows_ = matrix.num_rows_;
    this->num_columns_ = matrix.num_columns_;
    this->Set(this->GetNumRows(), this->GetNumColumns());
    for (int i = 0; i < matrix.num_rows_; ++i) {
        for (int j = 0; j < matrix.num_columns_; ++j) {
            this->At(i,j) = matrix[i][j];
        }
    }
    return *this;
}

template<class T>
RectMatrix<T> operator + (const RectMatrix<T> &one, const RectMatrix<T> &two) {
    if ((one.GetNumRows() != two.GetNumRows()) || (one.GetNumColumns() != two.GetNumColumns()) ) {
        throw std::out_of_range("from RectMatrix<T> operator + ()");
    }

    RectMatrix<T> result;
    result.num_rows_ = one.GetNumRows();
    result.num_columns_ = one.GetNumColumns();
    result.Set(result.GetNumRows(), result.GetNumColumns());
    for (size_t row = 0; row < result.GetNumRows(); ++row) {
        for (size_t column = 0; column < result.GetNumColumns(); ++column) {
            result[row][column] = one[row][column] + two[row][column];
        }
    }

    return result;
}

template<class T>
RectMatrix<T> operator * (T lambda, const RectMatrix<T> &matrix) {

    RectMatrix<T> result;
    result.num_rows_ = matrix.GetNumRows();
    result.num_columns_ = matrix.GetNumColumns();
    result.Set(result.GetNumRows(), result.GetNumColumns());
    for (size_t row = 0; row < result.GetNumRows(); ++row) {
        for (size_t column = 0; column < result.GetNumColumns(); ++column) {
            result[row][column] = lambda * matrix[row][column];
        }
    }

    return result;
}

template<class T>
bool operator == (const RectMatrix<T> &one, const RectMatrix<T> &two) {
    if (one.GetNumRows() != two.GetNumRows()) {
        return false;
    }

    if (one.GetNumColumns() != two.GetNumColumns()) {
        return false;
    }

    for (int row = 0; row < one.GetNumRows(); ++row) {
        for (int column = 0; column < one.GetNumColumns(); ++column) {
            if (one.At(row, column) != two.At(row, column)) {
                return false;
            }
        }
    }

    return true;
}



template<class T>
std::istream &operator >> (std::istream &in, RectMatrix<T> &matrix) {
    int num_rows, num_columns;
    in >> num_rows >> num_columns;

    matrix.Set(num_rows, num_columns);
    for (int row = 0; row < num_rows; ++row) {
        for (int column = 0; column < num_columns; ++column) {
            in >> matrix.At(row, column);
        }
    }

    return in;
}

template<class T>
std::ostream &operator<<(std::ostream &out, /*const*/ RectMatrix<T> &matrix) {
    out << matrix.GetNumRows() << " " << matrix.GetNumColumns() << std::endl;
    for (int row = 0; row < matrix.GetNumRows(); row++) {
        for (int column = 0; column < matrix.GetNumColumns(); column++) {
            if (column > 0) {
                out << " ";
            }
            out << matrix[row][column];
        }
        out << std::endl;
    }

    return out;
}


#endif //LAB2_RECT_MATRIX_TPP
