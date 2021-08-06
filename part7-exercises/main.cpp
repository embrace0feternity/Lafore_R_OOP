#include <iostream>
#include <string.h>
using namespace std;

void foo(char c[])
{
    char temp;  int n = strlen(c)-1;
    for (int i=0; i<n/2; i++)
    {
        temp = c[i];
        c[i] = c[n-i];
        c[n-i] = temp;
    }
}

int main()
{
    const int SIZE = 80;
    char c[SIZE];
    
    cout << "Write a message: ";
    cin.get(c, SIZE);
    foo(c);
    cout << "New message: " << c << endl;
}