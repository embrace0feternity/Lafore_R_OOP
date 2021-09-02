#include <iostream>
#include <list>
#include <string>
#include <algorithm>

class person
{
    std::string fname;
    std::string sname;
    unsigned int phoneNumber;
public:
    person(): fname("N/A"), sname("N/A"), phoneNumber(0) { }
    person(std::string f, std::string s, unsigned int pN): fname(f), sname(s), phoneNumber(pN) { }

    unsigned int getphone() { return phoneNumber; }

    friend bool operator < (const person &, const person &);
    friend bool operator > (const person &, const person &);
    friend bool operator == (const person &, const person &);
    friend bool operator != (const person &, const person &);
    friend std::ostream& operator << (std::ostream &, const person &);
};

bool operator < (const person &p1, const person &p2)
{
    if(p1.sname == p2.sname) return (p1.fname < p2.fname)? true : false;
    return (p1.sname < p2.sname)? true:false;
}

bool operator > (const person &p1, const person &p2)
{
    if(p1.sname == p2.sname) return (p1.fname > p2.fname)? true : false;
    return (p1.sname > p2.sname)? true:false;
}

bool operator == (const person &p1, const person &p2)
{
    return (p1.fname == p2.fname && p1.sname == p2.sname)? true : false;
}

bool operator != (const person &p1, const person &p2)
{
    return (p1.fname == p2.fname && p1.sname == p2.sname)? false : true;
}

std::ostream& operator << (std::ostream &out, const person &p)
{
    out << p.sname << ' ' << p.fname << ' ' << p.phoneNumber;
    return out;
}

int main()
{
    using namespace std;
    // Create persons
    person p1("Vlad", "Streha", 1111111);
    person p2("Masha", "Yankina", 2222222);
    person p3("Egor", "Grinuak", 3333333);
    person p4("Veronika", "Zakrevskaya", 44444444);
    person p5("Sonya", "Belko", 5555555);
    person p6("Katya", "Otchik", 6666666);
    person p7("Vlad", "Aleinikov", 7777777);
    person p8("Pasha", "Pyasetskii", 8888888);
    person p9("Masha", "Yankina", 99999999);
    
    // create multiset
    list<person> l;

    l.push_back(p1);
    l.push_back(p2);
    l.push_back(p3);
    l.push_back(p4);
    l.push_back(p5);
    l.push_back(p6);
    l.push_back(p7);
    l.push_back(p8);
    l.push_back(p9);

    cout << "Number of persons: " << l.size() << endl;

    for (const auto &iter : l) cout << iter << endl;
    
    cout << "Write a name: " << endl;
    string fname, sname;
    cin >> fname;
    cin >> sname;

    person searchPerson(fname, sname, 0);
    
    auto iter = find(l.begin(), l.end(), searchPerson);
    
    if (iter != l.end())
    {
        cout << "This person has been found" << std::endl;
        do
        {
            cout << *iter << endl;
            ++iter;
            iter = find(iter, l.end(), searchPerson);
        } while (iter != l.end());        
    }
    else cout << "This person hasn't been found" << std::endl;

    
    cout << "Write phoneNumber" << std::endl;
    unsigned int number; cin >> number;
    bool found = false;

    for (auto iter = l.begin(); iter != l.end(); ++iter)
    {
        if ((*iter).getphone() == number)
        {
            if (!found) 
            {
                cout << "The person with this phone number has been found" << endl;
                found = true;
            }
            cout << *iter << endl;
        }
    }
    if (!found) cout << "The person with this phone number hasn't been found" << endl;
    return 0;
}

