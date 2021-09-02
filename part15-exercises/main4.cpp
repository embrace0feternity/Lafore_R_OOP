#include <iostream>
#include <set>
#include <string>


class person
{
private:
    std::string name;
    char sex;
public:
    person(const std::string n, char s): name(n), sex(s) { }

    friend bool operator < (const person &p1, const person &p2);
    friend std::ostream& operator << (std::ostream &out, const person &p);
};

bool operator < (const person &p1, const person &p2){
    return (p1.name < p2.name);
}

std::ostream& operator << (std::ostream &out, const person &p){
    out << p.name << ' ' << p.sex;
    return out;
}

class compare
{
public:
    bool operator()(const person* p1, const person* p2){
        return (*p1 < *p2);
    }
};

int main()
{
    using namespace std;
    person *prsn[100];
    multiset<person*, compare> mPerson;
    multiset<person*, compare>::iterator iter;

    std::string name;
    char c = 'a';   int i=-1;
    while(c != 'n')
    {
        std::cout << "Write a name: "; std::cin >> name;
        std::cout << "Write his/her sex: "; std::cin >> c; 
        prsn[++i] = new person(name, c);
        std::cout << "Продолжить? (y) / (n)" << std::endl;
        cin >> c;
    }
    for (int j=0; j<=i; j++) mPerson.insert(prsn[j]);

    for (auto iter = mPerson.begin(); iter != mPerson.end(); ++iter)
    {
        cout << **iter << endl;
    }

    iter = mPerson.begin();
    while(iter != mPerson.end())
    {
        delete *iter;
        mPerson.erase(iter++);
    }

    return 0;
}