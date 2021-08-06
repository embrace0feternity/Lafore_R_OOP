#include <iostream>
#include <typeinfo>

class Base
{
    virtual void someFunc();
};
class Derv1 : public Base
{

};
class Derv2 : public Base
{

};

bool isDerv1(Base *unknown)
{
    Derv1 *pDerv1;
    if (pDerv1 = dynamic_cast<Derv1*>(unknown)) return true; else return false;
}


int main()
{
    Derv1* d1 = new Derv1;
    Derv2* d2 = new Derv2;

    if (isDerv1(d1))
        std::cout << "d1 belongs to Derv1" << std::endl;
    else
        std::cout << "d1 doen't belong to Derv1" << std::endl;

    
    if (isDerv1(d2))
        std::cout << "d2 belongs to Derv1" << std::endl;
    else
        std::cout << "d2 doen't belong to Derv1" << std::endl;    
    return 0;
}