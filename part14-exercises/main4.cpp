#include <iostream>

class Name
{
    std::string name;
public:
    Name(const std::string n): name(n) { }
    friend std::ostream& operator << (std::ostream &, Name &);
};

std::ostream& operator << (std::ostream &out, Name &other)
{
    out << other.name;
    return out;
}

template <typename T>
void swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

int main()
{
    int a = 3, b = 7;
    swap(a,b);
    std::cout << "a - " << a << "\tb - " << b << std::endl; 

    char c = 'c', d = 'd';
    swap(c,d);
    std::cout << "c - " << c << "\td - " << d << std::endl;
    
    Name man("Vlad"), girl("Masha");
    swap(man,girl);
    std::cout << "man - " << man << "\tgirl - " << girl << std::endl;
    return 0;
}