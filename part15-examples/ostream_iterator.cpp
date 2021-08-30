#include <iostream>
#include <algorithm>
#include <list>
#include <iterator>

#include <fstream>

int main()
{
    int arr[] = { 1, 3, 5, 7 };
    std::list<int> l1(arr, arr+4);
    
    // Выходной итератор. Конструктор имеет 2 аргумента: поток, куда выводить данные, и строка, которая идет после каждого
    // из записанных данных 
    std::ostream_iterator<int> out_iter(std::cout, ". ");

    std::cout << "Содержимое списка:" << std::endl;
    std::copy(l1.begin(), l1.end(), out_iter); // Копируем список в поток.
    std::cout << std::endl; 

    // Создаю файл, куда будут записаны данные. Данные будут записаны не в двоичном виде, даже если
    // указать ::binary. Данные записываются посимвольно
    std::ofstream outfile("ostream_iterator.dat", std::ios::out);
    std::ostream_iterator<int> fout_iter(outfile);

    std::copy(l1.begin(),l1.end(),fout_iter);
    return 0;
}