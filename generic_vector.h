//
// Created by dusce on 4/11/2023.
//

#ifndef FILME_GENERIC_Vector_H
#define FILME_GENERIC_Vector_H

// C++ program to implement Custom Vector
// class
#include "iostream"
#define ll long long
using namespace std;

// Template class to create Vector of
// different data_type
template <typename DT>
class GenericMyVector {
private:
    DT* arr;

    // Variable to store the current capacity
    // of the Vector
    ll capacity;

    // Variable to store the length of the
    // Vector
    ll length;

public:
    explicit GenericMyVector(ll = 100);

    // Function that returns the number of
    // elements in array after pushing the data
    ll push_back(DT);

    // function that returns the popped element
    DT pop_back();

    // Function that return the size of Vector
    ll size() const;
    DT& operator[](ll);

    // Iterator Class
    class iterator {
    private:
        // Dynamic array using pointers
        DT* ptr;

    public:
        explicit iterator()
                : ptr(nullptr)
        {
        }
        explicit iterator(DT* p)
                : ptr(p)
        {
        }
        bool operator==(const iterator& rhs) const
        {
            return ptr == rhs.ptr;
        }
        bool operator!=(const iterator& rhs) const
        {
            return !(*this == rhs);
        }
        DT operator*() const
        {
            return *ptr;
        }
        iterator& operator++()
        {
            ++ptr;
            return *this;
        }
        iterator operator++(int)
        {
            iterator temp(*this);
            ++*this;
            return temp;
        }
    };

    // Begin iterator
    iterator begin() const;

    // End iterator
    iterator end() const;
};

// Template class to return the size of
// Vector of different data_type
template <typename DT>
GenericMyVector<DT>::GenericMyVector(ll n)
        : capacity(n), arr(new DT[n]), length(0)
{
}

// Template class to insert the element
// in Vector
template <typename DT>
ll GenericMyVector<DT>::push_back(DT data)
{
    if (length == capacity) {
        DT* old = arr;
        arr = new DT[capacity = capacity * 2];
        copy(old, old + length, arr);
        delete[] old;
    }
    arr[length++] = data;
    return length;
}

// Template class to return the popped element
// in Vector
template <typename DT>
DT GenericMyVector<DT>::pop_back()
{
    return arr[length-- - 1];
}

// Template class to return the size of
// Vector
template <typename DT>
ll GenericMyVector<DT>::size() const
{
    return length;
}

// Template class to return the element of
// Vector at given index
template <typename DT>
DT& GenericMyVector<DT>::operator[](ll index)
{
    // if given index is greater than the
    // size of Vector print Error
    if (index >= length) {
        cout << "Error: Array index out of bound";
        exit(0);
    }

    // else return value at that index
    return *(arr + index);
}

// Template class to return begin iterator
template <typename DT>
typename GenericMyVector<DT>::iterator
GenericMyVector<DT>::begin() const
{
    return iterator(arr);
}

// Template class to return end iterator
template <typename DT>
typename GenericMyVector<DT>::iterator
GenericMyVector<DT>::end() const
{
    return iterator(arr + length);
}

// Template class to display element in
// Vector
template <typename V>
void display_Vector(V& v)
{
    // Declare iterator
    typename V::iterator ptr;
    for (ptr = v.begin(); ptr != v.end(); ptr++) {
        cout << *ptr << ' ';
    }
    cout << '\n';
}


#endif //FILME_GENERIC_Vector_H
