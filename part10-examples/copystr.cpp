#include <iostream>
#include <string.h>
using namespace std;

char* strc(char *str1, const char* str2)
{
    int i=0;
    while(str2[i]!='\0')
    {
        str1[i] = str2[i];
        i++;
    }
    str1[i] = '\0';
    return str1;
}

int main()
{
    char str1[30];
    char *str2 = "Hi vlad";

    //cout << strCPY(str1,str2) << endl;
    cout << strc(str1,str2) << endl;
    cout << str1 << endl;

    int a = 4, b = 6;
    const int *s = &a;
    cout << s << endl;
    s = &b;
    cout << s << endl;

    int* const ps = &a;
    cout << ps << endl;
    *ps = 7;
    cout << a << endl;
    return 0;
}


