#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v1(5); // Вектор на 5 ячеей, каждая из которой содержит 0.
    
    
    std::vector<int> v2; // Создание виктора
    v2.reserve(5); // Capacity = 5. Ячейки заполнены мусором.
    // v2 будет создан быстрее, чем v1. V1 будет еще заполнять ячейки (0 по умолчанию)    
    std::cout << "v1.size: " << v1.size() << "\tv2.size: " << v2.size() << std::endl;

    for (int i=0; i<10; i++) 
    {
        v1.push_back(i+1);
        v2.push_back(i+1);
    }
    for (int i=0; i<10; i++) 
    {
        std::cout << v1[i] << ' ' << v2[i] << std::endl;
    }

    std::cout << "v1.size: " << v1.size() << "\tv2.size: " << v2.size() << std::endl;
       
}