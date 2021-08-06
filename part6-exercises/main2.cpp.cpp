#include <iostream>
#include <conio.h>
using namespace std;

class border
{
private:
    unsigned int cars;
    double payment;
public:

    border(): cars(0),payment(0) {}

    void show(void) {  cout << "Итого проехало " << cars << " водителей. Заработок: " << payment << "$." << endl;  }
    void payingcar(void);
    void unpayingcar(void);
};

void border::payingcar(void)
{
    cars ++;        payment += 0.5;
    cout << "Водитель №" << cars << " оплатил проезд." << endl;
    cout << "Заработанных денег: " << payment << "$." << endl;
}

void border::unpayingcar(void)
{
    cars ++; 
    cout << "Водитель №" << cars << " не оплатил проезд." << endl;
    cout << "Заработанных денег: " << payment << "$." << endl;
}


int main()
{
    border temp;        char c='a';
    cout << "Вы добросовестный водитель?\n 1 - da\n 2 - net\n" << endl;
    while(c!='q')
    {
        c = getch();
        if (c==49)   temp.payingcar();
        else if (c==50)  temp.unpayingcar();
    }
}