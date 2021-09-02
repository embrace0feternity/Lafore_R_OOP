#include <iostream>
#include <algorithm>

class compare {
public:
    bool operator() (float &a, float &b) {
        return (a>b);
    }
};

int main()
{
    float arr[] = { 6.5, 6.9, 3, 12.4, 6.1 };
    std::sort(arr, arr+5, compare());
    for (int i=0; i<5; i++) std::cout << arr[i] << ' ';
    std::cout << std::endl;
    return 0;
}