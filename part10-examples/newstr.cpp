#include <iostream>
#include <string.h>
using namespace std;

class easy_string
{ 
    char *str;
public:
    easy_string() { str = new char[100]; str[0]='\0'; }
    easy_string(int len) { str = new char[len+1]; }
    easy_string(const char *str);
    ~easy_string();

    void get()const { if (str!=nullptr) cout << "STR: " << str << endl; else cout << "STR: empty" << endl; }

    easy_string operator+(easy_string &s2);
};
easy_string::easy_string(const char *str)
{ 
    int temp = strlen(str);
    this->str = new char[temp+1];
    strcpy(this->str, str); 
    this->str[temp]='\0';
}
easy_string::~easy_string()
{ 
    if (str!=nullptr) delete[]str;
}


easy_string easy_string::operator+(easy_string &s2)
{
    int len = strlen(s2.str) + strlen(str);
    easy_string temp(len);
    strcpy(temp.str,str);
    strcat(temp.str,s2.str);
    cout << "temp: " << temp.str << endl;
    return temp;
}

int main()
{
    const char *STR1 = "Hi, vlad. ";
    const char *STR2 = "How are you?";
    easy_string s1(STR1),s2(STR2);
    easy_string s3;

    s1.get();
    s2.get();
    s3.get();
    cout << endl;

    s3 = s1 + s2; // mistake!
    s1.get();
    s2.get();
    s3.get();
    return 0;
}