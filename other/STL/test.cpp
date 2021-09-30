#include <iostream>
using namespace std;

void *operator new(size_t size, char *p)
{
    return static_cast<void *>(p);
}

void *operator new(size_t size)
{
    void *t = malloc(size);
    return t;
}


void operator delete(void *p)
{
    ::operator delete(p);
}

class test{
    int value = 0;
public:
    test() { cout << "create" << endl; }
    test(int v): value(v) { cout << "create value" << endl; }
    
    ~test() { cout << "delete" << endl;}
};

char buff[512];

int main()
{
    test *t1 = new(buff) test(12);
    cout << static_cast<void *>(buff) << ' ' << t1 << endl;

    test *t2 = new test(24);
    cout << static_cast<void *>(buff) << ' ' << t2 << endl;

    return 0;
}