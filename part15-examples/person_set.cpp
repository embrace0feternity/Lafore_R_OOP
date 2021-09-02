#include <iostream>
#include <set>
#include <string>

class person
{
    std::string fname;
    std::string sname;
    unsigned int phoneNumber;
public:
    person(): fname("N/A"), sname("N/A"), phoneNumber(0) { }
    person(std::string f, std::string s, unsigned int pN): fname(f), sname(s), phoneNumber(pN) { }

    friend bool operator < (const person &, const person &);
    friend bool operator == (const person &, const person &);
    friend std::ostream& operator << (std::ostream &, const person &);
};

bool operator < (const person &p1, const person &p2)
{
    if(p1.sname == p2.sname) return (p1.fname < p2.fname)? true : false;
    return (p1.sname < p2.sname)? true:false;
}

bool operator == (const person &p1, const person &p2)
{
    return (p1.fname == p2.fname && p1.sname == p2.sname)? true : false;
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
    multiset<person> persSet;
    
    persSet.insert(p1);
    persSet.insert(p2);
    persSet.insert(p3);
    persSet.insert(p4);
    persSet.insert(p5);
    persSet.insert(p6);
    persSet.insert(p7);
    persSet.insert(p8);
    persSet.insert(p9);

    cout << "Number of persons: " << persSet.size() << endl;

    for (const auto &iter : persSet) cout << iter << endl;
    
    cout << "Write a name: " << endl;
    string fname, sname;
    cin >> fname;
    cin >> sname;

    person searchPerson(fname, sname, 0);
    int countPerson = persSet.count(searchPerson);
    cout << "The number of person with this name - " << countPerson << std::endl; 
    
    multiset<person>::iterator iter;
    iter = persSet.lower_bound(searchPerson);
    while(iter != persSet.upper_bound(searchPerson))
    {
        cout << *iter++ << endl;
    }
     return 0;
}

