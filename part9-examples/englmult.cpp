#include <iostream>
using namespace std;

class wood_type
{
private:
    string dimensions;
    string grade;
public:
    wood_type(): dimensions("\'N/A\'"), grade("\'N/A\'") { }
    wood_type(string dim, string gr): dimensions(dim), grade(gr) { }
    void setType()
    {
        cout << "Введите номинальные размеры (2х4 и тд.): "; cin >> dimensions;
        cout << "Введите сорт (необработанная, брус, опилки и тд.): "; cin >> grade;
    }
    void getType()const
    {
        cout << "-- Hоминальные размеры: " << dimensions << " --" << endl;
        cout << "-- Сорт: " << grade << " --" << endl;
    }
};


class Distance
{
private:
    int feet;
    float inches;
public:
    Distance(): feet(0), inches(0.0) { }
    Distance(int f, float inch): feet(f), inches(inch) { }
    void setDist()
    {
        cout << "Введите футы: "; cin >> feet;
        cout << "Введите дюймы: "; cin >> inches;
    }
    void getDist()const
    {
        cout << "-- " << feet << '-' << inches << " --" << endl;
    }
};



class Lumber : private wood_type, private Distance
{
private:
    int quality;
    double price;
public:
    Lumber(): wood_type(), Distance() { }
    Lumber(string dim, string gr, int f, float inch, int qual, double pr):
        Distance(f,inch), quality(qual), price(pr) { }
    void setLumber()
    {
        wood_type::setType();
        Distance::setDist();
        cout << "Введите количество: "; cin >> quality;
        cout << "Введите цену за штуку: "; cin >> price;
    }
    void getLumber()const
    {
        wood_type::getType();
        Distance::getDist();
        cout << "-- Кол-во: " << quality << " --" << endl;
        cout << "-- Цена за штуку: " << price << " --" << endl;
    }
};


int main()
{
    /*Lumber empty;
    empty.setLumber();
    for (int i=0; i<60; i++) cout << "-";
    cout << endl;
    empty.getLumber();

    cout << endl << endl;
    for (int j=0; j<60; j++) cout << "-";
    cout << endl << endl;
    */
    Lumber fuel("2x4", "Брусок", 12, 5.6, 70, 50.0);
    fuel.getLumber();
    return 0;
}


