#include <iostream>
#include <string.h>
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
    void get()const { cout << "Get: " << str << endl; }
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
//-------------------------------------------------------------------------------------------------------------------
class Pstring2 : public Pstring
{
private:
    char buff[SIZE];
public:
    Pstring2() : Pstring()  { buff[0]='\0'; }
    Pstring2(const char s[]) : Pstring(s) { cout << "create: " << this << endl; }
    ~Pstring2() { cout << "destr: " << this << endl; }
    char* left(const int n);
    char* middle(const int bot, const int top);
    char* right(const int n);
};
char* Pstring2::left(const int n)
{
    for (int j=0; j<n; j++) buff[j]=str[j];
    buff[n] = '\0';
    return buff;
}

char* Pstring2::middle(const int bot, const int top)
{
    for (int i=0; i<top-bot; i++) buff[i] = str[i+bot];
    buff[top]='\0';
    return buff;
}

char* Pstring2::right(const int n)
{
    for (int i=n; i<strlen(str); i++) buff[i-n]=str[i];
    buff[strlen(str)-n] = '\0';
    return buff;
}




int main()
{  
    Pstring2 temp = "Hi vlad";
    temp.get();
    cout << "left: " << temp.left(3) << endl;
    cout << "middle: " << temp.middle(3,6) << endl;
    cout << "right: " << temp.right(6) << endl;
    return 0;
}