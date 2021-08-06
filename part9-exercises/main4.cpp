#include <iostream>
#include <conio.h>
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

class sales
{
    enum { N = 3 };
    float arr[N];
public:
    void setData()
    {
        cout << "Сколько было получено прибыли за продажу этих книг за последние 3 месяца: ";
        for (int i=0; i<N; i++) cin >> arr[i];
    }
    void getData()const 
    {
        cout << "--- Получено прибыли за последние 3 месяца: ";
        for (int i=0; i<N; i++) cout << arr[i] << ' ';
        cout << endl;
    }
};


class book  :   private publications, private sales
{
private:
    int pages;
public:
    book(): publications(), pages(0) { }

    void setData() 
    { 
        publications::setData();
        cout << "Введите количество страниц в книге: "; cin >> pages;
        sales::setData(); 
    }
    void getData()const 
    { 
        publications::getData();
        cout << "--- Страниц: " << pages << endl; 
        sales::getData();
    }
};

class type  :   private publications, private sales
{
private:
    float min;
public:
    type(): publications(), min(0.0) { }
    
    void setData() 
    { 
        publications::setData();
        cout << "Введите количество минут этой аудиокниги: "; cin >> min; 
        sales::setData(); 
    }
    void getData()const 
    { 
        publications::getData();
        cout << "--- Минут: " << min << endl; 
        sales::getData();
    }
}; 

enum CDorDVD { CD, DVD };

class disk  :   private publications, private sales
{
private:
    CDorDVD disk_choose;
public:
    void setData() 
    { 
        publications::setData();
        cout << "Подарок. Получите публикацию на диске бесплатно! Выберите CD (c) или DVD (d): ";
        char ch = 'a';      ch=getche();
        cout << endl;
        disk_choose = (ch == 'c')? CD : DVD;
        sales::setData(); 
    }
    void getData()const 
    { 
        publications::getData();
        cout << "--- Диск: " << ((disk_choose == 0)? "CD" : "DVD") << endl; 
        sales::getData();
    }
};

int main()
{
    //book b1;
    //type a1;
    disk d1;

    //cout << "\t\tКнига №1: " << endl; b1.setData();
    //cout << "\t\tАудиокнига №1: " << endl; a1.setData();
    cout << "\t\tДиск №1 " << endl; d1.setData(); 

    for (int i=0; i<60; i++) cout << '+';
    cout << endl;
    d1.getData();

    //b1.getData();
    for (int i=0; i<60; i++) cout << '+';
    cout << endl;
    //a1.getData();
    return 0;
}