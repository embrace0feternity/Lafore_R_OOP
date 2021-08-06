#include <iostream>
using namespace std;

class Int
{
    int field;
public:
    Int(void): field(0) {}
    Int(int arg): field(arg) {}

    Int operator+ (Int &other) { return Int(field + other.field); }
    Int operator- (Int &other) { return Int(field - other.field); }
    Int operator* (Int &other) { return Int(field * other.field); }
    Int operator/ (Int &other) { return Int(field / other.field); }
    void show()const { cout << field << endl; }
};

int main()
{
    Int a=2,b=6;
    Int c = a + b;
    cout << endl << "a + b = "; c.show();
    c = a - b;
    cout << endl << "a - b = "; c.show();
    c = a * b;
    cout << endl << "a * b = "; c.show();
    c = a / b;
    cout << endl << "a / b = "; c.show();

    return 0;
}
