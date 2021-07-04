#include "heap.h"
#include <cmath>

template<class T>
void Heap<T>::SiftDown(int index) {
    if (index >= _heap->GetLength() || index < 0)
        throw std::out_of_range("from Heap<T>::SiftDown(int index)");
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int maxChild = left;
    while (left < _heap->GetLength()) {
        if (right < _heap->GetLength() && (*_heap)[left] < (*_heap)[right])
            maxChild = right;
        if ((*_heap)[index] > (*_heap)[maxChild])
            return;
        std::swap((*_heap)[index], (*_heap)[maxChild]);
        index = maxChild;
        left = 2 * index + 1;
        right = 2 * index + 2;
        maxChild = left;
    }
}

template<class T>
void Heap<T>::SiftUp(int index) {
    if (index >= _heap->GetLength() || index < 0)
        throw std::out_of_range("from Heap<T>::SiftUp(int index)");
    int parrent = (index - 1) / 2;
    while ((index > 0) && ((*_heap)[index] > (*_heap)[parrent])) {
        std::swap((*_heap)[index], (*_heap)[parrent]);
        index = parrent;
        parrent = (index - 1) / 2;
    }
}

template<class T>
Heap<T>::Heap() {
    _heap = (Sequence<T> *) new ArraySequence<T>;
}

template<class T>
Heap<T>::Heap(const Sequence<T> &seq) {
    *_heap = seq;
    if (seq.GetLength() == 0)
        return;
    for (int i = seq.GetLength(); i >= 0; --i) {
        SiftDown(i);
    }
}

template<class T>
Heap<T>::Heap(Heap<T> &heap) {
    _heap = (Sequence<T> *) new ArraySequence<T>;
    for (int i = 0; i < heap.GetLength(); ++i) {
        _heap->Append(heap[i]);
    }
}

template<class T>
void Heap<T>::Clear() {
    while (_heap->GetLength() != 0)
        ExtractMax();
}

template<class T>
int Heap<T>::GetLength() const {
    return _heap->GetLength();
}

template<class T>
void Heap<T>::Insert(T &value) {
    _heap->Append(value);
    SiftUp(_heap->GetLength() - 1);
}

template<class T>
T &Heap<T>::GetMax() {
    if (_heap->GetLength() == 0)
        throw std::out_of_range("from Heap<T>::ExtractMax()");
    return (*_heap)[0];
}

template<class T>
T &Heap<T>::GetByIndex(int index) {
    if (index >= _heap->GetLength() || index < 0)
        throw std::out_of_range("from Heap<T>::GetByIndex(int index)");
    return (*_heap)[index];
}

template<class T>
T &Heap<T>::operator[] (const int index) {
    return GetByIndex(index);
}

template<class T>
T &Heap<T>::ExtractMax() {
    if (_heap->GetLength() == 0)
        throw std::out_of_range("from Heap<T>::ExtractMax()");
    T t = (*_heap)[0];
    (*_heap)[0] = (*_heap)[_heap->GetLength() - 1];
    SiftDown(0);
    _heap->Remove(_heap->GetLength() - 1);
    return t;
}

template<class T>
bool Heap<T>::CheckEntry(T &value) {
    if (_heap->GetLength() == 0) return false;
    int maxLevel = floor(log(_heap->GetLength())) + 1;
    for (int i = 0; i <= maxLevel; ++i) {
        int leftLimit = pow(2, i) - 1;
        int rightLimit = pow(2, i + 1) - 1;
        bool isMore = false;
        for (int j = leftLimit; j < rightLimit; ++j) {
            if (j < _heap->GetLength() && (*_heap)[j] == value)
                return true;
            if (j < _heap->GetLength() && (*_heap)[j] > value)
                isMore = true;

        }
        if (!isMore) return false;
    }
    return false;
}

template<class T>
void Heap<T>::DeleteByValue(T &value) {
    if (!CheckEntry(value)) return;
    int maxLevel = floor(log(_heap->GetLength())) + 1;
    for (int i = 0; i <= maxLevel; ++i) {
        int leftLimit = pow(2, i) - 1;
        int rightLimit = pow(2, i + 1) - 1;
        for (int j = leftLimit; j < rightLimit; ++j) {
            if (j < _heap->GetLength() && (*_heap)[j] == value) {
                (*_heap)[i] = GetMax();
                SiftUp(i);
                ExtractMax();
                return;
            }
        }
    }
}

template<class T>
std::string toString(T &value) {
    return "{ " + std::to_string(value) + " }";
}

template<class T>
std::string toString(T &value1, T& value2) {
    return "{ " + std::to_string(value1) + ", " + std::to_string(value2) + " }";
}

template<class T>
std::string Heap<T>::SavePairsInString() {
    if (_heap->GetLength() == 0) return "";
    std::string pairs = toString((*_heap)[0]);
    for (int i = 1; i < _heap->GetLength() ; ++i) {
        int parrent = (i - 1) / 2;
        pairs += " " + toString((*_heap)[parrent], (*_heap)[i]);
    }
    return pairs;
}

template<class T>
std::ostream& operator<<(std::ostream &out, const Heap<T> &h) {
    for (int i = 0; i < h.GetLength(); ++i) {
        out << (*h._heap)[i];
        if (i != h.GetLength() - 1)
            out << ", ";
    }
    return out;
}

template<class T>
Heap<T>::~Heap() {
    Clear();
}