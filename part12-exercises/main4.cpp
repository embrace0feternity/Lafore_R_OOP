/*
        В цикле запрашивайте у пользователя данные, состоящие из имени, отчест- 
    ва, фамилии и номера работника (типа unsigned long). Затем осуществите 
    форматированный вывод в объект ofstream с помощью оператора вставки 
    («). Не забывайте, что строки данных должны оканчиваться пробелами 
    или другими разделителями. Когда пользователь сообщит об окончании 
    ввода, закройте объект ofstream, откройте объект ifstream, прочитайте и вы- 
    ведите на экран все данные из файла, после чего завершите программу. 
*/

#include<iostream>
#include<fstream>
#include<string.h>
#include<conio.h>

class user
{
private:
    std::string fname;
    std::string sname;
    std::string addname;
public:
    unsigned long number;
    
    user() { fname = sname = addname = "N/A";   number = 0; }
    void setData(); 
    void showData()const;
    friend std::ofstream& operator << (std::ofstream &, user &);
    friend std::ifstream& operator >> (std::ifstream &, user &);
};

void user::setData()
{
    std::cout << "Введите имя - "; std::getline(std::cin, fname);
    std::cout << "Введите фамилию - "; std::getline(std::cin, sname);
    std::cout << "Введите отчество - "; std::getline(std::cin, addname);
    std::cout << "Номер - "; std::cin >> number;
}

void user::showData()const
{
    std::cout << "-----------------" << std::endl;
    std::cout << "Имя - " << fname << std::endl;
    std::cout << "Фамилия - " << sname << std::endl;
    std::cout << "Отчество - " << addname << std::endl;
    std::cout << "Номер - " << number << std::endl;
}

std::ofstream& operator << (std::ofstream &out, user &other)
{
    out << other.number << other.fname << ' ' << other.sname << ' ' << other.addname << ' ' << std::endl;
    return out;
}

std::ifstream& operator >> (std::ifstream &in, user &other)
{
    in >> other.fname >> other.sname >> other.addname;
    return in;
}


int main()
{
    user *usr[100];
    char ch;
    std::cout << "Читать (r) или вводить(w)? "; std::cin >> ch;
    int i;
    if (ch == 'w')
    {
        std::ofstream outfile("main4_user.txt");
        i=0;
        while(ch != 'n')
        {
            std::cin.ignore(1,'\n');
            usr[i] = new user;
            usr[i]->setData();
            outfile << *(usr[i]);
            std::cout << "Введите \'y\' для продолжения записи или \'n\' для прекращения" << std::endl;
            std::cin >> ch;
            i++;
        } 
        
    }
    else if (ch == 'r')
    {
        i=0;
        std::ifstream infile("main4_user.txt");
        while(true)
        {
            int num;
            infile >> num;
            if (infile.eof()) break;
            usr[i] = new user;
            infile >> *(usr[i]);
            usr[i]->number = num;
            usr[i]->showData();
            i++;
        }
    }
    return 0;
}