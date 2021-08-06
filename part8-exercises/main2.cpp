#include <string.h>
#include <iostream>
using namespace std;

class cat
{  
    enum { SIZE = 21 };
    char str[SIZE];
public:
    cat(void) { strcpy(str,""); }
    cat(const char c[]) { strcpy(str,c); }
    void show(void)const { cout << str << endl;}

    cat operator+ (cat &other)
    {
        cat temp;
        if ((strlen(other.str) + strlen(str)) > SIZE) { cout << "Out of range" << endl; exit(0); }
        else
        {
            strcpy(temp.str,str);
            strcat(temp.str,other.str);
        }
        return temp;
    }

    cat operator+= (cat &other)
    {
        strcat(str,other.str);
        return str;
    }
};

int main(int argc, char** argv)
{
    cat str1 = "Hi, ";
    cat str2 = "dude!"; 
    cat str3;

    cout << "str1 + str2 = ";
    str3 = str1 + str2;
    str3.show();

    cout << "str1 += str2 = ";
    str1 += str2;
    str1.show();

    cat str4;
    str4 = str1 += str2;
    str3.show();
    return 0;
}