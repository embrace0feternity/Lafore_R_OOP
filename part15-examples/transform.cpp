#include <iostream>
#include <algorithm>

double convert(double in) 
{
    return in/100.;
}

int main()
{
    double weight[] = { 121.2, 76.5, 613.7 };
    // transform работает как и for_each, но пользовательская ф-ия может модифицировать данные и помещать их в контейнер
    std::transform(weight, weight+3, weight, convert); 
    for (int i=0; i<3; i++) std::cout << weight[i] << ' ';
    std::cout << std::endl;
}