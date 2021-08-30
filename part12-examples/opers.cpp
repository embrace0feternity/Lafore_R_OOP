#include <iostream>
#include <fstream>
#include <string.h>

class person
{
private:
    //std::string name;
    int age;
public:
    person() { }
    void setData()
    {
        //std::cout << "Имя человека: "; getline(std::cin, name);
        std::cout << "Возраст человека: "; std::cin >> age;
    }
    void showData()
    {
       // std::cout << "Имя: " << name << std::endl;
        std::cout << "Возраст: " << age << std::endl;
    }
};

int main()
{
    person pers;
    pers.setData();
    std::ofstream outfile("edata.dat", std::ios::binary);
    outfile.write(reinterpret_cast<char*>(&pers), sizeof(pers));
    outfile.close();

    // std::ifstream infile("edata.txt", std::ios::binary);
    // infile.read(reinterpret_cast<char*>(&pers), sizeof(pers));
    // infile.close();
    // pers.showData();

    return 0;
}