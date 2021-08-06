#include <iostream>
 
class A
{
public:
    virtual const char* getName() { return "A"; }
};
 
class B: public A
{
public:
    virtual const char* getName() { return "B"; }
};
 
class C: public B
{
public:
    virtual const char* getName() { return "C"; }
};
 
class D: public C
{
public:
};
 
int main()
{
    C objC;
    B &ref = objC;
    //D d;
    //A &ref = d;
    std::cout << ref.getName() << '\n';
 
    return 0;
}