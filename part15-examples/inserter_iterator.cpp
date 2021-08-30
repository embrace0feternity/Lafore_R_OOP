#include <iostream>
#include <algorithm>
#include <list>
#include <iterator>

int main()
{
    int arr[] = { 1, 3, 5, 7 };
    int brr[] = { 2, 4, 6, 8, 10, 12};
    std::list<int> l1 (arr, arr+4);
    std::list<int> l2 (brr, brr+4);

    std::copy(l2.begin(), l2.end(), std::back_inserter(l1));
    
    std::list<int>::iterator iter = l1.begin();
    while(iter!=l1.end()) 
        std::cout << *iter++ << ' ';
    std::cout << std::endl;
    

    return 0;
}