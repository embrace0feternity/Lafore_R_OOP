#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


int main()
{
    std::string str[] = { "qwerty", "kek", "lol", "papich" };
    for (const auto &i : str) std::cout << i << std::endl;
    std::cout << std::endl;
    std::string searchStr;
    std::cout << "Ввод строки: ";     std::cin >> searchStr;
    
    std::string *ptr;
    ptr = find_if(str, str+4, std::bind2nd(std::equal_to<std::string>(), searchStr));
    if (ptr == str+4) 
    {
        std::cerr << "Нет такой строки" << std::endl;
        exit(0);
    }       else
    std::cout << ptr-str << " позиция слова " << *ptr << std::endl;
    return 0;
}   