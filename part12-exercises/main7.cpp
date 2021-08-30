#include <iostream>
#include <fstream>
#include <string.h>
#include <conio.h>

class user
{
private:
    char name[30];
    static std::fstream ffile;
public:
    user() { }
    user(char *s);

    void showData()const { std::cout << "Имя - " << name << std::endl;}
    static void openFile();
    static void closeFile() { ffile.close(); std::cout << "File is close!" << std::endl; }
    static void pointer() { ffile.seekg(0);}
    void write();
    bool read();
};
std::fstream user::ffile;

user::user(char *s)
{
    strcpy(name, s);
    name[strlen(s)] = '\0';
}
void user::openFile()
{
    ffile.open("main7_user.txt", std::ios::binary | std::ios::out | std::ios::in | std::ios::app);
    if (!ffile.is_open())
    {
        std::cerr << "Creating/opening error!" << std::endl;
        exit(1);
    }   else std::cout << "File is open!" << std::endl;
}

void user::write()
{
    ffile.write(reinterpret_cast<char*>(this),sizeof(user));
}

bool user::read()
{
    std::cout << "cur -  " << ffile.tellg() << std::endl; 
    ffile.read(reinterpret_cast<char*>(this),sizeof(user));
    if (!ffile.eof()) 
    {
        showData();
        return true;
    }        else return false; 
}


int main()
{
    user *usr[10];
    char ch = 'a';  int i;
    char name[30];
    while(ch != 'q')
    {
        i = 0;
        std::cout << "Write (w) or read (r)?? ";
        std::cin >> ch;
        if (ch == 'w')
        {
            user::openFile();
            while (ch != 'n')
            {
                std::cin.ignore(1,'\n');
                std::cout << "Write a name - "; 
                std::cin.getline(name, 30);
                usr[i] = new user(name);
                usr[i]->write();
                usr[i++]->showData();
                std::cout << "continue? y or n" << std::endl;
                std::cin >> ch;
            }
            user::closeFile();
            for (int j=0; j<i; j++) delete usr[j];
        }
        else if (ch == 'r')
        {
            user::openFile();
            user::pointer();
            while (true)
            {
                usr[i] = new user;
                if(!usr[i++]->read())
                {
                    std::cout << i-1 << " objects were read" << std::endl;
                    break;
                }
            }
            user::closeFile();
            for (int j=0; j<i; j++) delete usr[j];
        }
        else break;
    }
    return 0;
}