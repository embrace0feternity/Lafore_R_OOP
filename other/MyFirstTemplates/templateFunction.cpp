#include <iostream>

template<typename T>
void swap(T &a, T &b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}

int main()
{
    int a, b;
    std::cout << "Write \'a\' and \'b\' (int): "; std::cin >> a >> b;
    std::cout << "---- Int swaping ---- " << std::endl;
    swap(a,b);
    std::cout << "a = " << a << "  b = " << b << std::endl; 
    
    double c, d;
    std::cout << "Write \'a\' and \'b\' (double): "; std::cin >> c >> d;
    std::cout << "---- Double swaping ---- " << std::endl;
    swap(c,d);
    std::cout << "c = " << c << "  d = " << d << std::endl;
    return 0;
}