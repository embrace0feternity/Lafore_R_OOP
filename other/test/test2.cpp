#include <iostream>

namespace
{
    const int SIZE = 5;
}

int comp(int a, int b)
{
    if (a>b) return 1;
    else return -1;
}

void sort(int *arr)
{
    int (*ptr)(int, int);
    ptr = comp;
    int temp;
    for (int i=0; i<SIZE; i++)
        for (int j=i+1; j<SIZE; j++)
            if (ptr(arr[i],arr[j]) > 0)
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
}

int main()
{
    int arr[SIZE] = { 6, -1, -8, 3, 7 };
    sort(arr);
    for (int i=0; i<SIZE; i++) std::cout << arr[i] << ' ';
    std::cout << std::endl;
}