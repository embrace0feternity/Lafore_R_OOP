#include <iostream>
#include <string.h>
#include <iomanip>
#include <conio.h>

#include <string>
using namespace std;

class person
{
    char name[12];
    char sex;
    int age;
public:
    void set();
    void get()const;
};
void person::set()
{
    cout << "Write a name: "; cin >> name;
    cout << "Write person`s sex(M/F): "; cin >> sex;
    cout << "And then write age of person: "; cin >> age; 
}
void person::get()const
{
    cout << "Name: " << name << endl << "Sex: " << sex << endl << "Age: " << age << endl << endl; 
}

class string_
{
    static const int SIZE = 256;
    char str[SIZE];
public:
    string_()    {   str[0] = '\0';   }
    string_(const char s[]) { strcpy(str,s); }
    void get()const {   cout << str << endl;    }
    void concat(const string_ &str2);
};
void string_::concat(const string_ &str2)
{
    strcat(str, str2.str);
}


void foo1() //cout your message
{
    /*
     *    Setw is needed to terminate input stream. If user writes a message which contains more than SIZE symbols, 
     *    next symbols after SIZE aren`t considered. Max length of input and output message is SIZE (without '\0').
    */
    const int SIZE = 100;
    char c[SIZE];
    cout << "Write a message:  ";
    cin >> setw(SIZE+1) >> c;
    cout << endl << "Your message is:  " << c << endl << "It`s length equals: " << strlen(c) << endl << endl;
}

void foo2() //copy your message
{
    char str1[] = "They will take you far from here...";
    const int SIZE = strlen(str1);
    char str2[SIZE+1];
    //strcpy(str2,str1);   // strcpy is the same like the next line;
    for (int i=0; i<SIZE; i++) str2[i]=str1[i];
    //str2[SIZE] = '\0';
    cout << "Copied message is:  " << str2 << endl;
}

void foo3() //array of string
{
    const int STR = 4;
    const int LENGTH = 12;
    char c[STR][LENGTH];
    for (int i=0; i<STR; i++) cin >> c[i];
    for (int i=0; i<STR; i++) cout << c[i] << endl; 
}

int main(int argc, char **argv)
{
    //foo1();
    //foo2();
    //foo3();
//----------------------------------------------------------------------------------------------------------------------------------  
    /*person p1,p2;
    p1.set();        p1.get();
    p2.set();        p2.get();*/
//----------------------------------------------------------------------------------------------------------------------------------
    /*string_ str1 {"I`m so sick of the fucking illusion that we keep "};
    string_ str2 {"We lost at the steple looooooove"};
    string_ str3;
    cout << "str1: ";   str1.get(); 
    cout << "str2: ";   str2.get(); 
    cout << "str3: ";   str3.get();

    str3 = str1;
    cout << "\nstr3: ";   str3.get();

    str3.concat(str2);
    cout << "\nstr1: ";   str1.get(); 
    cout << "str2: ";   str2.get(); 
    cout << "str3: ";   str3.get();
    */
//----------------------------------------------------------------------------------------------------------------------------------
    /*string str1 = "Washes the pain of instant despair";
    string str2 = "Trek through perilous water to face coldness and death";
    string str3;
    cout << "str1: " << str1;
    cout << "\nstr2: " << str2;
    cout << "\nstr3: " << str3;

    str3 = str1;
    str3 = str3 + ' ' + str2;
    cout << endl << endl;
    cout << "str1: " << str1;
    cout << "\nstr2: " << str2;
    cout << "\nstr3: " << str3;*/
//----------------------------------------------------------------------------------------------------------------------------------    
    /*string person;
    getline(cin,person,'$');
    cout << "Info about person: " << person << endl;*/
//----------------------------------------------------------------------------------------------------------------------------------
    /*string str1 = "The cryes of the peasant linger and wallow and flow through the air";
    int n;

    n = str1.find("peasant"); // position of str1 word
    cout << "Position of str1 word: " << n << endl;
    
    n = str1.find_first_of("abc");
    cout << "Position of the every symbol in \'abc\': " << n << endl;

    n = str1.find_first_not_of("The ");
    cout << "Position of the every symbol that isn`t contained in \'The \': " << n << endl;
    */
//----------------------------------------------------------------------------------------------------------------------------------
    /*string name = "Vlad";
    string your_name;
    
    getline(cin, your_name);
    if (name == your_name) cout << "Our names are the same!" << endl;
    else if (name < your_name) cout << "Your name is farther from NAME" << endl;
    else cout << "Your name is before name NAME" << endl;

    int n = your_name.compare(0,2,name,0,2); // 0 - from; 2 - how many symbols from 0; name - compare with; 0 - from (in name), 2 - how many (in name) 
    cout << endl << "First 2 letters in your name ";
    if (n==0) cout << "the same ";
    else if (n<0) cout << "stay before the NAME";
    else cout << "stay after the NAME ";
    cout << name.substr(0,2) << endl;*/

    return 0;
}
/*
    double doubleArray[100];
    for (int j=0; j<100; j++) cout << doubleArray[j] << endl;

    double twoD[10][10];
    cout << twoD[1][3];

    float flarr[3][3] 
    {
        52,27,83;
        94,63,26;
        11,65,24;
    }

    emplist[17].salary;

    bird manybirds[50];
    manybirds[27].cheep();

    cin >> setw(21) >> city;

    dextrose = "dfgodkg"

    strcpy(blank, name);

class dog
{
    int age;
    string breed;
};
*/