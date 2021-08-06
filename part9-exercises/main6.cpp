#include <iostream>
using namespace std;

class safearray
{
protected:
    int size; int top, bot;
    int *arr;
public:
    safearray() : top(0), bot(0) { }
    safearray(int top, int bot): top(top), bot(bot)
    {
        size = (top>bot)? top-bot : bot-top;
        arr = new int[size];
    }
    ~safearray() { delete[] arr; }
    
};

class safehilo : public safearray
{
public:
    safehilo(): safearray() {}
    safehilo(int top, int bot): safearray(top,bot) {}
    int& operator[] (int pos);
};

int& safehilo::operator[] (int pos)
{
    if (pos < bot || pos > top-1) 
    {
        cout << "error" << endl;
        exit(0);
    }
    return arr[pos];
}
int main()
{
    cout << "Введите нижнюю и верхнюю границу массива: ";       int top, bot;         cin >> bot >> top;
    safehilo a(top,bot);       int pos, data;
    cout << "Введи позицию, куда вставлять, и число, которое вставлять: " << endl;    cin >> pos >> data;
    a[pos]=data;
    cout << a[pos] << endl;
    return 0;
}