#ifndef LAB3_SET_H
#define LAB3_SET_H


#include "../heap/heap.h"
#include "../heap/heap.tpp"
#include <string>

template<class T>
class Set {
    Heap<T> *_elements;
public:
    //Constructors
    Set();
    Set(const Sequence<T> &seq);
    Set(const Set<T> &heap);

    void Generate(int n, T (*random)());

    //Decomposition
    void Clear();
    int GetLength() const;

    //Operations
    void Insert(T &value);
    T &GetMax();
    bool CheckEntry(T &value);
    void DeleteByValue(T &value);

    Set<T> *Union(Set *set);
    Set<T> operator+(const Set<T> &set);
    Set<T> *Crossing(Set *set);
    Set<T> operator*(const Set<T> &set);
    Set<T> *Subtraction(Set *set);
    Set<T> operator-(const Set<T> &set);

    bool CheckSubset(Set *set);
    bool CheckEquelSet(Set *set);
    bool operator==(const Set<T> &set);


    std::string SaveInString();

    template<class R>
    friend std::ostream& operator<<(std::ostream &out, const Set<R> &s);

    //Destructor
    ~Set();
};

#endif //LAB3_SET_H
