#include <iostream>
#include <algorithm>
#include <list>
#include <iterator>

#include <fstream>

int main()
{
    using namespace std;
    list<int> l1(5);
    cout << "Введите 5 чисел типа float" << std::endl;
    istream_iterator<int> cin_iter(std::cin);
    
    // особая роль такого итератора. Конструктор по умолчанию создает объект для указания завершения потока
    istream_iterator<int> end_of_stream;

    copy(cin_iter, end_of_stream, l1.begin());
    cin.clear();
    list<int>::iterator iter;
    for (iter = l1.begin(); iter != l1.end(); iter++)
        std::cout << *iter << ' ';
    cout << std::endl;

    list<int> l2;
    ifstream infile("ostream_iterator.dat");
    istream_iterator<int> infile_iter(infile);
    istream_iterator<int> end_of_file;
    copy(infile_iter, end_of_file, back_inserter(l2));
    cin.clear();
    for (auto iter = l2.begin(); iter != l2.end(); iter++)
        cout << *iter << endl;
    return 0;
}