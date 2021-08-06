#include <iostream>
#include <string.h>
#include <iomanip>
#include <conio.h>
using namespace std;
#define ENTER 13

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
};


class bmoney
{
    enum { SIZE = 20 };
    char str[SIZE];
    long double amount;

public:
    bmoney(void): amount(0.0) { strcpy(str,"$"); }
    bmoney(sterling &sterl);

    char* __to_string(void);
    long double __stold(void);
    void show()const { cout << "Amount: " << setiosflags(ios::fixed) << setiosflags(ios::showpoint)
        << setprecision(6) << amount << endl; }
    
    bmoney operator+ (bmoney &other);
};
long double bmoney::__stold(void)
{
    char temp[SIZE];            int j = 0;    
    int length = strlen(str);

    for (int i=0; i<length; i++) 
        if (((str[i]>='0' && str[i]<='9') || str[i]=='.')) temp[j++] = str[i];
    temp[j]='\0';

    amount = stold(temp);  
    return amount;  
}
char* bmoney::__to_string(void)
{
    string buff = to_string(amount);        int i = 0;
    while (buff[i]!='.') i++;
    if (i>3)
    {
        for (int j=i-3; j>0; j-=3) 
        buff.insert(j, ",");
    }
    buff.insert(0,"$");
    for (int i=0; i<buff.length(); i++) str[i]=buff[i]; 
    return str;
}
bmoney bmoney::operator+ (bmoney &other)
{
    bmoney temp;
    temp.amount = amount + other.amount;
    return temp;
}

bmoney::bmoney(sterling &sterl)
{
    amount = double(sterl);
    amount = amount * 240;
    double dollar_temp = 50./240.;
    amount = amount * dollar_temp;
}



// 1.0.0 = 50$
int main()
{
    cout << "Write amoount of money using old money system like this: \'7.17.9\' " << endl;
    long funt; int sh, pens;
    cout << "Funt: "; cin >> funt;
    cout << "Sh: "; cin >> sh;
    cout << "Pens: "; cin >> pens; 
    sterling old(funt,sh,pens);


    bmoney dollars;
    dollars = old;
    cout << "$";        dollars.show();

    /*cout << "Write amount of money in new system: \'7.89\'" << endl;
    double money;
    cin >> money;
    sterling nw(money); // convert into old system;
    old.putSterling();  // show into old system;
    cout << "New in "; nw.putSterling();
    */

    return 0;

}

