#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    char ch;
    int j;
    double d;
    string str1;
    string str2;

    //     Файл formato.txt уже создан в одноименной программе. Поэтому новый файл создаваться не будет    
    ifstream infile("formato.txt");

    /*
            Все последовательности символов приводятся к нужным типам.
    */
    infile >> ch >> j >> d >> str1 >> str2;

    cout << "Данные изъяты из файла:" << endl;
    cout << ch << endl
        << j << endl
        << d << endl
        << str1 << endl
        << str2 << endl;
    return 0;
}