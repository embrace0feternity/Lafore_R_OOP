#include <iostream>
#include <string.h>
#include <string>
using namespace std;

class easy_string
{
    enum { SIZE = 100 }; 
    char str[SIZE];
    int sum;
public:
    easy_string(): sum(5) { strcpy(str,"\0"); }
    easy_string(const char str[]): sum(5) { strcpy(this->str, str); }
    void get()const { cout << "STR: " << str << "\tSum: " << sum << endl; }

    easy_string operator+(easy_string s2);
};

easy_string easy_string::operator+(easy_string s2)
{
    easy_string temp;
    if (strlen(str)+strlen(s2.str)>SIZE)
    {
        cout << "Out of string" << endl;
        return 0;
    }
    else
    {
        strcpy(temp.str,str);
        strcat(temp.str,s2.str);
    }
    temp.sum = sum + s2.sum;
    return temp;
}

int main()
{
    char STR1[100], STR2[100];
    string str1,str2,str3;
    str1 = "Hi ";
    str2 = "Vlad";
    str3 = str1+str2;
    cout << str3 << endl;
    cout << "Write the first message: "; cin >> STR1;
    cout << "Write the second message: "; cin >> STR2;
    easy_string s1(STR1),s2(STR2),s3;

    s1.get();
    s2.get();
    s3.get();
    cout << endl;

    s3 = s1 + s2;
    s1.get();
    s2.get();
    s3.get();
    return 0;
}