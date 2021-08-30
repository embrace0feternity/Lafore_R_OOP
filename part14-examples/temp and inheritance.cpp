#include <iostream>
using namespace std;

template <typename T>
class worker
{
protected:
    char type;
    T salary;
public:
    worker(T s): type('w'), salary(s) { }
    virtual void showSalary() { std::cout << "workers salary: " << salary << std::endl; }
};

template <typename T>
class engineer : public worker<T> 
{
public:
    engineer(T s): worker<T>(s) { }
    void showSalary() { std::cout << "engineers salary: " << worker<T>::salary << std::endl; }
};


int main()
{
    engineer<int> en(20);
    worker<int> *pointer = &en;
    pointer->showSalary();
    return 0;
}