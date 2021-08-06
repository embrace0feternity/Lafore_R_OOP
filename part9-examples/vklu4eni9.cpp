#include <iostream>
using namespace std;

const int SIZE = 20;

class student
{
protected:

    char school[SIZE];
    char degree[SIZE];
public:
    student() { cout << "-----Constr st-----" << this << endl; }
    ~student() { cout << "-----Destr st-----" << this << endl; }
    void setEdu()
    {
        cout << "Write a name of school: "; cin >> school;
        cout << "Write a degree: "; cin >> degree;
    }
    void getEdu()
    {
        cout << "The name of school is " << school << endl;
        cout << "The degree is " << degree << endl;
    }
};

class employee
{
protected:
    char arr[SIZE];
    unsigned int number;
public:
    employee() { cout << "-----Constr empl-----" << this << endl; }
    ~employee() { cout << "-----Destr empl-----" << this << endl; }
    void setData()
    {
        cout << "Write an employees name: "; cin >> arr;
        cout << "Write the employees number: "; cin >> number; 
    }
    void getData()const
    {
        cout << "Name: " << arr << endl;
        cout << "Number: " << number << endl;
    }
};

class managers
{
private:
    employee objA;
    student objB;
    char title[SIZE];
    double amount;
public:
    void setData() 
    {
        objA.setData();
        objB.setEdu();
        cout << "Write manager`s title: "; cin >> title;
        cout << "Write an amount he has paid to company: "; cin >> amount;

    }
    void getData()
    {
        objA.getData();
        objB.getEdu();
        cout << "Write manager`s title: " << title << endl;
        cout << "Write an amount he has paid to company: " << amount << endl;
    }
};

class scientist
{
private:
    employee objA;
    student objB;
    unsigned short count_article;
public:
    void setData() 
    {
        objA.setData();
        objB.setEdu();
        cout << "How much articles he has done? "; cin >> count_article;
    }
    void getData()
    {
        objA.getData();
        objB.getEdu();
        cout << "He has done " << count_article << " articles" << endl;
    }
};

class worker
{
private:
    employee objA;
public:
    void setData()  {   objA.setData();  }
    void getData()  {   objA.getData();  }
};


int main()
{
    managers m1,m2;
    scientist s1;
    worker w1;
    for (int i=0; i<40; i++) cout << '-';
    cout << "Write info abount the first manager:" << endl;
    cout << endl;
    m1.setData();
    
    for (int i=0; i<40; i++) cout << '-';
    cout << "Write info abount the second manager:" << endl;
    cout << endl;
    m2.setData();
    
    for (int i=0; i<40; i++) cout << '-';
    cout << "Write info abount the scientist:" << endl;
    cout << endl;
    s1.setData();
    
    for (int i=0; i<40; i++) cout << '-';
    cout << "Write info abount the worker:" << endl;
    cout << endl;
    w1.setData();
    cout << endl;
    cout << "The first manager information:" << endl;
    m1.getData();
    cout << "The second manager information:" << endl;
    m2.getData();
    cout << "The scientist information:" << endl;
    s1.getData();
    cout << "The worker information:" << endl;
    w1.getData();

    return 0;
}


/*

4)      class Bosworth  :   public Alphonso
        {

        };


8)      Bosworth Bosworthobj;
        Bosworthobj.Alphonso::alfunc();


11)     Bosworth() : Alphonso() { }


14)     Derv(int a) : Base(a) {}


18)     class Tire  :   public Wheel, public Rubber     { };

19)     class Derv  :   public Base
        {
        public:
            void func()
            {
                ...
                Base::func();
                ...
            }
        };


*/