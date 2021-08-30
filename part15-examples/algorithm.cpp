#include <iostream>
#include <algorithm>

int main()
{
    int arr[] = { 1, 36, 2, 45, 2, 6, 16, 97 };
    int a = 2;
    int *ptr;
    // std::find ----------------------------------------------
    ptr = std::find(arr, arr+8, a);
    std::cout << "Позиция искомого элемента: " << ptr-arr << std::endl;

    // std::count ---------------------------------------------
    int n = std::count(arr, arr+8, a);
    std::cout << "Число " << a << " встречается в контейнере " << n << " раз(а)" << std::endl;
    
    // std::search --------------------------------------------
    int small_arr[] = {36, 2, 4};
    std::cout << arr+8 << std::endl;
    ptr = std::search(arr, arr+8, small_arr, small_arr+3);
    if (ptr == arr+8) std::cout << "Нет искомой последовательности" << std::endl; 
        else
    std::cout << "Позиция искомой последовательности в контейнере arr: " << ptr-arr << std::endl;
    
    // std::merge ---------------------------------------------
    int new_arr[11];
    std::merge(arr, arr+8, small_arr, small_arr+3, new_arr);
    for (int i=0; i<11; i++) std::cout << new_arr[i] << ' ';
    std::cout << std::endl;
    return 0;
}