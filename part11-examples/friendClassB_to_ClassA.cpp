#include <iostream>

class Alpha
{
private:
    int data_A;
public:
    Alpha(): data_A(6) { }
    friend class Beta;
};

class Beta
{
private:
    int data_B;
public:
    Beta(): data_B(3) { }
    void foo(Alpha A)const { std::cout << "data_A = " << A.data_A << std::endl; }    
};

int main()
{
    Alpha objA;
    Beta objB;
    objB.foo(objA);
    return 0;
}