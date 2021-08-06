#include <iostream>

const int SIZE = 5;

template<typename T>
void swap(T &a, T &b);

template<typename T>
void swap(T *a, T *b);

template <typename T>
void swap(T &a, T &b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}

template<typename T>
void swap(T *a, T *b)
{
    T temp;
    for (int i=0; i<SIZE; i++)
    {
        temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
}


int main()
{
    double a = 3.0, b = 5.0;
    std::cout << "a = " << a << "  b = " << b << std::endl;
    std::cout << "---- Double swap ----" << std::endl;
    swap(a,b);
    std::cout << "a = " << a << "  b = " << b << std::endl;
    

    double arr[SIZE] = { 1.4, 5.6, 1.9, 43.2, 0.4 };
    double brr[SIZE] = { 3.3, 0.0, 7.6, 2.1, 29.5 };
    std::cout << "---- Double arrays swap ----" << std::endl;
    swap(arr,brr);
    std::cout << "arr: " << " brr:" << std::endl;
    for (int i=0; i<SIZE; i++)
    {
        std::cout << arr[i] << "  " << brr[i] << std::endl;
    }
    return 0;
}