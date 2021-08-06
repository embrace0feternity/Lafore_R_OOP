#include <conio.h>
#include <string>
#include <string.h>
#include <iostream>
#include <iomanip>
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
    explicit bmoney(long double summ): amount(summ) { }

    char* __to_string(void);
    long double __stold(void);
    void show()const { cout << "Amount: " << setiosflags(ios::fixed) << setiosflags(ios::showpoint)
            << setprecision(6) << amount << endl; }
    
    bmoney operator+ (bmoney &other) { return bmoney(amount + other.amount); }
    bmoney operator- (bmoney &other) 
    {
        long double temp = (amount >= other.amount)? amount-other.amount : other.amount-amount;  
        return bmoney(temp);
    };
    bmoney operator* (long double &other) { return bmoney(amount * other); }
    long double operator/ (bmoney other) 
    { 
        long double temp; 
        temp = amount / other.amount; 
        return temp; 
    }
    bmoney operator/ (long double other) { return bmoney(amount/other); }

};


// cin line of money
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



void menu(void)
{
    cout << "Что Вы хотите сделать??\n1. Найти сумму\n2. Разность\n3. Узнать цену за единицу времени, затраченного на изделие\n"
        << "4. Узнать общую цену, деленную на цену изделия\n5. Общая цена на число изделий" << endl;
}

/*
    Тестил работу explicit. Можно все параметры перегруженных операторов передавать по ссылке, и тогда explicit не нужон. Из-за ссылки не 
    будет создаваться новый объект класса.
    amount[1] = amount[0] / temp; работает с explicit
    amount[1] = amount[0] + temp; уже не работает, но только если в перегруженный оператор аргумент передавать по значению, а не по ссылке
*/

int main(int argc, char **argv)
{
    bmoney amount[3];
    char choose; long double temp = 0;
    menu();
    for (int i=0; i<2; i++) amount[i].__stold();
    while(true)
    {
    label2:
        cout << "Введите выбор: ";
        choose = getch();
        cout << choose << endl;
        switch (choose)
        {
        case '1':
            amount[2] = amount[0] + amount[1];
            cout << "Ваша сумма равняется " << amount[2].__to_string() << endl;
            break;
        case '2':
            amount[2] = amount[0] - amount[1];
            cout << "Разность равняется " << amount[2].__to_string() << endl;
            break; 
        case '3':
            if (temp == 0)
            {
               cout << "У вас еще нет изделий. Укажите, сколько изделий, пункт 4." << endl; 
               goto label2;
            }
            amount[2] = amount[0] * temp;
            cout << "Цена за единицу времени, затраченного на изделие: " << amount[2].__to_string() << endl;
            break; 
        case '4':
            temp = amount[0] / amount[1];
            cout << "Общую цена, деленная на цену изделия: " << temp << endl;
            break; 
        case '5':
            if (temp == 0)
            {
               cout << "У вас еще нет изделий. Укажите, сколько изделий, пункт 4." << endl; 
               goto label2;
            }
            amount[2] = amount[0] / temp;
            cout << "Общая цена на число изделий: " << amount[2].__to_string() << endl;
            break;         
        default:
            return 0;

        }
    }
    return 0; 
}
/*
cout << "Your amount is: " << setiosflags(ios::fixed) << setiosflags(ios::showpoint) 
        << setprecision(amount1.afterpoint()) <<  buff << endl;
        */