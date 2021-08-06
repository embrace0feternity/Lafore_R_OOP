#include <iostream>
using std::endl;

class Beta;

class Alpha
{
private:
    int data_A;
public:
    Alpha(): data_A(10) {}
    friend int function(Alpha &, Beta &);
};

class Beta
{
private:
    int data_B;
public:
    Beta(): data_B(2) {}
    friend int function(Alpha &, Beta &);
};

int function(Alpha &a, Beta &b)
{
    return (a.data_A + b.data_B);
}


int main()
{
    Alpha objA;
    Beta objB;

    std::cout << function(objA, objB) << endl;;

    return 0;
}