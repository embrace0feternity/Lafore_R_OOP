#include <iostream>
using namespace std;

class Parent
{
private:    
    int priv;
public:
    int pub;
    Parent(): priv(0), pub(0), prot(0) {}
    void show()const { cout << "priv: " << priv << "\npub: " << pub << "\nprot " << prot << endl; }
protected:
    int prot;
};

class A : public Parent
{
public:
    int a;
    A(): Parent(), a(5) { }
    void foo()
    {
        //priv = a;
        prot = a+a;
        pub = a-2;
        cout << "FOO       - : prot = " << prot << "\nFOO       - : pub = " << pub << endl;
    }
private:
    void settings() { cout << "Settings" << endl; }
protected:
    void getresult() { cout << "Results = ";}
};


class B : private Parent
{
public:
    int a;
    B() : Parent(), a(2) {}
    void foo()
    {
        pub = a;
        prot = a+20;
        //priv = a-20;
        Parent::show();
    }
private:
    void Settings() { cout << "set" << endl;}
};

int main()
{
    Parent basic;
    basic.show();

    A objA;
    //objA.priv = 3;
    objA.pub = 5;
    //objA.prot = 4;
     objA.foo();
    objA.show();

    cout << endl << "objB -----------------------------------------" << endl;
    B objB;
    objB.foo();
    // objB.pub;
    // objB.priv;
    // objB.prot;

    cout << "basic --------------------------------------------" << endl;
    basic.show();
    return 0;
}