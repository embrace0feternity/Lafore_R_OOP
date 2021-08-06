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
    B(): A() { }
    void get()override { cout << "B" << endl; }
    void test() {}
};


class C : public B
{
public:
    C(): B() { }
    void get()override { cout << "C" << endl; }
};

int main()
{
    C objc;
    A &refA = objc;
    refA.get();
    return 0;
}