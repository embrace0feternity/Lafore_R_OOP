#include <iostream>
using std::endl;

class Distance
{
private:
    int feet;
    float inches;
public:
    Distance(): feet(0), inches(0.0) { }
    Distance(float flt)
    {
        feet = static_cast<int>(flt);
        inches = 12*(flt-feet);
    }
    Distance (int f, float i): feet(f), inches(i) { }
    
    void show()const { std::cout << feet << '-' << inches << endl;}
    friend Distance operator+ (Distance, Distance); // friend function
    friend Distance operator* (Distance, Distance);
};

Distance operator+ (Distance argA, Distance argB)
{
    int f = argA.feet + argB.feet;
    float i = argA.inches + argB.inches;
    if (i >= 12)
    {
        i -= 12;
        f++;
    }
    return Distance (f,i);
}

Distance operator* (Distance argA, Distance argB)
{
    int f = argA.feet * argB.feet;
    float i = argA.inches * argB.inches;
    if (i >= 12)
    {
        int temp = i/12;
        f += temp;
        i -= temp*12;
    }
    return Distance (f,i);
}

int main()
{
    Distance d1(12,7); // Distance
    Distance d2(5.11);  // float -> Distance
    Distance d3;       // empty

    d1.show();  d2.show();  d3.show();

    d3 = d1 * d2;
    d3.show();

    d3 = d1 * 2.0;
    d3.show();
    // If this function didn't realise, i wouldn't use d3 = 1 + d1, only d3 = d1 + 1;
    d3 = 2 * d1;
    d3.show();

    return 0;
}