#include <iostream>
#include <algorithm>

bool isDone(std::string name)
{
    return name == "Masha";
}

std::string names[] = { "Vlad", "Egor", "Masha", "Sonya"};

int main()
{
    std::string *ptr;
    ptr = std::find_if(names,names+5, isDone);
    if (ptr == names+4)
        std::cout << "Masha isn't been in the list" << std::endl;
    {
        std::cout << "Masha is in the list" << std::endl;
        std::cout << "Her position is " << ptr - names << std::endl;
    }
}