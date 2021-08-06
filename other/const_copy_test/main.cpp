#include <iostream>
using namespace std;

class car
{
private:
    int *number;
    int numsize;
public:

    car(int numsize)
    {
        this->numsize = numsize;
        cout << "Конструктор создан:  " << this << endl;
        number = new int[numsize];
        for (int i=0; i < numsize; i++) number[i]=i;
    }
    car(const car &arg);
    ~car()    {        cout << "Деструктор:  " << this << endl; delete[]number;    }
    void show(void);
};

car::car(const car &other)
{
    this->numsize = other.numsize;
    this->number = new int[numsize];
    for (int i = 0; i < numsize; i++)
    {
        this->number[i] = other.number[i];
    }
    cout << "Конструктор копирования для автомобилей создан:  " << this << endl;
    
}

void car::show(void)
{
    cout << "\nСвободные места:" << endl;
    for (int i=0; i< numsize; i++) cout << number[i] << ' '; 
    cout << endl;
}



class bus
{
private:
    int number;
    float tick_prise;
public:
    bus(int number, float tick_prise): number(number), tick_prise(tick_prise) 
    {
        cout << "Small_bus_12 has been created!  " << this << endl;
    }
    bus(bus &other);
    ~bus()
    {
        cout << "Small_bus has been deleted!  " << this << endl;
    }
    void show() { cout << "\nНомер автобуса: " << number << ". Стоимость билетика: " << tick_prise << '.' << endl; }
};

bus::bus(bus &other)
{
    this->number = other.number;
    this->tick_prise = other.tick_prise;
    cout << "Конструктор копирования сработал!  " << this << endl;
}



class apple
{
private:
    int weight;
public:
    apple(): weight(5)      {}
    void show() { cout << "Вес яблока: " << weight << endl; }
};

int main()
{
    /*cout << "Такие автобусы доступны сейчас:" << endl;
    bus small_bus_12(12,13.5);
    small_bus_12.show();

    bus small_bus_12_a(small_bus_12);
    small_bus_12_a.show();


    car nissan360(6);
    nissan360.show();

    car toyota(nissan360);
    toyota.show();*/

    apple red;
    red.show();

    return 0;
}