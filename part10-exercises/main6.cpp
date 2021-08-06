//Use pointers everywhere it is possible
#include <iostream>
#include <string.h>
using namespace std;

int cmprstr(const char *str1, const char *str2)
{
    cout << strlen(str1) << ' ' << strlen(str2) << endl;
    int optimal_length = (strlen(str1) <= strlen(str2))? strlen(str2) : strlen(str1);
    for (int i=0; i<optimal_length; i++)
    {
        cout << "str1: " << str1[i] << "  str2: " << str2[i] << endl;
        if (str1[i]<str2[i]) return -1;
        else
            if (str1[i]>str2[i]) return 1;
        
    }
    return 0;
}

int main(int argc, char **argv)
{
    int SIZE = 30;
    char str1[SIZE], str2[SIZE];
    cout << "Is s1 < s2, return -1;\ns1 = s2 - return 0;\nelse return 1" << endl << endl;
    cout << "Write the first line: ";
    cin.getline(str1,SIZE);
    cout << "Write the second line: ";
    cin.getline(str2,SIZE);
    cout << cmprstr(str1,str2) << endl;
    return 0;
}

