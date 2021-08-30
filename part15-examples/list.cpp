#include <iostream>
#include <list>

int main()
{
    int arr[] = { 8, 3, 5, 7, 1 };
    int brr[] = { 2, 4, 6, 8 };

    std::list<int> l1;
    for (int i=0; i<5; i++)
        l1.push_back(arr[i]);
    std::list<int> l2;
    for (int i=0; i<4; i++)
        l2.push_front(brr[i]);
    
    l1.reverse(); // Перевернуть список: 8 7 5 3 1
    l1.merge(l2); // Объединить l1 и l2 и результат поместить в l1
    
    // Удаляет повторяющиеся элементы в списке. Текущий элемент сравнивается с предыдущим и удаляется, если она равны
    l1.unique(); // удалилась 8

    while(!l1.empty())
    {
        std::cout << l1.front() << ' ';
        l1.pop_front();
    }
    std::cout << std::endl;
    return 0;
}