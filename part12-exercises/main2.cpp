/*
        Напишите программу, эмулирующую команду COPY. To есть 
    программа должна копировать содержимое одного файла в другой. Долж- 
    но использоваться два аргумента командной строки — исходный файл и 
    файл назначения. Например: 

        С:\>осору srcfile.cpp destfile.cpp 

    Осуществляйте проверку числа аргументов командной строки и возмож- 
    ность открытия указанных пользователем файлов. 

*/
#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char *argv[])
{
    std::cout << "argv[0] - " << argv[0] << "    argv[1] - " << argv[1] << std::endl;
    //std::cout << "argv[2] - " << argv[2] << std::endl;
    if (argc != 3)
    {
        std::cerr << "Неправильный ввод команды. Команда должна выглядить так:\n"
                << "\t\t\'name1 name2\'" << std::endl;
        exit(0);
    }
    std::ifstream infile(argv[2]);
    if (!infile.is_open())
    {
        std::cerr << "Невозможно открыть файл " << argv[2] << std::endl; exit(1);
    }
    std::ofstream outfile(argv[1]);
    if (!outfile.is_open())
    {
        std::cerr << "Невозможно открыть файл" << argv[1] << std::endl; exit(2);
    }
    char ch;
    while (true)
    {
        infile.get(ch);
        if (infile.eof()) break;
        outfile.put(ch);
    }
    std::cout << "Информация скопирована!" << std::endl;
    return 0;
}