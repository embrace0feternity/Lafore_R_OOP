#include <string.h>
#include <iostream>
using namespace std;

class cars
{
    float speed;
    enum { SIZE = 10 };
    char name[SIZE];
public:
    cars(float speed,const char str[]): speed(speed) { strcpy(name, str); }
    float get()const { return speed; }

    bool operator< (cars &other);    
    bool operator== (cars &other);
};
bool cars::operator< (cars &other)
{
    return (speed < other.speed)? true : false;
}
bool cars::operator== (cars &other)
{
    //return (strcmp(name,other.name) == 0) ? true : false;
    int temp = strcmp(name,other.name);
    if (strcmp(name,other.name) == 0) return true;
    else return false;
}


int main()
{
    cars c1(247.4,"Toyota"), c2(250,"Mazda");

    if (c1 < c2) cout << "c1 < c2" << endl;
    else cout << "с1 не меньше с2" << endl;

    if (c1 == c2) cout << "c1 == c2" << endl;
    else cout << "c1 не равно c2" << endl;

}