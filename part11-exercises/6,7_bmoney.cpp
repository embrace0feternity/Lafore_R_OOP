#include <conio.h>
#include <string>
#include <string.h>
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

#define ENTER 13

class bmoney
{
    enum { SIZE = 20 };
    char str[SIZE];
    long double amount;

    void setstr(void);
public:
    bmoney(void): amount(0.0) { strcpy(str,"$"); }
    bmoney(long double summ): amount(summ) { }

    char* __to_string(void);
    long double __stold(void);
    void show()const { cout << "Amount: " << setiosflags(ios::fixed) << setiosflags(ios::showpoint)
            << setprecision(6) << amount << endl; }

    int round();
    
    bmoney operator+ (bmoney &other) { return bmoney(amount + other.amount); }
    bmoney operator- (bmoney &other) 
    {
        long double temp = (amount >= other.amount)? amount-other.amount : other.amount-amount;  
        return bmoney(temp);
    };
    long double operator/ (bmoney other) 
    { 
        long double temp; 
        temp = amount / other.amount; 
        return temp; 
    }

    friend bmoney operator* (bmoney argA, bmoney argB);

    friend bmoney operator/ (bmoney argA, bmoney argB);

};


// cin line of money. It`s weird, i know :)
void bmoney::setstr(void)
{
    uint8_t i = 1;     
    cout << "Write amount of money like this \'$12,345.67\': $";
    while ((str[i]=getch())!=ENTER)
    {
        if ((str[i]>='0' && str[i]<='9') || str[i]==',' || str[i]=='.')
        {
            cout << str[i];
            i++; 
        }
    }
    str[i]='\0';
    cout << endl << str << endl;
}

// convert char* to long double
long double bmoney::__stold(void)
{
    char temp[SIZE];            int j = 0;    
    setstr();               int length = strlen(str);

    for (int i=0; i<length; i++) 
        if (((str[i]>='0' && str[i]<='9') || str[i]=='.')) temp[j++] = str[i];
    temp[j]='\0';

    amount = stold(temp);  
    return amount;  
}

// convert long double to string
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

// i don't want to change amount so i use variable
int bmoney::round()
{
    float variable;
    int temp = (modf(amount,&variable)>=0.5)? 1 : 0;
    return (variable+temp);    
}

bmoney operator* (bmoney argA, bmoney argB)
{
    return bmoney(argA.amount*argB.amount);
}
bmoney operator/ (bmoney argA, bmoney argB)
{
    return bmoney(argA.amount/argB.amount);
}



void menu(void)
{
    cout << "Что Вы хотите сделать??\n1. Найти сумму\n2. Разность\n3. Узнать цену за единицу времени, затраченного на изделие\n"
        << "4. Узнать общую цену, деленную на цену изделия\n5. Общая цена на число изделий" << endl;
}


int main(int argc, char **argv)
{
    bmoney objA(500.000);
    bmoney objB(10.000);
    objB = 10/objA;
    cout << objB.__to_string() << endl;
    objB = objA*90;
    cout << objB.__to_string() << endl;

    bmoney objC(100.49);
    cout << objC.round();
    return 0; 
}
/*
cout << "Your amount is: " << setiosflags(ios::fixed) << setiosflags(ios::showpoint) 
        << setprecision(amount1.afterpoint()) <<  buff << endl;
        */