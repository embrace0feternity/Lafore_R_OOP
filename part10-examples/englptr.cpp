#include <iostream>
using namespace std;

class Distance
{
private:
    int feet;
    float inches;
public:
    Distance() { cout << "constr: " << this << endl; }
    void set() { cout << "Feet: "; cin >> feet; 
    cout << "Inches: "; cin >> inches; }
    ~Distance() { cout << "destr: " << this << endl;}

    void get()const { cout << feet << '-' << inches << endl;}
};

void foo()
{
    Distance temp1;
    Distance *temp2 = new Distance;
}


int main()
{
    Distance dist;
    dist.set();
    dist.get();
    
    Distance *distptr = new Distance;
    cout << distptr << endl;
    (*distptr).set();
    distptr->get();
     
    return 0;
}