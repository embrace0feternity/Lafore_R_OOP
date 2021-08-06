#include <iostream>
using namespace std;

class foo
{
private:
    static int count;
public:
    foo()   {   count++;    }
    int get()   {   return count;   }
    void change_static(int n);
};
int foo::count = 0;

void foo::change_static(int n)
{
    count += n;
}

int main()
{
    foo f1,f2,f3;
    cout << "f1:  " << f1.get() << endl;
    cout << "f2:  " << f2.get() << endl;
    cout << "f3:  " << f3.get() << endl;


    f1.change_static(1);            cout << "f1:  " << f1.get() << endl;      
    f2.change_static(6);            cout << "f2:  " << f2.get() << endl;
    f3.change_static(-4);            cout << "f3:  " << f3.get() << endl;        
}