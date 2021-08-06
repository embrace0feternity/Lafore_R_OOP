#include <iostream>
#include <time.h>
#include <random>
using namespace std;

class myArray
{
    int **arr;
    int i,j;

    void setNull();
public:
    myArray(int i, int j): i(i), j(j) {
        arr = new int*[i];
        for (int k = 0; k < i; k++) *(arr+k) = new int[j];
        setNull();        
    }
    ~myArray() 
    { 
        for (int k = 0; k < i; k++) delete[] *(arr+k);
        delete[] arr;
    }
    void show()const;

    int& operator[] (int index);

};
void myArray::setNull()
{
    for (int k=0; k<i; k++)
        for (int p=0; p<j; p++) arr[k][p] = 0;
}
void myArray::show()const
{
    for (int k=0; k<i; k++)
    {
        for (int p = 0; p < j; p++) cout << arr[k][p] << ' ';
        cout << endl;
    }
}

int& myArray::operator[] (int index)
{
    if ((index > i*j || index < 0) ) 
        cout << "Out of range. Enter the index 0-" << i*j << '!' <<  endl;
    int __i = int(index/j);
    int __j = index % j;   
    return *(*(arr + __i) + __j);
}


int main()
{
    srand(time(0));
    int i, j;
    cout << "Write a number of lines: ";  cin >> i; 
    cout << "Write a number of collums: ";  cin >> j;

    myArray arr(i,j);
    for (int k=0; k < i*j; k++) 
        arr[k] = k*10;
    arr.show();
    return 0;
}