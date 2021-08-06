#include <iostream>
using namespace std;

class employee
{
protected:
    enum { SIZE = 20 };
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

class managers : public employee
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
    }
    void getData()
    {
        employee::getData();
        cout << "Write manager`s title: " << title << endl;
        cout << "Write an amount he has paid to company: " << amount << endl;
    }
};

class scientist : public employee
{
private:
    unsigned short count_article;
public:
    void setData() 
    {
        employee::setData();
        cout << "How much articles he has done? "; cin >> count_article;
    }
    void getData()
    {
        employee::getData();
        cout << "He has done " << count_article << " articles" << endl;;
    }
};

class worker : public employee
{

};

class brigadir : public worker
{
private:
    float quotas;
public:
    void setData()
    {
        worker::setData();
        cout << "Write his quotas: "; cin >> quotas;
    }
    void getData()const
    {
        worker::getData();
        cout << "His quotas: " << quotas << endl;
    }
};


int main()
{
    //managers m1,m2;
    scientist s1;
    worker w1;
    brigadir b1;

    /*cout << "Write info abount the first manager:" << endl;
    for (int i=0; i<40; i++) cout << '-';
    cout << endl;
    m1.setData();
    
    cout << "Write info abount the second manager:" << endl;
    for (int i=0; i<40; i++) cout << '-';
    cout << endl;
    m2.setData();
    
    cout << "Write info abount the scientist:" << endl;
    for (int i=0; i<40; i++) cout << '-';
    cout << endl;
    s1.setData();
    */
    cout << "Write info abount the worker:" << endl;
    for (int i=0; i<40; i++) cout << '-';
    cout << endl;
    w1.setData();

    cout << "Write info abount the first brigadir:" << endl;
    for (int i=0; i<40; i++) cout << '-';
    cout << endl;
    b1.setData();

    /*w1.setData();
    for (int i=0; i<70; i++) cout << '.';
    cout << endl;
    cout << "The first manager information:" << endl;
    m1.getData();
    cout << "The second manager information:" << endl;
    m2.getData();
    cout << "The scientist information:" << endl;
    s1.getData();*/
    cout << "The worker information:" << endl;
    w1.getData();
    cout << "The brigadir information:" << endl;
    b1.getData();
    return 0;
}