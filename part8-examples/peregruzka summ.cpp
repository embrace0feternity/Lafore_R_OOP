#include <iostream>
using namespace std;

class weight
{
private:
    float wei;
public:
    weight(): wei(0.0) {}
    weight(float w): wei(w) {}
    float get()const { return wei; }
    weight operator+( weight &other);
    void operator+= (weight &other);

};

weight weight::operator+( weight &other)
{
    weight temp;
    temp.wei = wei + other.wei;
    return temp(wei + other.wei);
}       //c1 = c2 + c3;

void weight::operator+=(weight &other)
{
    wei = wei + other.wei;
}       //c1 += c2


int main()
{
    weight w1(5.3),w2(4.7), w3, w4;
    cout << "get w1: " << w1.get() << endl;
    cout << "get w2: " << w2.get() << endl;

    w3 = w1 + w2;
    w4 = w1 +w2 +w3;

    cout << "get w1: " << w1.get() << endl;
    cout << "get w2: " << w2.get() << endl;
    cout << "get w3: " << w3.get() << endl;    
    cout << "get w4: " << w4.get() << endl << endl;

    w3 += w4;
    cout << "get w3: " << w3.get() << endl; 
    return 0;
}