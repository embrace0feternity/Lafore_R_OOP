#include <iostream>
using namespace std;

class counter
{
protected:
    int count;
public:

    counter(): count(0) { cout << "\tcounter constr on" << this << endl; }
    counter(int c): count(c) { cout << "\tcounter const on" << this << endl; }
    ~counter() { cout << "\tcounter destr on" << this << endl;}

    int show()const { return count; }
    counter operator++(int)
    {
        count++;
        return counter(count);
    }
    counter operator+ (int &a)
    {
        return counter(count + a);
    }
};

class classDn : public counter
{
public:
    classDn(): counter () { cout << "\tClassDn constr on" << this << endl; }
    classDn(int n): counter (n) { cout << "\tClassDn constr on" << this << endl; }
    ~classDn() { cout << "\tClassDn destr on" << this << endl;}
    counter operator--()
    {
        return counter(--count);
    }
};


int main()
{
    classDn c;
    c++; c++; c++;
    cout << "Count: " << c.show() << endl;
    
    --c; --c;
    cout << "Count: " << c.show() << endl;

    classDn qwe = 5;
    c++;
    cout << "Count: " << c.show() << endl;

    return 0;
}