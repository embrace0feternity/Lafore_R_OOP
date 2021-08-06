#include <string.h>
#include <iostream>
using namespace std;

class weigth
{
    const float coef;
    int kilo;
    float gramm;
public:
    weigth(): coef(0), kilo(0), gramm(0) {}
    weigth(float c): coef(c) 
    {
        kilo = int(c);
        gramm = c-kilo;
    }
    void show()const { cout << "Kilo: " << kilo << ", gramm: " << gramm << endl; }

    operator float ()
    {
        float temp=0;
        temp = kilo + gramm;
        return temp;
    }
};

class s
{
    enum { SIZE = 80 };
    char str[SIZE];
public:
    s(): str("\0") {}
    s(const char str[]) { strcpy(this->str,str); } 
    void show()const { cout << "Message: " << str << endl; }
    operator char* ()
    { return str; }
};

int main()
{
    s str1;
    str1.show();
    str1 = "Hi ";
    str1.show();
    
    s str2 = "dude";
    cout << static_cast<char*>(str2) << endl << endl;

    weigth wei1(123.5F);
    wei1.show();

    float temp = static_cast<float>(wei1);
    cout << "Temp: " << temp << endl;

    temp = 0;
    cout << "Zero temp: " << temp << endl;

    temp = wei1;
    cout << "Equal temp: " << temp << endl;


    return 0;
}

