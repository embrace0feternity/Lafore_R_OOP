#include <iostream>
#include <string.h>
#include <conio.h>
using namespace std;

class employee
{
protected:
    enum { SIZE = 20 };
    char arr[SIZE];
    unsigned int number;
public:
    employee(): number(0) { arr[0]='\0'; }
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
    managers() : employee(), amount(0.0) { title[0] = '\0'; }
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
    scientist() : employee(), count_article(0) {}
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

//-------------------------------------------------------------------------------------------------------

enum period{ hours, weeks, months };
class employee2
{
private:
    double compensation;
    period time;
public:
    employee2() : compensation(0) { }
    void setData()
    {
        cout << "Write a paymont: "; cin >> compensation;
        char ch;
        cout << "Почасовая/недельная/месячная оплата (h/w/m): "; cin >> ch;
        if (ch == 'h') time = hours;
        else if (ch == 'w') time == weeks;
        else if (ch == 'm') time == months;
    }
    void getData()const
    {
        cout << "Paymont: " << compensation << endl;
        string temp;
        if (time == hours) temp = "hours";
        else if (time == weeks) temp == "weeks";
        else if (time == months) temp == "months";

        cout << "Time/earn: " << temp << endl;
        for (int i=0; i<50; i++) cout << "--";
        cout << endl;
    }   
};

class managers2 : private employee2, private managers
{
public:
    managers2() : employee2(), managers() { }
    void setData() { managers::setData(); employee2::setData(); }
    void getData() { managers::getData(); employee2::getData(); }
};

class scientist2 : private employee2, private scientist
{
public:
    scientist2() : employee2(), scientist() { }
    void setData() { scientist::setData(); employee2::setData(); }
    void getData() { scientist::getData(); employee2::getData(); }
};

class worker2 : private employee, private employee2
{
public:
    worker2() : employee(), employee2() { }
    void setData() { employee::setData(); employee2::setData();}
    void getData() { employee::getData(); employee2::getData();}
};





int main()
{
    managers2 m1;
    managers2 m2;
    scientist2 s1;
    worker2 w1;

    cout << "--- Manager 1 ----" << endl;
    m1.setData();
    cout << "--- Manager 2 ----" << endl;
    m2.setData();
    cout << "--- Scientist 1 ----" << endl;
    s1.setData();
    cout << "--- Worker 1 ----" << endl;
    w1.setData();

    m1.getData();
    m2.getData();
    s1.getData();
    w1.getData();
    return 0;
}