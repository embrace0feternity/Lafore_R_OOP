#include <iostream>
using namespace std;

class safearray
{
    int size; int top, bot;
    int *arr;
public:
    safearray(int top, int bot): top(top), bot(bot)
    {
        size = (top>bot)? top-bot : bot-top;
        arr = new int[size];
    }
    ~safearray() { delete[] arr; }
    int& operator[] (int pos);
};
int& safearray::operator[] (int pos)
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
    safearray a(top,bot);       int pos, data;
    cout << "Введи позицию, куда вставлять, и число, которое вставлять: " << endl;    cin >> pos >> data;
    a[pos]=data;
    cout << a[pos] << endl;
    return 0;
}