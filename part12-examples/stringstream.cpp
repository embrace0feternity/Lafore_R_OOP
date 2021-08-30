#include<iostream>
#include<sstream>

int main()
{
    std::stringstream str1;
    str1 << "Vlad Streha" << std::endl; // Ввод данных в буффер для хранения инфы
    std::string line1, line2; 
    str1 >> line1 >> line2; // Вывод инфы из буффера в объект line1
    std::cout << line1 << ' ' << line2 << std::endl;

    double d = 654.236;
    str1 << ' ' << d; // Записали в буффер число
    std::string line3;
    str1 >> line3; // Вывели числовую строку
    std::cout << line3 << std::endl;
    return 0;
}