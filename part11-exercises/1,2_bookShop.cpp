#include <iostream>
#include <random>
#include <time.h>
using namespace std;

class publications
{
private:
    string name;
    float price;
public:
    publications(): name("\'N/A\'"), price(0.0) { }

    virtual void setData()
    {
        cout << "Введите название книги: "; cin >> name;
        cout << "Введите стоимость книги: "; cin >> price;
    }
    virtual void getData()const 
    {
        cout << "--- Название: " << name << endl;
        cout << "--- Стоимость: " << price << endl;
    }
};


class book  :   public publications
{
private:
    int pages;
public:
    book(): publications(), pages(0) { }

    void setData() 
    { 
        cout << " --- Книга ---" << endl;
        publications::setData();
        cout << "Введите количество страниц в книге: "; cin >> pages; 
    }
    void getData()const 
    { 
        cout << endl << "Книга" << endl;
        publications::getData();
        cout << "--- Страниц: " << pages << endl; 
    }
};

class type  :   public publications
{
private:
    float min;
public:
    type(): publications(), min(0.0) { }
    
    void setData() 
    { 
        cout << " --- Аудио книга ---" << endl;
        publications::setData();
        cout << "Введите количество минут этой аудиокниги: "; cin >> min; 
    }
    void getData()const 
    {
        cout << endl << "Аудио книга:" << endl; 
        publications::getData();
        cout << "--- Минут: " << min << endl; 
    }
}; 

int main()
{
    srand(time(0));
    const int SIZE = 4;
    publications* publ[SIZE];
    for (int i=0, temp; i<SIZE; i++)
    {
        temp = rand()%2;
        if (temp) // if temp = 1 create book else audio
        {
            publ[i] = new book;
            publ[i]->setData();
        }
        else
        {
            publ[i] = new type;
            publ[i]->setData();
        }
    }
    for (int i=0; i<SIZE; i++) publ[i]->getData();

    return 0;
}