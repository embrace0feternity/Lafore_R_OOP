#include <iostream>
#include <fstream>
#include <string.h>

const int N = 5;

class person
{
private:
    char name[20];
    int age;
public:
    void setData()
    {
        std::cout << "Write a name: "; std::cin.getline(name, 20); 
        std::cout << "How old is he/she: "; std::cin >> age;
    }
    void showData()
    {
        std::cout << "-------------------" << std::endl;
        std::cout << "Name: " << name << std::endl;
        std::cout << "Age: " << age << std::endl;
    }
};

int main()
{ 
    char ch; 
    person pers; 
    std::fstream file("Person.txt", std::ios::out | std::ios::in);

    if (file.is_open()) std::cout << "File is open!" << std::endl;

    int i=0;
    do 
    {
        std::cout << "Введите данные о человеке:" << std::endl; 
        pers.setData();
        file.write( reinterpret_cast<char*>(&pers), sizeof(pers)); 
        std::cout << "Продолжить ввод (у/n)? "; 
        std::cin >> ch;
        std::cin.ignore(1,'\n');
        i++;
    } while(ch == 'y'); 

    file.seekg(0); 
    i=0;
    while (!file.eof()) 
    { 
        std::cout << "Персона:"; 
        pers.showData();  
        file.read(reinterpret_cast<char*>(&pers), sizeof(pers)); 
        i++;
    } 
    file.close();
    std::cout << std::endl; 
    return 0;
} 
