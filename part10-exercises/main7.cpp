#include <iostream>
#include <string.h>
using namespace std;


class person
{
    string name;
    float salary;
public:
    person(): salary(0.0) { name[0]='\0'; }

    void setData() { cout << "Write a persons name: "; cin >> name;
        cout << "Write his/her salary: "; cin >> salary;     }
    
    float getSalary()const { return salary; }

    void show() { cout << "Name: " << name << "\t\tSalary: " << salary << endl; }
};

void salSort(person **prsn, int n)
{
    person *buff;
    for (int i=0; i<n; i++)
        for (int j=i+1; j<n; j++)
            if ((*(prsn+i))->getSalary() > (*(prsn+j))->getSalary())
            {
                buff = *(prsn+i);
                *(prsn+i) = *(prsn+j);
                *(prsn+j) = buff;
            }
}

void qSort(person **prsn, int first, int last)
{
    int i = first, j = last;
    int mid = (first + last)/2;
    person *temp;
    cout << mid << endl;
    while (i <= j)
    {
        while (prsn[i]->getSalary() < prsn[mid]->getSalary()) ++i;
        while (prsn[j]->getSalary() > prsn[mid]->getSalary()) --j;
        cout << "prsn[j]: " << prsn[j]->getSalary() << "   prsn[i]: " << prsn[i]->getSalary() << endl;
        if (i <= j)
        {
            temp = prsn[i];
            prsn[i] = prsn[j];
            prsn[j] = temp;
            i++;            j--;
        }
    }
    if (i < last) qSort(prsn,i,last);
    if (j > first) qSort(prsn,first,j);
}


int main()
{
    person **prsn;
    prsn = new person*[20];
    int i=0;    char ch = 'a';
    do
    {
        prsn[i] = new person;
        prsn[i++]->setData();
        cout << "Want one more time?? "; cin >> ch;
    } while (ch == 'y');
    for (int j=0; j<i; j++)  
    {
        cout << "---------------------------- " << j+1 << " ------------------------------" << endl;
        prsn[j]->show();
    }

    //salSort(prsn, i);
    int first = 0;
    int last = i - 1;
    qSort(prsn, first, last);
    cout << endl <<"Sort list:" << endl << endl;

    for (int j=0; j<i; j++)  
    {
        cout << "---------------------------- " << j+1 << " ------------------------------" << endl;
        prsn[j]->show();
    }

    return 0;
}

/*

Vlad
66.6
y
Vika
33.3
y
Max
45
y
Brane
18.54
y
Zak
34.8
n

*/