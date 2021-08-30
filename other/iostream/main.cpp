#include <iostream>

class Fraction
{
private:
    std::string name;
    int members; // how many
    double account; // how much money does organization have
public:
    Fraction(): members(0), account(0.0) { name = "N/A"; }
    Fraction(const std::string n, const int m, const double a): name(n), members(m), account(a) { }
    // how much money has each person invested
    double money() { members = static_cast<double>(members);  return account/members; } 
    friend std::ostream& operator<< (std::ostream &out, Fraction& fr);
    friend std::istream& operator>> (std::istream &in, Fraction& fr); 
};

std::ostream& operator<< (std::ostream &out, Fraction& fr)
{
    out << "Name: " << fr.name << "\nMembers: " << fr.members << "\nAccount: " << fr.account;
    return out;
}

std::istream& operator>> (std::istream &in, Fraction& fr)
{
    in >> fr.name;  in >> fr.members;  in >> fr.account;
    return in;
}

int main()
{
    Fraction fr1;
    std::cout << fr1 << std::endl;

    std::cout << "Write info about fraction" << std::endl;
    std::cin >> fr1;
    std::cout << fr1 << std::endl;

    Fraction fr2("Ballas", 450, 125320.5);
    std::cout << fr2 << std::endl;
    
    return 0;
}