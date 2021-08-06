#include <iostream>
using namespace std;

class Distance
{
private:
    const float MTF;
    int feet;
    float inches;
public:
    explicit Distance (float meters): MTF (3.28F)
    {
        float fltfeet = MTF * meters;
        feet = int (fltfeet);
        inches = 12 * (fltfeet - feet);
    }
    void showdist()
    {
        cout << feet << "\'-" << inches << "\'" << endl;
    }
};
void fancyDist(Distance d);

void fancyDist(Distance d)
{
    cout << "В футах и дюймах: ";
    d.showdist();
}

int main()
{
    Distance d1(2.35);
    d1.showdist();
    float mtrs = 3.0;
    cout << "Dist1: " << endl;
    //fancyDist(mtrs);
    return 0;
}

/*

2)  class x
    {

    };

    x3.sub(x2,x1);

3)  class x
    {
        x operator- (x &other)
        {
            x temp();
            temp.field = field - other.field;
            return temp;
            // return x(field - other.field); 
        }
    };
    
    x3 = x2 - x1;

5)
    mycounter operator- ()
    {
        field --;
        return *this;
    }

8) и 9)
    myclass operator++ (int)
    {
        field++;
        return *this;
    }
*/