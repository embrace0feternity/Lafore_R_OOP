#include <iostream>

namespace iAverage
{
    int average(int a, int b)
    {
        return (a+b)/2;
    }
}

namespace dAverage
{
    double average(int a, int b)
    {
        double c = (a+b)/2.;
        return c;
    }
}

int main()
{
    std::cout << iAverage::average(3,4) << std::endl;
    std::cout << dAverage::average(3,4) << std::endl;
    return 0;
}

/*
6)
    10

    4
    0

    10 1

    10 -4

7)
    1
    
    4 1 2

    2

    2

    4 1 2 
    
    2
*/