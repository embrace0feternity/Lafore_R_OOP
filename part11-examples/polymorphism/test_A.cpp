#include <iostream>
using namespace std;

class A
{
public:
    A() { }
    virtual void get() { cout << "A" << endl; }
};


class B : public A
{
public:
    B() { }
    void get()override { cout << "B" << endl; }
    void test() {}
};


int main()
{
    B objB;
    A &refA = objB;
    refA.get();
    return 0;
}