#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    string s;
    string str;
    cout << "write a message: ";
    getline(cin,s);
    for (int i = 0;i < s.length(); i++)    s.erase ('1');
    cout << s << endl;
}