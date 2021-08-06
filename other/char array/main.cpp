#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    const int LENGTH = 200;
    char cArr[LENGTH];
    cout << "Write a line:" << endl;
    cin.get(cArr,LENGTH,'0');
    cout << "you write:  " << cArr << endl;

    /*const int LENGTH = 50;
    char cArr[LENGTH];
    cout << "Write a line:" << endl;
    cin.get(cArr, LENGTH);
    cout << "You write:  " << cArr << endl;*/
    return 0;
}