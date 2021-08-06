#include <iostream>
#include <string>
const int SIZE = 5;

struct TwoSwapStruct
{
    std::string name;
    double salary;
    bool couple;
};


template<typename T>
void swap(T &a, T &b);
template <typename T>
void swap(T &a, T &b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}
template<> void swap<>(TwoSwapStruct &a, TwoSwapStruct &b);
template<> void swap<>(TwoSwapStruct &a, TwoSwapStruct &b)
{
    bool temp2;
    double temp1;

    temp2 = a.couple;
    a.couple = b.couple;
    b.couple = temp2;
    temp1 = a.salary;
    a.salary = b.salary;
    b.salary = temp1;
}

int main()
{
    double a = 3.0, b = 5.0;
    std::cout << "a = " << a << "  b = " << b << std::endl;
    std::cout << "---- Double swap ----" << std::endl;
    swap(a,b);
    std::cout << "a = " << a << "  b = " << b << std::endl;
    
    TwoSwapStruct person_1;
    person_1.name = "Vlad";
    person_1.salary = 66.6;
    person_1.couple = false;

    TwoSwapStruct person_2;
    person_2.name = "Mary";
    person_2.salary = 60;
    person_2.couple = true;

    swap(person_1, person_2);

    std::cout << "Name: " << person_1.name << "  Salary: " << person_1.salary 
        << "  Couple?: " << (person_1.couple? '+' : '-') << std::endl; 

    std::cout << "Name: " << person_2.name << "  Salary: " << person_2.salary 
        << "  Couple?: " << (person_2.couple? '+' : '-') << std::endl; 

    return 0;
}