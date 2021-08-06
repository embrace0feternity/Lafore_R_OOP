#include <iostream>
using namespace std;

class sterling
{
    long funt;
    int sh;
    int pens;
public:
    sterling(): funt(0), sh(0), pens(0) { }
    explicit sterling(double nw)
    {
        double temp = nw*240;   // 240 - koef. 1 funt = 240 pens
        funt = int(temp/240);
        temp = temp - funt*240;
        sh = int(temp/12);      // 1 sh = 12 pens
        pens = temp - sh*12;
    }
    sterling(long f, int sh, int p): funt(f), sh(sh), pens(p) {}

    void putSterling() { cout << ". Old money system: " << funt << '.' << sh << '.' << pens << endl; }
    operator double()
    {
        double temp = ((funt*20 + sh)*12 + pens)/240.;
        return temp;
    }
    sterling operator+ (sterling &other);
    sterling operator- (sterling &other);
    sterling operator* (double &other);
    sterling operator/ (sterling &other);
    sterling operator/ (double &other);
};
sterling sterling::operator+(sterling &other)
{
    double temp1 = other;
    double temp2 = sterling(funt,sh,pens);
    return sterling(temp1 + temp2);   
}

sterling sterling::operator-(sterling &other)
{
    double temp1 = other;
    double temp2 = sterling(funt,sh,pens);
    return sterling(temp1 - temp2);   
}

sterling sterling::operator* (double &other)
{
    double temp2 = sterling(funt,sh,pens);
    return sterling(other * temp2);   
}

sterling sterling::operator/ (sterling &other)
{
    double temp1 = other;
    double temp2 = sterling(funt,sh,pens);
    return sterling(temp1 / temp2);   
}

sterling sterling::operator/ (double &other)
{
    double temp2 = sterling(funt,sh,pens);
    return sterling(other / temp2);   
}


int main()
{
    cout << "Write amoount of money using old money system like this: \'7.17.9\' " << endl;
    long funt; int sh, pens;
    cout << "Funt: "; cin >> funt;
    cout << "Sh: "; cin >> sh;
    cout << "Pens: "; cin >> pens; 
    sterling old(funt,sh,pens);

    cout << "Write amount of money in new system: \'7.89\'" << endl;
    double money;
    cin >> money;
    sterling nw(money); // convert into old system;
    old.putSterling();  // show into old system;
    cout << "New in "; nw.putSterling();

    /*
            explicit в конструкторе запрещает неявное преобразование дабла в объект.
        Отсутствие explicit позволит создавать объекты без наличия перегруженных операторов +, -, *, /.
        При отсутствии explicit: 

            sterling temp;
            temp = nw + old;
        
            Создаётся объект темп через констр по умолчанию
        Объект nw и old преобразуются в дабл через оператор преобразования, суммируются даблы.
        Компилятор распознает сумму двух объектов типа дабл и создает НОВЫЙ temp, где сумма является 
        аргументом конструктора. 
            Итого: 2 одноименных объекта класса. Один создан констр по умолчанию,а другой - через констр с 1м аргументом (сумма).
        Пустой объект будет лишним, будет просто висеть в памяти до конца функции, в которой он был создан.
            С explicit такого неявного преобразования дабла в объекс класса не будет. Но придется перегружать 
        арифметические операторы. Я думаю, этот способ более надежный. 
    */

    sterling temp;
    temp = nw + old;
    cout << "Sum sterling + sterling"; temp.putSterling();

    temp = nw - old;
    cout << "Sub sterling - sterlin"; temp.putSterling();
    
    temp = old * money;
    cout << "Mult sterling * double"; temp.putSterling();

    temp = nw / old;
    cout << "Divide sterling / sterling"; temp.putSterling();

    temp = old / money;
    cout << "Divide sterling / double"; temp.putSterling();
    return 0;

}

