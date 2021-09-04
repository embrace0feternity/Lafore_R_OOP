#include <fstream>
#include <iostream>
#include <iterator>
#include <deque>
#include <algorithm>

int main()
{    
 
    std::deque<int> deq;
    // ifstream не требует команды infile.open(); fstream не работает с итераторами ввода/вывода.
    std::ifstream infile("base.txt", std::ios::in); // В файле сейчас [1; 7]. Открываю файл для чтения
    if (!infile.is_open()) { std::cerr << "File isn't created" << std::endl; exit(0); }
    
    // Входной итератор с входным потоком ffile
    std::istream_iterator<int> infile_iter(infile);
    // если создается входной итератор без параметров конструктора, то это итератор для указания окончания потока считывания
    std::istream_iterator<int> end_of_file;
    
    std::copy(infile_iter,end_of_file, front_inserter(deq)); // итератор начала потока, итератор окончания потока и 
    std::cin.clear();
    infile.close();
    
    std::cout << deq.size() << std::endl;
    for (int i=0; i<deq.size(); i++) std::cout << deq[i] << ' ';
    std::cout << std::endl;


    std::ofstream outfile("purpose.txt");
    std::ostream_iterator<int> fout_iter(outfile);
    std::copy(deq.begin(), deq.end(), fout_iter);
    
    return 0;
}