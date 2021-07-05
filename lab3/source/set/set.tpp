#include "set.h"
#include "../extrafunctions/extrafunctions.h"
using namespace std;

template<class T>
Set<T>::Set() {
    _elements = new Heap<T>;
}

template<class T>
Set<T>::Set(const Sequence<T> &seq) {
    _elements = new Heap<T>(seq);
}

template<class T>
Set<T>::Set(const Set<T> &set) {
    _elements = new Heap<T>(*set._elements);
}

template<class T>
void Set<T>::Generate(int n, T (*random)()) {
    for (int i = 0; i < n; ++i) {
        T value = random();
        Insert(value);
    }
}

template<class T>
void Set<T>::Clear() {
    _elements->Clear();
}

template<class T>
int Set<T>::GetLength() const {
    return _elements->GetLength();
}

template<class T>
void Set<T>::Insert(T &value) {
    if (!(_elements->CheckEntry(value)))
        _elements->Insert(value);
}

template<class T>
T &Set<T>::GetMax() {
    return _elements->GetMax();
}

template<class T>
bool Set<T>::CheckEntry(T &value) {
    return _elements->CheckEntry(value);
}

template<class T>
void Set<T>::DeleteByValue(T &value) {
    if (_elements->CheckEntry(value))
        _elements->DeleteByValue(value);
}

template<class T>
Set<T> *Set<T>::Union(Set *set) {

    Set<T> *_union(set) ;

    for (int i = 0; i < GetLength(); ++i) {
        _union->Insert((*_elements)[i]);
    }
    return _union;
}

template<class T>
Set<T> Set<T>::operator+(const Set<T> &set) {
    Set<T> _union = set;
    return *(Union(&_union));
}

template<class T>
Set<T> *Set<T>::Crossing(Set *set) {
    Set<T> *_crossing = new Set<T>;
    for (int i = 0; i < std::min(GetLength(), set->GetLength()); ++i) {
        if (set->CheckEntry((*_elements)[i]))
            _crossing->Insert((*_elements)[i]);
        if (CheckEntry((*(set->_elements))[i]))
            _crossing->Insert((*(set->_elements))[i]);

    }
    return _crossing;
}

template<class T>
Set<T> Set<T>::operator*(const Set<T> &set) {
    Set<T> _crossing = set;
    return *(Crossing(&_crossing));
}

template<class T>
Set<T> *Set<T>::Subtraction(Set *set) {
    Set<T> *_subtraction = this;
    for (int i = 0; i < set->GetLength(); ++i) {
        _subtraction->DeleteByValue((*(set->_elements))[i]);
    }
    return _subtraction;
}

template<class T>
Set<T> Set<T>::operator-(const Set<T> &set) {
    Set<T> _subtraction = set;
    return *(Subtraction(&_subtraction));
}

template<class T>
bool Set<T>::CheckSubset(Set *set) {
    for (int i = 0; i < set->GetLength(); ++i) {
        if (!this->CheckEntry((*(set->_elements))[i]))
            return false;
    }
    return true;
}

template<class T>
bool Set<T>::CheckEquelSet(Set *set) {
    return CheckSubset(set) && set->CheckSubset(this);
}

template<class T>
bool Set<T>::operator==(const Set<T> &set) {
    Set<T> _set = set;
    return CheckEquelSet(&_set);
}

template<class T>
string Set<T>::SaveInString() {
    if (_elements->GetLength() == 0) return "";
    string string = "";
    for(int i = 0; i < _elements->GetLength(); ++i) {
        string += to_string((*_elements)[i]);
        if (i != _elements->GetLength() - 1)
            string += ", ";
    }
    return string;
}

template<class T>
std::ostream& operator<<(ostream &out, const Set<T> &s) {
    out << "{ " << *(s._elements) << " }";
    return out;
}

template<class T>
Set<T>::~Set() {
    Clear();
    _elements->~Heap<T>();
}