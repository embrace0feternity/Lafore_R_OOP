#include <time.h>
#include <random>
#include <iostream>
using namespace std;

int main()
{
    srand(time(0));
    int **arr;
    int numarrays;
    cout << "How many arrays do u have? "; cin >> numarrays;
    arr = new int*[numarrays];
    for (int i=0; i<numarrays; i++)
    {
        *(arr+i) = new int[10];
        cout << i+1 << ". ";
        for (int j=0; j<10; j++) {  
            arr[i][j] = 1 + rand()%9;
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}