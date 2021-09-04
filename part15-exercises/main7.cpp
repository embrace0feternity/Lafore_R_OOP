#include <iostream>
#include <list>
#include <string>
#include <numeric> // для accumulate

// Задача - использовать функцию accumulate с 3мя параметрами

class tax
{
    double month_debt;
    long double year_debt;
public:
    tax(): month_debt(0.0), year_debt(0.0) { }
    tax(double m, long double y): month_debt(m), year_debt(y) { }
    ~tax() { }
    void set() {
        std::cin >> month_debt >> year_debt;
    }
    tax operator + (const tax &other);
    friend std::ostream& operator << (std::ostream &out, const tax &other);
};

tax tax::operator + (const tax &other)
{
    double m = month_debt + other.month_debt;
    long double y = year_debt + other.year_debt;
    return tax(m, y);
}


std::ostream& operator << (std::ostream &out, const tax &other)
{
    out << other.month_debt <<"$\t" << other.year_debt << "$тыс."; 
    return out;
}

int main()
{
    tax* debt[100];
    char ch = 'a'; int i=0;
    std::list<tax> lst;
    std::cout << "Укажите сумму долга за месяц и за год" << std::endl;
    while(ch != 'n')
    {
        debt[i] = new tax;
        debt[i]->set();
        lst.push_back(*(debt[i]));
        std::cout << "Продолжить? y or n" << std::endl;
        std::cin >> ch;
        i++;
    }
    tax sum;
    sum = std::accumulate(lst.begin(), lst.end(), tax());
    std::cout << sum << std::endl;
    return 0;
}
