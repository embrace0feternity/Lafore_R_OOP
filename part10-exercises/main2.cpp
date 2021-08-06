/*
    --------------------------------------Condition--------------------------------------------
        Используя уже ранее написанный код, класс easy_string, добавьте к нему метод upit(),
    который будет переводить символы строки из нижнего регистра в верхний. МОЖНО использовать библиотечную
    ф-ию toupper(), которая будет возвращать 1 символ -_-, переводя его в верхний регистр, если это необходимо
    Она находится в заголовочном файле CCtype; #include <cctype>
*/


#include <iostream>
#include <string.h>
using namespace std;
// Я представил, что класс easy_string недоступен явным образом. Так будет интереснее. Использую наследование

class easy_string
{  
private:
    enum { SIZE = 40 };

public:
    char str[SIZE];
    easy_string() { str[0]='\0'; }
    easy_string(const char *str);

    void get()const { if (str!=nullptr) cout << "STR: " << str << endl; else cout << "STR: empty" << endl; }

    easy_string operator+(easy_string &s2);
};
easy_string::easy_string(const char *str)
{ 
    int temp = strlen(str);
    strcpy(this->str, str); 
    this->str[temp]='\0';
}
easy_string easy_string::operator+(easy_string &s2)
{
    int len = strlen(s2.str) + strlen(str);
    if (len > SIZE) { cout << "Out of range (SIZE = 40)." << endl; exit(1); } 
    easy_string temp;
    strcpy(temp.str,str);
    strcat(temp.str,s2.str);
    return temp;
}


class String : public easy_string 
{
public:
    String(): easy_string() { }
    String(easy_string other) { strcpy(str, other.str); }
    String(const char* str): easy_string(str) { }
    char* upper();

    String operator+(easy_string &s2) 
    { 
        String temp = easy_string::operator+(s2);
        return temp;
    }
};
char* String::upper()
{
    char *temp = str;
    for (int i=0; i<strlen(str); i++)
    {   
        temp[i] = str[i];
        if (temp[i]>='a' && temp[i] <='z') 
        temp[i] -= 32; // 'A' = 97; 'a' = 65; 'A' - 'a' = 32;
    }
    return temp;
}



int main()
{
    const char *STR1 = "Hi, Vlad. ";
    const char *STR2 = "How ARE you?";
    String s1(STR1),s2(STR2);
    String s3;

    s1.get();
    s2.get();
    s3.get();
    cout << endl;

    s3 = s1 + s2; // mistake! joke
    s1.get();
    s2.get();
    s3.get();

    cout << s3.upper() << endl;
    cout << endl;

    
    return 0;
}