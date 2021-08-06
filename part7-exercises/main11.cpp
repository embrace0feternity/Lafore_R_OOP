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

    char* __to_string(void);
    long double __stold(void);
    void show()const { cout << "Amount: " << setiosflags(ios::fixed) << setiosflags(ios::showpoint)
        << setprecision(6) << amount << endl; }
    
    bmoney operator+ (bmoney &other);
};
void bmoney::setstr(void)
{
label:
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
    if (strlen(str) == 1) 
    {
        cout << "Your line is empty!" << endl;
        goto label; 
    }
    cout << endl << str << endl;
}

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

int main(int argc, char **argv)
{
    bmoney amount[3];
    int choose;
    cout << "Would you like to calculate the summ?\n 1. Yes\n 2. No" << endl;
    while(true)
    {
        cin >> choose;
        if (choose == 2) return 0;
        else
        {
            cout << "Wrute two time your money" << endl;
            amount[1].__stold();        amount[2].__stold();  
            amount[3] = amount[1] + amount[2];  
            cout << "Your result: " << amount[3].__to_string() << endl;
            cout << "One more time?" << endl;
        }   
    }
    return 0; 
}
/*
cout << "Your amount is: " << setiosflags(ios::fixed) << setiosflags(ios::showpoint) 
        << setprecision(amount1.afterpoint()) <<  buff << endl;
        */