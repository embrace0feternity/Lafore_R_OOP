#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    const int MAX = 80; // размер буфера для getline
    char buff[MAX]; // Строка, полученная из файла
    ifstream infile("song.txt");
    while(!infile.good()) // Пока не дойдем до конца файла
    {
        infile.getline(buff, MAX); // читаем строки
        cout << buff << endl; 
    }
    return 0;
}