#include <iostream>
using namespace std;

class Base
{
public:
    virtual void show() = 0;
};

class Relative1 : public Base
{
public:
    void show(){ cout << "Relative1" << endl;}
};

class Relative2 : public Base
{
public:
    void show(){ cout << "Relative2" << endl;}
    void temp(){ cout << "Hi" << endl; }
};

int main()
{
    Base* arr[2];

    Relative1 rl1;
    Relative2 rl2;
    
    arr[0] = &rl1;
    arr[1] = &rl2;
    
    arr[0]->show();
    arr[1]->show();
    return 0;
}