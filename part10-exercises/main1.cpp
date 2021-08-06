/*
    --------------------------------Condition-------------------------------------
        Напишите программу, которая принимает числа от пользователя и помещает их в массив типa float.
    Программа должна посчитать ср. арефм. чисел. 
    
    Используйте указатели везде, где только возможно. 
*/

#include <iostream>
using namespace std;

int main(int argc,char **argv)
{
    cout << "Enter a size of array: ";  int size;   int *pSize = &size;   cin >> *(pSize);
    float *arr = new float[*pSize];
    cout << "Write array`s number:" << endl;

    int result = 0; int *pResult = &result;
    for (int i=0; i<*pSize; i++) 
    {
        cin >> *(arr+i);    
        *(pResult) += *(arr+i);
    }
    cout << "Mean value: " << *(pResult)/(*pSize) << endl;
    delete[] arr;
    return 0;
}