#include <iostream>
#include "linked_list.h"


template<class T>
LinkedList<T>::LinkedList() {
    length_ = 0;
    head_ = nullptr;
}

template<class T>
LinkedList<T>::LinkedList(T *data, int count) : LinkedList() {
    for (int i = 0; i < count; i++)
        PushBack(data[i]);
}

template<class T>
LinkedList<T>::LinkedList(const LinkedList<T> &list) : LinkedList() {
    Node *node = list.head_;
    for (int i = 0; i < list.length_; i++) {
        PushBack(node->data);
        node = node->pNext;
    }
}

template<class T>
T &LinkedList<T>::Front() const {

    if (!this->length_)
        throw std::out_of_range ("from LinkedList<T>::Front()");
//        throw "The list is empty!";
    T &front = this->head_->data;
    return front;

}

template<class T>
T &LinkedList<T>::Back() const {
    try {
        if (!this->length_)
            throw std::out_of_range ("from LinkedList<T>::Back()");
        Node *node = this->head_;
        for (int i = 0; i < this->length_; ++i) {
            node = node->pNext;
        }
        T &back = node->data;
        return back;
    }  catch (const char* error) {
        std::cout << error << std::endl;
    }
}

template<class T>
T &LinkedList<T>::Get(int index) const {
    try {
        if (index >= this->length_ || index < 0)
            throw std::out_of_range ("from LinkedList<T>::Get()");
        Node *node = this->head_;
        for (int i = 0; i < index; ++i) {
            node = node->pNext;
        }
        T &value = node->data;
        return value;
    } catch(const char* error) {
        std::cout << error << std::endl;
    }
}

template<class T>
void LinkedList<T>::PopFront() {
    try {
        if (!this->length_)
            throw std::out_of_range ("from LinkedList<T>::PopFront()");
        Node* del_node = this->head_;
        this->head_ = this->head_->pNext;
        delete del_node;
        --this->length_;
    }  catch (const char* error) {
        std::cout << error << std::endl;
    }
}

template<class T>
void LinkedList<T>::PopBack() {
    try {
        if (!this->length_)
            throw std::out_of_range ("from LinkedList<T>::PopBack()");
        Node* node = this->head_;
        for (int i = 0; i < this->length_ - 1; ++i) node = node->pNext;
        Node* del_node = node->pNext;
        node->pNext = nullptr;
        delete del_node;
        --this->length_;
    }  catch (const char* error) {
        std::cout << error << std::endl;
    }
}

template<class T>
void LinkedList<T>::Clear() {
    while (length_)
        PopFront();
}

template<class T>
void LinkedList<T>::DelByIndex(int index) {
    try {
        if (index < 0 || index >= length_)
            throw std::out_of_range ("from LinkedList<T>::DelByIndex()");
        if (!index) {
            Node *n_del = head_;
            head_ = head_->pNext;
            delete n_del;
            --length_;
            return;
        }
        Node *n = head_;
        for (int i = 1; i < index; ++i) {
            n = n->pNext;
        }
        Node *n_del = n->pNext;
        n->pNext = n->pNext->pNext;
        delete n_del;
        --length_;
    }  catch (const char *error) {
        std::cout << error << std::endl;
    }
}

template<class T>
LinkedList<T> *LinkedList<T>::GetSubList(int start_index, int end_index) const {
    try {
        if (start_index < 0 || start_index >= this->length_ || end_index < 0 || end_index > this->length_)
            throw std::out_of_range ("from LinkedList<T>::GetSubList");
        if (start_index > end_index)
            std::swap(start_index, end_index);
        LinkedList<T>* list = new LinkedList<T>;
        for (int i = start_index; i < end_index; ++i)
            (*list).PushBack(this->Get(i));
        return list;
    }  catch (const char* error) {
        std::cout << error << std::endl;
    }
}

template<class T>
int LinkedList<T>::GetLength() const {
    return length_;
}

template<class T>
void LinkedList<T>::PushFront(const T &data) {
    Node* new_node = new Node;
    *new_node = Node(data);
    if (!this->length_) {
        this->head_ = new_node;
        ++this->length_;
        return;
    }
    new_node->pNext = this->head_;
    this->head_ = new_node;
}

template<class T>
void LinkedList<T>::PushBack(const T &data) {
    Node* new_node = new Node;
    new_node->data = data;
    new_node->pNext = nullptr;
    if (!this->length_) {
        this->head_ = new_node;
        ++this->length_;
        return;
    }
    Node *node = this->head_;
    for(int i = 0; i < this->length_ - 1; ++i) {
        node = node->pNext;
    }
    node->pNext = new_node;
    ++this->length_;
}

template<class T>
void LinkedList<T>::InsertAt(const T &data, int index) {
    try {
        if (index < 0 || index > this->length_)
            throw std::out_of_range ("from LinkedList<T>::InsertAt");
        if (!index) {
            this->PushFront(data);
            return;
        }
        if (index == this->length_) {
            this->PushBack(data);
            return;
        }
        Node* node = this->head_;
        for (int i = 0; i < index - 1; ++i) {
            node = node->pNext;
        }
        Node* new_node = new Node;
        *new_node = Node(data, node->pNext);
        node->pNext = new_node;
        ++this->length_;
    }  catch (const char* error) {
        std::cout << error << std::endl;
    }
}

template<class T>
void LinkedList<T>::Set(const T &data, int index) {
    try {
        if (index < 0 || index > this->length_)
            throw std::out_of_range ("from LinkedList<T>::Set");
        if (index == length_) {
            this->PushBack(data);
            return;
        }
        Node* node = this->head_;
        for (int i = 0; i < index; ++i) {
            node = node->pNext;
        }
        node->data = data;
    }  catch (const char* error) {
        std::cout << error << std::endl;
    }
}

template<class T>
LinkedList<T> *LinkedList<T>::Concat(LinkedList<T> *list) const {
    try {
        if (list == nullptr)
            throw std::out_of_range ("from LinkedList<T>::Concat");
        LinkedList* new_list = new LinkedList;
        for (int i = 0; i < this->GetLength(); ++i) {
            new_list->PushBack(this->Get(i));
        }
        for (int i = 0; i < list->GetLength(); ++i) {
            new_list->PushBack(list->Get(i));
        }
        return new_list;
    }  catch (const char *error) {
        std::cout << error << std::endl;
    }
}

template<class T>
LinkedList<T>::~LinkedList() {
    Clear();
}