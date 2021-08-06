#include <iostream>
using namespace std;

class Distance
{
    static int counter; int id;

    float res;
    int m;
    float sm;
public:
    Distance(): res(0.0), m(0), sm(0.0) { id = ++counter; }
    Distance(float r): res(r)
    {
        float temp = res;
        m = int(temp/100);
        sm = temp - m;
        id = ++counter;
    }
    void show()const { cout << "Distance " << id << ": " << m << " meters " << sm << " santimeters" << endl; }

    Distance operator+ (Distance &other);
    Distance operator- (Distance &other);
};
int Distance::counter = 0;

Distance Distance::operator+ (Distance &other)
{
    return Distance(res + other.res);
}
Distance Distance::operator- (Distance &other)
{
    if (res >= other.res) return Distance(res - other.res);
    else
        return Distance(other.res - res);
}


int main(int argc, char **argv)
{
    Distance d1(329.54),d2(812.543),d3;
    
    d3 = d1 + d2;
    d1.show();      d2.show();      d3.show();

    d3 = d1 - d2;
    d1.show();      d2.show();      d3.show();
    return 0;
}