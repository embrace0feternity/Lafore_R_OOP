#include <iostream>
#include <random>
#include <time.h>

class Array
{
private:
    int SIZE;
    int *arr;
public:
    Array(const int n): SIZE(n) { arr = new int[SIZE]; }
    Array(Array& other);
    
    ~Array() { delete[] arr;}

    int& operator[] (int i);
    Array& operator= (Array& other);
};
Array::Array(Array& other)
{
    SIZE = other.SIZE;
    arr = new int[SIZE];
    for (int i=0; i<SIZE; i++) arr[i] = other.arr[i];
}

int& Array::operator[] (int i)
{
    if (i<0 || i>SIZE) { std::cout << "Error! Out of range. Size of array equal " << SIZE << std::endl; 
        exit(0);
    }
    else    return arr[i];
}

Array& Array::operator= (Array& other)
{
    SIZE = other.SIZE;
    arr = new int[SIZE];
    for (int i=0; i<SIZE; i++) arr[i] = other.arr[i];
    return *this;
}


int main()
{
    srand(time(0));
    const int SIZE = 10;
    
// Create "arr". Array is filled with random figures;
    Array arr(SIZE);
    std::cout << "array \'Arr\':" << std::endl;
    for (int i=0; i<SIZE; i++)
    {
        arr[i] = (1+rand()%9);
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;

// Copy "arr" in "brr";
    Array brr(arr);
    std::cout << "array \'Brr\':" << std::endl;
    for (int i=0; i<SIZE; i++) std::cout << brr[i] << ' ';
    std::cout << std::endl;

// Copy "arr" in "brr"
    Array crr = arr;
    std::cout << "array \'Crr\':" << std::endl;
    for (int i=0; i<SIZE; i++) std::cout << crr[i] << ' ';
    std::cout << std::endl;

// Change figures of "crr". Now i have "crr" numbers from 10 to 20;
    std::cout << "array \'Crr\' (new):" << std::endl;
    for (int i=0; i<SIZE; i++)
    {
        crr[i] = 10 + rand()%11;
        std::cout << crr[i] << ' ';
    }
    std::cout << std::endl;

// use the overloaded operator= to equal "crr" to "arr" and "brr"
    std::cout << "array \'Arr\' and \'Brr\' (new):" << std::endl;
    arr = brr = crr;
    for (int i=0; i<SIZE; i++) std::cout << arr[i] << ' ' << brr[i] << std::endl;

    return 0;
}