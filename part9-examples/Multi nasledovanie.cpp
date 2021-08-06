#include <iostream>
using namespace std;

const int SIZE = 20;

class student
{
protected:
    char school[SIZE];
    char degree[SIZE];
public:
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
    employee() {}
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

class managers : private employee, private student
{
private:
    char title[SIZE];
    double amount;
public:
    managers() : employee() {}
    void setData() 
    {
        employee::setData();
        cout << "Write manager`s title: "; cin >> title;
        cout << "Write an amount he has paid to company: "; cin >> amount;
        student::setEdu();
    }
    void getData()
    {
        employee::getData();
        cout << "Write manager`s title: " << title << endl;
        cout << "Write an amount he has paid to company: " << amount << endl;
        student::getEdu();
    }
};

class scientist : private employee, private student
{
private:
    unsigned short count_article;
public:
    void setData() 
    {
        employee::setData();
        cout << "How much articles he has done? "; cin >> count_article;
        student::setEdu();
    }
    void getData()
    {
        employee::getData();
        cout << "He has done " << count_article << " articles" << endl;
        student::getEdu();
    }
};

class worker : public employee
{

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