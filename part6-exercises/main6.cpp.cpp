#include <iostream>
#include <conio.h>
using namespace std;

class time
{
private:
    int hours;
    int minutes;
    int seconds;

    static int count; int id;
public:
    time(): hours(0), minutes(0), seconds(0) { count++; id = count; }
    time(int &h, int &m, int &s): hours(h), minutes(m), seconds(s) { count++; id = count; }

    void show()const { cout << "Время на часах №" << id << ": " << hours << ':' << 
        minutes << ':' << seconds << endl; }
    void add(const time &watch1,const time &watch2);
};

int time::count = 0;

void time::add(const time &watch1,const time &watch2)
{
    hours = watch1.hours + watch2.hours;
    if (hours > 23) hours -= 24;

    minutes = watch1.minutes + watch2.minutes;
    if (minutes > 59) { minutes -= 60; hours ++; }

    seconds = watch1.seconds + watch2.seconds;
    if (seconds > 59) { seconds -= 60; minutes++; }
}

void write(int &h, int &m, int &s)
{
    char c[6]; int i=0; int temp;
    while(i!=6)
    {
        c[i] = getch();
        if (c[i] > 47 && c[i] < 58)
        {
            if ((i == 1) || (i == 3)) cout << c[i] << ':';
            else cout << c[i];
            i++;
        }
    } 
    h = (c[0]-48)*10+(c[1]-48);  
    m = (c[2]-48)*10+(c[3]-48);
    s = (c[4]-48)*10+(c[5]-48);
    cout << endl;
}

int main()
{
    int h,m,s;

    cout << "Write time for shape like this: \'00:00:00\'" << endl; 
    write(h,m,s);
    const time watch1(h,m,s);
    watch1.show();
    
    cout << "Write time one more" << endl;
    write(h,m,s);
    const time watch2(h,m,s);
    watch2.show();

    time watch3;
    watch3.add(watch1, watch2);
    watch3.show();
    return 0;
}