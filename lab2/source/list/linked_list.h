#ifndef LAB2_LINKED_LIST_H
#define LAB2_LINKED_LIST_H

#include <stdexcept>        //for exception

template<class T>
class LinkedList {

private:
    class Node {
    private:

        T data;
        Node *pNext;

    public:

        explicit Node(T data = T(), Node *pNext = nullptr) {
            this->data = data;
            this->pNext = pNext;
        }

    };

    Node *head_;
    size_t length_;

public:
    //Constructors
    LinkedList();
    LinkedList(T *data, int count);
    LinkedList(const LinkedList<T> &list);


    //Decomposition
    T &Front() const;
    T &Back() const;
    T &Get(int index) const;
    void PopFront();
    void PopBack();
    void DelByIndex(int index);
    void Clear();
    LinkedList<T> *GetSubList(int start_index, int end_index) const;
    [[nodiscard]] size_t GetLength() const;

    //Operations
    void PushFront(const T &data);
    void PushBack(const T &data);
    void InsertAt(const T &data, int index);
    void Set(const T &data, int index);
    LinkedList<T> *Concat(LinkedList<T> *list) const;


    //Destructor
    ~LinkedList();
};

#include "linked_list.tpp"

#endif //LAB2_LINKED_LIST_H