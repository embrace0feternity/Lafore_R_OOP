#include <iostream>
#include <new>
#include <string>
using namespace std;


const int SIZE = 512;


class test{
private:
    string str;
    int a;
public:
    test(const string &str = "TEST", int n=0): str(str), a(n) { cout << str << " constucted\n"; }
    ~test() { cout << str <<  " destroyed\n" << this << endl; }
    void show()const { cout << str << " " << a << endl << endl; }
};


int main()
{
    char *buff = new char[SIZE];
    test *obj1, *obj2;
    obj1 = new(buff) test;
    obj2 = new test("Vlad", 10);
    cout << "Memory block addresses:\n" << "buffer: " << static_cast<void *>(buff) << "\t\theap: " << obj2;
    cout << endl << endl;
    cout << "obj1: "; obj1->show();
    cout << "\nobj2: "; obj2->show();

    test *obj3, *obj4;
    obj3 = new(buff+sizeof(test)) test;
    obj4 = new test("Masha", 20);

    cout << "Memory block addresses:\n" << "buffer: " << static_cast<void *>(buff) << "\t\theap: " << obj4;
    cout << endl << endl;
    cout << "obj1: "; obj3->show();
    cout << "\nobj2: "; obj4->show();

    cout << static_cast<void*>(buff) << ' ' << obj1 << ' ' << obj3 << endl;
    obj1->~test();
    obj3->~test();
    delete obj2;
    delete obj4;
    delete[]buff;
    
    return 0;    
}