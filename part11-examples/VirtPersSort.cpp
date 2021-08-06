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
    void show() { cout << "Name: " << name << "\t\tSalary: " << salary << endl; }
    float getSalary() { return salary; }
    virtual void setnewData()=0;
    virtual bool isOutstanding()=0;
};

class student   :   public person
{
private:
    float meanNote;
public:
    student(): person() { }
    void setnewData()
    {
        person::setData();
        cout << "Write his/her mean note: "; cin >> meanNote;
    }
    bool isOutstanding() { return (meanNote > 9)? true : false; } 
};


class professor   :   public person
{
private:
    int publication;
public:
    professor(): person() { }   
    void setnewData()
    {
        person::setData();
        cout << "How many articles does he/she has?: "; cin >> publication;
    }
    bool isOutstanding() { return (publication > 80)? true : false; } 
};


void Sort(person **prsn, int first, int last)
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
    if (i < last) Sort(prsn,i,last);
    if (j > first) Sort(prsn,first,j);
}


int main()
{
    person *prsn[20];
    int i=0;    char ch = 'a';
   
    do
    {
        cout << "Write student or professor (s) or (p): "; cin >> ch;
        if (ch == 's') prsn[i] = new student;
        else if (ch == 'p') prsn[i] = new professor;
        prsn[i++]->setnewData();
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
    Sort(prsn, first, last);
    cout << endl <<"Sort list:" << endl << endl;

    for (int j=0; j<i; j++)  
    {
        cout << "---------------------------- " << j+1 << " ------------------------------" << endl;
        if (prsn[j]->isOutstanding()) { 
            prsn[j]->show();
            cout << "He/She is great!" << endl;
        }
        else
        prsn[j]->show();
    }
    return 0;
}

/*
s
Vlad
66.6
8.9
y
s
Vika
33.3
9.6
y
s
Max
45
9.7
y
p
Brane
18.54
90
y
p
Zak
34.8
76
n

*/