#include <iostream>
#include <list>

class abstract
{
public:
    virtual void test() = 0;
};

class childA : public abstract
{
public:
    void test() { }
};

class childB : public abstract
{
public:
    void test() { }
};

int main()
{
    childA A;
    childB B;
    
    std::list<abstract *> lst = { &A, &B };
    return 0;
}