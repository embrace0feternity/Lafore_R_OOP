#include <iostream>
#include <time.h>
#include <random>
#include <iomanip>


template <typename T>
T mean(T *arr, const int size)
{
    T result = 0;
    for (int i=0; i<size; i++) result += arr[i];
    return result / size;
}


template<>  // explicit template instantiation
char mean<char>(char *crr, int SIZE)
{
    const int LOWERCAST = 5; // number of lowercast letters (a - e)
    int temp[LOWERCAST]; 
    for (int i=0; i<LOWERCAST; i++) temp[i] = 0; 
    for (int i=0; i<SIZE; i++) temp[crr[i]-'a'] += 1;
    
    int max = 0;    int pos;
    for (int i=0; i<LOWERCAST; i++) 
        if (max < temp[i]) { max = temp[i]; pos = i; }
    return 'a'+ pos;
}

static char symbols[] = { 'a', 'b', 'c', 'd', 'e' };

int main()
{
    srand(time(0));

    const int SIZE = 10;
    int irr[SIZE];  double drr[SIZE];  char crr[SIZE+1];
    std::cout << "irr[i]\tdrr[i]\tcrr[i]" << std::endl;
    for (int i=0; i<SIZE; i++)
    {
        irr[i] = 1 + rand()%10;
        drr[i] = (rand()%1000+1.0)/100.0;
        int temp = rand()%5;    
        crr[i] = 97+temp; // fuel crr only with 'a'-'e'; 
        std::cout << std::setw(3) << irr[i] << std::setw(10) << drr[i] 
                << std::setw(17) << crr[i] << std::endl; 
    }
    std::cout << "Mean of an int array: " << mean(irr, SIZE) << std::endl
            << "Mean of a double array: " << mean(drr, SIZE) << std::endl
            << "The most often symbol in char array: " << mean(crr, SIZE) << std::endl;
    
    return 0;
}