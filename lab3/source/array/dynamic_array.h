#ifndef LAB2_DYNAMIC_ARRAY_H
#define LAB2_DYNAMIC_ARRAY_H


#include <stdexcept>        //for exception
#include <cstring>          //for memcpy()

template<class T>
class DynamicArray {

private:
    T *data_;
    size_t length_;

public:
    //Constructors
    DynamicArray();
    DynamicArray(const T *data, int length);
    explicit DynamicArray(int length);

    //Copy constructor
    DynamicArray(const DynamicArray<T> &array);

    //Decomposition
    T &Get(int index);
    T &operator[](int index);
    [[nodiscard]] size_t GetLength() const;

    //Operations
    void Set(int index, T value);
    void Resize(int length);
    void Insert(int insert_index, T value);
    void Delete(int index);

    //Destructor
    ~DynamicArray();
};

#include "dynamic_array.tpp"


#endif //LAB2_DYNAMIC_ARRAY_H
