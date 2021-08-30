#include <iostream>
#include <list>
#include <iterator>

int main()
{
    int arr[] = { 1, 3, 5, 4, 2 };
    std::list<int> l1 (arr, arr+5);

    std::list<int>::reverse_iterator r_iter; 
    for (r_iter = l1.rbegin(); r_iter != l1.rend(); r_iter++)
        std::cout << *r_iter << ' ';
    std::cout << std::endl;
    return 0;
}