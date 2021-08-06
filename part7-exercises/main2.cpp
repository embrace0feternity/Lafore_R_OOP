#include <iostream>
#include <conio.h>
#include <string.h>
using namespace std;

class employee
{
private:
    enum {SIZE=80};
    char name[SIZE];
    int number;
public:
    void set(void);
    void show(void)const { cout << "Name: " << name << ".\t\tNumber: " << number << endl; }
};
void employee::set(void)
{
    cout << "Write the name of the empolyee: "; 
    cin.get();
    cin.get(name,SIZE,'\n'); 
    cout << "Write workers` number: "; cin >> number; cout << endl;
}


int main()
{
    const int SIZE = 100;
    employee worker[SIZE];
    char c = '1';       int count=0;

    for (int i=0; i<SIZE; i++)
    {
        count ++;
        worker[i].set();
        cout << "Would you like still to write down info about employee?\n";
        c = getch();
        if (c == '2') break;  
    }
    cout << "All your workers:\n"; 
    for (int i=0; i<count; i++) { worker[i].show(); }
    return 0;
}