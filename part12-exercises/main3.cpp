/*
        Напишите программу, возвращающую размер файла, указанного в команд- 
    ной строке:
    
    C:\>filesize 
*/
#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
    if (argc != 2) 
    {
        std::cerr << "Input error! You need to write \'main3.exe name_of_file\'" << std::endl;
    }
    std::ifstream infile;
    infile.open(argv[1]);
    infile.seekg(0, std::ios::end);
    std::cout << "File size - " << infile.tellg() << std::endl;
    return 0;
}
