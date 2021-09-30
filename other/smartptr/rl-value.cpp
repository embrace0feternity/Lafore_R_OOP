#include <iostream>

using namespace std;

template <typename T>
class PTR
{
    T *ptr;
public:
    PTR(T *ptr = nullptr): ptr(ptr) { }
    ~PTR() { delete ptr; }

    PTR(const PTR &other);
    PTR& operator = (const PTR &other);

};

template <typename T>
PTR<T>::PTR(const PTR<T> &other)
{
    ptr = new T;
    ptr = other.ptr;
}

template <typename T>
PTR<T>& PTR<T>::operator = (const PTR<T> &other)
{
    if (&other == this) return *this;
    delete ptr; 
    ptr = new T;
    *ptr = *other.ptr;
    return *this;
}

class Item
{
public:
    Item() { cout << "Item create" << endl; }
    ~Item() { { cout << "Item destroy" << endl; }}
};



PTR<Item> foo()
{
    PTR<Item> p2(new Item);
    return p2;
}


int main()
{
    PTR<Item> p1;
    p1 = foo();
    return 0;
}