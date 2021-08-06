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
    counter operator++ (int) // постфикс ++
    {
        count++;
        return counter(count);
    }
};

class classDn : public counter
{
public:
    classDn(): counter () { cout << "\tClassDn constr on" << this << endl; }
    classDn(int n): counter (n) { cout << "\tClassDn constr on" << this << endl; }
    ~classDn() { cout << "\tClassDn destr on" << this << endl;}
    classDn operator-- () // префикс --
    {
        return classDn(--count);
    }
    classDn operator-- (int) // постфикс ++
    {
        return classDn(count--);
    }
    classDn operator++ ()
    {
        return classDn(count++);
    }
    classDn operator++ (int)
    {
        return classDn(count++);
    }
};


int main()
{
    classDn c;
    cout << "Count: " << c.show() << endl;
    c++; ++c;
    cout << "Count: " << c.show() << endl;

    c--; --c;
    cout << "Count: " << c.show() << endl;

    return 0;
}