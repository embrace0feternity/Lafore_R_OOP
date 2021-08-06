#include <iostream>
#include <conio.h>
using namespace std;

enum sign {positive, negative};

class Distance
{
protected:
    int feet;
    float inches;
public:
    Distance(): feet(0), inches(0.0) {}
    Distance(int f, float inch): feet(f), inches(inch) {} 

    void setDistance(); 
    void show()const { cout << feet << '-' << inches << endl; }
};

void Distance::setDistance()
{
    cout << "Write a number of feet: "; cin >> feet;
    cout << "write a number of inches: "; cin >> inches; 
}

class Distance_sign : public Distance
{
private:
    sign s;
public:
    Distance_sign() : Distance() { s = positive; } 
    Distance_sign(int f, float inch, sign s = positive) : Distance(f, inch) { this->s = s; }

    void setDistance();
    void show()const 
    { 
        cout << ((s == positive)? "(+)" : "(-)");
        Distance::show();
    }
};
void Distance_sign::setDistance()
{
    Distance::setDistance();
    cout << "Write sign (\'+\' or \'-\'): ";    
    char ch;        ch = getch();
    s = (ch == '+')? positive : negative;
}

int main(int argc, char **argv)
{
    Distance_sign distA;
    distA.setDistance();
    distA.show();
    
    Distance_sign distB(10, 8.7);
    distB.show();
    Distance_sign distC(4, 2.2, negative);
    distC.show();

    return 0;
}