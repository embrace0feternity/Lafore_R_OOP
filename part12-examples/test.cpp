#include <fstream>
#include <iostream>

class person
{
private:
    enum { SIZE = 20 };
    char name[SIZE];
    short age;
public:
    person(): age(0) {  }
    void setData()
    {
        std::cout << "Введите имя пользователя - "; std::cin.getline(name, SIZE);
        std::cout << "Введите возраст - "; std::cin >> age;
        std::cin.ignore(1, '\n');
    }
    void showData()
    {
        for (int i=0; i<50; i++) std::cout << '-';
        std::cout << "\nИмя пользователя - " << name << std::endl;
        std::cout << "Возраст - " << age << std::endl;
    }
    char* getName() { return name; }
    ~person() {  }
};


using namespace std;

int main()
{
    person prsn[100];
    ifstream infile("findperson_v2.txt", ios::binary);
    int i = 0;
    while(true)
    {
        infile.read(reinterpret_cast<char*>(prsn+i), sizeof(*(prsn+i)));
        if (infile.eof())
        {
            cout << "Конец" << endl;
            break; 
        }
        prsn[i++].showData();
    }
    return 0;
}