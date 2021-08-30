#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v_ini;
    for (int i=0; i<5; i++) v_ini.push_back(i+1);
    
    std::vector<int> v(v_ini.begin(), v_ini.end());
    for (int i=0; i<v.size(); i++) std::cout << v[i] << ' ';
    std::cout << std::endl;

    v.insert(v.begin()+3, 6); // Вставляю 6 в 3й элемент (считая с 0)
    for (int i=0; i<v.size(); i++) std::cout << v[i] << ' ';
    std::cout << std::endl;

    v.erase(v.begin()+3);   // Удаляю ранее вставленный элемент
    for (int i=0; i<v.size(); i++) std::cout << v[i] << ' ';
    std::cout << std::endl;
   
    return 0;
}