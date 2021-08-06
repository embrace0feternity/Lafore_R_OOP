#include <iostream>
#include <string.h>
using namespace std;

class person
{
    char *name;
public:
    person() { }
    person(const char *s) 
    { 
        int len = strlen(s);
        name = new char[len+1]; 
        strcpy(name,s);
    }
    void set() { cout << "Write a persons name: "; cin >> name; }
    void get()const { cout << "Name: " << name << endl; }
};


int main()
{
    int *pa;
    cin >> *pa;

    person *pPerson;
    pPerson->set();
    pPerson->set();

    person *prsn[100];
    int i=0;    char ch = 'a';
    do
    {
        prsn[i++] = new person("gofdk");
        prsn[i++]->set();
        cout << "Want one more time?? "; cin >> ch;
    } while (ch == 'y');
    for (int j=0; j<i; j++)  prsn[j]->get();
    return 0;

}