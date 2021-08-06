#include <iostream>
using namespace std;

class counter
{
private:
    int count;
public:
    counter(): count(0) {}
    int get()const { return count; }
    counter operator++() 
    {
        count++;
        return *this;
    }
    counter operator++(int)
    {
        count++;
        return *this;
    }
};

int main()
{   
    counter c1,c2;
    cout << "c1: " << c1.get() << endl;
    cout << "c2: " << c2.get() << endl;

    ++c1;
    ++c1;
    ++c2;
    cout << "После ++c: " << endl;
    cout << "c1: " << c1.get() << endl;
    cout << "c2: " << c2.get() << endl;

    c1 = ++c2;
    cout << "После c1 = ++c2: " << endl;
    cout << "c1: " << c1.get() << endl;
    cout << "c2: " << c2.get() << endl;

    c2++;
    c2++;
    cout << "После c2++ дважды: " << endl;
    cout << "c1: " << c1.get() << endl;
    cout << "c2: " << c2.get() << endl;
    return 0;
}