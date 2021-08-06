#include <iostream>
using namespace std;

class safearr
{
    enum { SIZE = 20 };
    int arr[SIZE];
    int b;
public:
    safearr(): b(0) {}
    /*int& accept(int j)
    {
        if (j<0 && j>SIZE) 
        {
            cout << "Mistake" << endl;
            exit(0);
        }
        return arr[j]; 
    }*/
    int& operator[] (int i);
    int& getB()
    {
        return b;
    }
    void show()const{ cout << b << endl;}
};
int & safearr::operator[] (int i)
{
    if (i<0 && i> 20)
    {
        cout << "Out of range" << endl;
        exit(0);
    }
    return arr[i];
}


int main()
{
    safearr a;
    for (int i=0; i<20; i++) a[i]=i;
    for (int i=0; i<20; i++) 
    {
        cout << "Element " << i << " equals: " << a[i] << endl;
    }
    return 0;
}