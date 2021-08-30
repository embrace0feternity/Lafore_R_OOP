#include <iostream>
#include <algorithm>

void convert(double in) 
{
    std::cout << in << ' ';
}

int main()
{
    double weight[] = { 121.2, 76.5, 613.7 };
    // Ф-ия не должна модифицировать данные. Она может их выводить или использовать значения в своей работе
    std::for_each(weight, weight+3, convert); 
    std::cout << std::endl;
}