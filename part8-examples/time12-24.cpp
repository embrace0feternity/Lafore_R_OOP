#include <iostream>
#include <string.h>
using namespace std;


class time24
{
    int hrs;
    int min;
    int sec;
public:
    int gethrs()const { return hrs; }
    int getmin()const { return min; }
    int getsec()const { return sec; }
    time24(int h, int m, int c): hrs(h), min(m), sec(c) {}
    void show()const; 
    //operator time12();
};
void time24::show()const
{
    cout << "24-часовое время: "; 
    if (hrs < 10 ) cout << '0'; cout << hrs << ':';
    if (min < 10 ) cout << '0'; cout << min << ':'; 
    if (sec < 10 ) cout << '0'; cout << sec << endl; 
}

/*time24::operator time12()
{
    bool am_pm = (hrs < 12)? false : true;

    int min12 =  sec < 30 ? min : min+1;
    if (min12 == 60)
    {
        min12 = 0;
        hrs++;
        if (hrs == 12 || hrs == 24) am_pm = (am_pm == true) ? false : true; 
    }

    int hrs12 = (hrs > 12)? hrs-12 : hrs;
    if (hrs12 == 0)
    {
        hrs12 = 12;
        am_pm = true;
    }
    return time12 (am_pm, hrs12, min12);
}*/


class time12
{
    bool am;
    int hrs;
    int min;
public:
    time12(): am(true), hrs(0), min(0) {}
    time12(time24 &other);
    time12(bool a, int h, int m): am(a), hrs(h), min(m) {}
    void show()const;
};
void time12::show()const
{
    cout << "12-часовое время: "; 
    if (hrs < 10 ) cout << '0'; cout << hrs << ':';
    if (min < 10 ) cout << '0'; cout << min;
    string temp = am ? "pm" : "am"; 
    cout << temp << endl;
}
time12::time12(time24 &other)
{
    int hrs24 = other.gethrs();
    int min24 = other.getmin();
    int sec = other.getsec();
    am = (hrs24 < 12)? false : true;

    min =  sec < 30 ? min24 : min24+1;
    if (min == 60)
    {
        min = 0;
        hrs24++;
        if (hrs24 == 12 || hrs24 == 24) am = (am == true) ? false : true; 
    }

    int hrs = (hrs24 > 12)? hrs24-12 : hrs24;
    if (hrs == 0)
    {
        hrs = 12;
        am = true;
    }
}



int main()
{
    time12 t12;
    int hrs, min, sec;
    cout << "Введите время в 24-часовой системе:\n Часы (0-23): "; cin >> hrs;
    cout << " Минуты: "; cin >> min;
    cout << " Секунды: "; cin >> sec; 

    time24 t24(hrs,min,sec);
    t24.show();

    t12 = t24;
    t12.show();

    return 0;
}