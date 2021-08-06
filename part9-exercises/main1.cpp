#include <iostream>
using namespace std;

class publications
{
private:
    enum { SIZE = 30 };
    char name[SIZE];
    float price;
public:
    publications(): name("\'N/A\'"), price(0.0) { }

    void setData()
    {
        cout << "Введите название книги: "; cin >> name;
        cout << "Введите стоимость книги: "; cin >> price;
    }
    void getData()const 
    {
        cout << "--- Название: " << name << endl;
        cout << "--- Стоимость: " << price << endl;
    }
};


class book  :   private publications
{
private:
    int pages;
public:
    book(): publications(), pages(0) { }

    void setData() 
    { 
        publications::setData();
        cout << "Введите количество страниц в книге: "; cin >> pages; 
    }
    void getData()const 
    { 
        publications::getData();
        cout << "--- Страниц: " << pages << endl; 
    }
};

class type  :   private publications
{
private:
    float min;
public:
    type(): publications(), min(0.0) { }
    
    void setData() 
    { 
        publications::setData();
        cout << "Введите количество минут этой аудиокниги: "; cin >> min; 
    }
    void getData()const 
    { 
        publications::getData();
        cout << "--- Минут: " << min << endl; 
    }
}; 

int main()
{
    book b1;
    type a1;

    cout << "\t\tКнига №1: " << endl; b1.setData();
    cout << "\t\tАудиокнига №1: " << endl; a1.setData();

    for (int i=0; i<60; i++) cout << '+';
    cout << endl;

    b1.getData();
    a1.getData();
    return 0;
}