#include <iostream>
#include <string.h>
using namespace std;
class person
{
    string name;
public:
    person() { name[0]='\0'; }

    void set() { cout << "Write a persons name: "; cin >> name; }
    string get() { return name; } 
};


void sort(person **prsn, int n)
{
    for (int i=0; i<n; i++)
        for (int j=i+1; j<n; j++)
            if (prsn[i]->get() < prsn[j]->get())
            {
                person *temp = prsn[i];
                prsn[i] = prsn[j];
                prsn[j] = temp;
            }
}

void sort(person **prsn, int n);


int main()
{
    person **prsn;
    prsn = new person*[20];
    int i=0;    char ch = 'a';
    do
    {
        prsn[i] = new person;
        prsn[i++]->set();
        cout << "Want one more time?? "; cin >> ch;
    } while (ch == 'y');
    for (int j=0; j<i; j++)  
    {
        cout << "Name: " << j+1 << ": " << prsn[j]->get() << endl;
    }

    sort(prsn, i);
    cout << "Sort list:" << endl;

    for (int j=0; j<i; j++)  
    {
        cout << "Name: " << j+1 << ": " << prsn[j]->get() << endl;
    }

    return 0;
}