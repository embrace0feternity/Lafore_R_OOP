#include <iostream>
#include <array>
#include <string>
using std::endl;

const int SIZE = 4;
std::array<std::string,SIZE>name = { "Misrosoft", "Goodle", "Youtube", "Telegram" };

void fill(std::array<double, SIZE> &arr)
{
    for (int i = 0; i < SIZE; i++)
    {
        std::cout << "Введите расходны компании " << name[i] << ": ";
        std::cin >> arr[i];
    }
    
}

double show(std::array<double, SIZE> arr)
{
    std::cout << "РАСХОДЫ: " << endl;
    double sum = 0.0;
    for (int i = 0; i < SIZE; i++)
    {    
        std::cout << name[i] << ": " << arr[i] << " kk $" << endl;
        sum += arr[i];
    } 
    return sum;   
}

int main()
{
    std::array<double, SIZE>arr;
    fill(arr);
    std::cout << show(arr) << " kk $" << endl;
    return 0;
}