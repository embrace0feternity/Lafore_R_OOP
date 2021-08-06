#include <iostream>
#include <string.h>
using namespace std;

class String
{
protected:
    enum { SIZE = 31 };
    char str[SIZE];
public:
    String() { strcpy(str, "\0"); }
    String(const char s[]) { strcpy(str,s); }
    void get()const { cout << str; }
    operator char*()    { return str; }
};

class Pstring : public String
{
public:
    Pstring() : String() {}
    Pstring(const char s[])
    {
        if (strlen(s) > SIZE-1)
        {
            for (int i=0; i<SIZE-1; i++) str[i] = s[i];
            str[SIZE-1]='\0';
        }  else strcpy(str,s);
    }
};

int main()
{
    Pstring s1 = "Hi dude.";
    Pstring s2 = " Nice to meet you. I`m Vlad. Who are you, man???";
    s1.get();
    s2.get();
    return 0;
}