#include <iostream>
#include <typeinfo>

class Base
{
protected:
    int ba;
public:
    Base(): ba(0) { }
    Base(int b): ba(b) { }

    void virtual somefunc() { }
    void show()const { std::cout << "Base: ba = " << ba << std::endl; }
};

class Derv1 : public Base
{
private:
    int da;
public:
    Derv1(int a, int b): da(b) { ba = a; }
    
    void show()const { std::cout << "Base: ba = " << ba << ".  da = " << da << std::endl; }
};


int main()
{
    Base *pBase = new Base(10);
    Derv1 *pDerv = new Derv1(12,22);

    pBase = dynamic_cast<Base*>(pDerv);
    pBase->show();

    pBase = new Derv1(65,1234);
    pDerv = dynamic_cast<Derv1*>(pBase);
    pDerv->show();

    return 0;
}