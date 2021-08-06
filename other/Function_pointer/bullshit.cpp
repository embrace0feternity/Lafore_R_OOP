#include <string.h>
#include <iostream>
using namespace std;

class bullshit
{
private:
    char *str;
public:
    bullshit() { str = nullptr; }
    bullshit(const char *s) 
    {
        int length = strlen(s);
        str = new char[length+1]; 
        strcpy(str,s); 
        str[length] = '\0';
    }
    bullshit(const bullshit &other)
    {
        int length = strlen(other.str);
        str = new char[length+1];
        strcpy(str, other.str);
        str[length] = '\0';
    }
    ~bullshit() 
    {
        delete str;
    }

    void show()const 
    { 
        char *ps = str;
        cout << "str: " << str << "  addr: " << &ps << endl;
    }
};


int main()
{
    cout << "test git" << endl;
    bullshit s1("Hi dude");
    s1.show();

    bullshit s2(s1);
    s2.show();

    bullshit s3 = s1;
    s3.show();
    
   return 0;
}