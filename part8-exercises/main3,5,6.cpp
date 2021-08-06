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
    time(int h, int m, int s): hours(h), minutes(m), seconds(s) { count++; id = count; }

    void show()const { cout << "Время на часах №" << id << ": " << hours << ':' << 
        minutes << ':' << seconds << endl; }
    time operator+ (time &watch);
    time operator++ () { return time(hours++,minutes,seconds); }
    time operator++ (int) { return time(hours++,minutes,seconds); }
    time operator-- () { return time(hours--,minutes,seconds); }
    time operator-- (int) { return time(hours--,minutes,seconds); }
    time operator- (time &watch);
};

int time::count = 0;

time time::operator+ (time &watch)
{
    time temp;
    temp.hours = hours + watch.hours;
    if (temp.hours > 23) temp.hours -= 24;

    temp.minutes = minutes + watch.minutes;
    if (temp.minutes > 59) { temp.minutes -= 60; temp.hours ++; }

    temp.seconds = seconds + watch.seconds;
    if (temp.seconds > 59) { temp.seconds -= 60; temp.minutes++; }
    return temp;
}

time time::operator- (time &watch)
{
    time temp;
    temp.hours = hours - watch.hours;
    if (temp.hours < 0) temp.hours += 24;

    temp.minutes = minutes - watch.minutes;
    if (temp.minutes < 0) { temp.minutes += 60; temp.hours --; }

    temp.seconds = seconds - watch.seconds;
    if (temp.seconds < 0) { temp.seconds += 60; temp.minutes--; }
    return temp;
}

//05:07:12
// - - - -
//12:47:52
//17

void write(int &h, int &m, int &s)
{
    char c[6]; int i=0; int temp;
    while(i!=6)
    {
        c[i] = getch();
        if (c[i] >='0' && c[i] <= '9')
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
    time watch1(h,m,s);
    watch1.show();
    
    cout << "Write time one more" << endl;
    write(h,m,s);
    time watch2(h,m,s);
    watch2.show();

    time watch3;
    watch3 = watch1 + watch2;
    watch3.show();
    
    watch3++;
    ++watch3;
    watch3.show();
    watch3--;
    --watch3;
    watch3.show();

    time watch4;
    watch4 = watch1 - watch2;
    watch4.show();
    return 0;
}