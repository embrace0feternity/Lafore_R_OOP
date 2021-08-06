#include <iostream>
using namespace std;

class Vehicles
{
public:
    Vehicles() {}
    virtual void go() { cout << "go base" << endl; }
};

class Jeep : public Vehicles
{
public:
    void go() override  
    { cout << "Go using JEEP" << endl;}
};


class Bus : public Vehicles
{
public:
    void go() override  
    { cout << "Go using BUS" << endl;}
};


class Van : public Vehicles
{
public:
    void go() override  
    { cout << "Go using VAN" << endl;}
};


class Train : public Vehicles
{
public:
    void go() override  
    { cout << "Go using TRAIN" << endl;}
};


class Taxi : public Vehicles
{
public:
    void go() override   
    { cout << "Go using TAXI" << endl;}
};

class Man
{
public:
    void choose(Vehicles *other)
    {
        other->go();
    }
};

int main()
{
    Vehicles obj;
    Jeep big_jeep;
    Bus small_bus;
    Van mercedes_van;
    Train suburb_train;
    Taxi fast_taxi;

  
    Man *person = new Man;
    person->choose(&small_bus);    
    return 0;
}