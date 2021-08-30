#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

void test(std::list<int>::iterator iter)
{
    std::cout << "Test: " << *iter << std::endl;
}


int main()
{
    int arr[] = { 1, 3, 5, 4, 2 };
    std::list<int> l1;

    for (int i=0; i<5; i++)
        l1.push_back(arr[i]);

    std::list<int>::iterator iter; // двусторонний итератор 
    for (iter = l1.begin(); iter != l1.end(); iter++)
        std::cout << *iter << ' ';
    std::cout << std::endl;

    std::list<int> l2 (arr, arr+5);
    std::list<int>::iterator iter2;
    for (iter2 = l2.begin(); iter2 != l2.end(); iter2++)
    {
        *iter2 += 2;
        std::cout << *iter2 << ' ';
    }
    std::cout << std::endl;
    
    iter = std::find(l2.begin(), l2.end(), 6);
    std::cout << &iter << std::endl;
    test(iter);
    if (iter == l2.end()) std::cout << "Такого числа нет" << std::endl;
    else
        // Из-за того, что итератор двусторонний, в нему не применяются арифметические операции.
        std::cout << "Число 6 находится в позиции " << "N/A" << std::endl; 
    return 0;
}