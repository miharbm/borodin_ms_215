#ifndef LAB2_LIST_SEQUENCE_H
#define LAB2_LIST_SEQUENCE_H


#include "sequence.h"
#include "../list/linked_list.h"

template <class T>
class ListSequence: public Sequence<T> {

private:
    LinkedList<T> *_list;

public:
    //Constructors
    ListSequence();
    ListSequence(T* data, int count);
    ListSequence(const ListSequence<T>& list);

    //Decomposition
    T& GetFirst();
    T& GetLast();
    T& Get(int index);
    T& operator[] (int index);
    Sequence<T> *GetSubSequence(int start_index, int end_index) const;
    [[nodiscard]] size_t GetLength() const;
    void Remove(int index);

    //Operations
    void Append(const T& value);
    void Prepend(const T& value);
    void InsertAt(const T& value, int index);
    void Set(const T& item, int index);
    Sequence<T> *Concat(Sequence<T> *seq) const;

    //Destructor
    ~ListSequence();
};

#include "list_sequence.tpp"

#endif //LAB2_LIST_SEQUENCE_H