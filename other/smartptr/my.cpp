#include <iostream>

template<typename T>
class smart_ptr
{
    T *ptr;
public:
    smart_ptr(T *ptr = nullptr): ptr(ptr) { }
    ~smart_ptr() { delete ptr; }

    T& operator*() const { return *ptr; }
    T* operator->() const { return ptr; }
    bool isNull()const { return ptr == nullptr; }
};

class Age
{
    int age;
public:
    Age(int age = 0): age(age) { std::cout << "Возвраст установлен" << std::endl;}
    ~Age() { std::cout << "Возраст удален" << std::endl; }
};

int main()
{
    using namespace std;
    smart_ptr<Age> pAge(new Age(20));


    int a=0;
    return 0;
}