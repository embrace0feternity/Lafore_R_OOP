#include <iostream>
using namespace std;

class myclass
{
    int a;
    int b;
public:
    myclass(): a(0), b(0) {}
    myclass(int a, int b): a(a), b(b) {}
    void get()const { cout << a << ' ' << b << endl; }
    void take(int a, int b) { this->a = a; this->b = b; }  
};

int main()
{
    int a=1, b=2;
    myclass cl1[10];
    for (int i=0; i<10; i++)
    {
        cl1[i].take(1,2);
        cl1[i].get();
    }
    return 0;
}