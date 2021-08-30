#include <iostream>
#include <string>
#include <typeinfo>

namespace
{
    const int SIZE = 10;
}

class exceptions
{
public:
    std::string where;
    int what;
    exceptions(const std::string where, int index): where(where), what(index) {  }
};

template <typename T>
class safearray
{
private:
    T arr[SIZE];
public:
    T& operator[] (int index);
};

template <typename T>
T& safearray<T>::operator[] (int index)
{
    if (index < 0 | index > 10) throw exeptions("Выход за границы массива", index);

    return arr[index]; 
}

int main()
{
    safearray<int> irr;
    safearray<char> crr;

    try
    {
        for (int i=0; i<SIZE; i++) 
        {
            irr[i] = i*2;
            crr[i] = i + 'a';
        }
        irr[5] = -1;
        crr[57] = 'X';
        //irr[11] = -1;  // error
        //crr[32] = 'q';  //error 
        std::cout << "irr:\t\tcrr[i]" << std::endl;
        for (int i=0; i<SIZE; i++) std::cout << irr[i] << '\t' << crr[i] << std::endl;
        std::cout << std::endl;
    }
    catch(const exceptions& e) // catch all the exeptions
    {
        std::cerr << e.where << std::endl;
        std::cerr << "Вы пытались вызвать " << e.what << " индекс. А всего индексов - " << SIZE << std::endl;
    }
    return 0;
}