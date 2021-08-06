#include <iostream>
#include <random>
#include <time.h>
using namespace std;

void sum(int **arr,const int SIZE)
{
    for (int i=0; i<SIZE; i++)   
        for (int j=0; j<SIZE-1; j++)   *(*(arr+SIZE-1)+i) += *(*(arr+j)+i);
}

int main(int argc, char **argv)
{
    srand(time(0));
    int SIZE = 3;
    int **arr;
    arr = new int*[SIZE];
    for (int i = 0; i < SIZE; i++) 
    {
        *(arr+i) = new int[SIZE];
        if (i!= SIZE-1)
            for (int j=0; j<SIZE; j++) 
            {
                *(*(arr+i)+j) = -1 + rand()%9+1;  
                cout << *(*(arr+i)+j) << ' ';
            }
            else
                for (int j=0; j<SIZE; j++) 
                { 
                    *(*(arr+i)+j) = 0;
                    cout << *(*(arr+i)+j) << ' ';
                }
        cout << endl;
    }
    cout << endl << "Сумма массивов показана в SIZE-1 массиве" << endl;
    sum(arr,SIZE);
    cout << endl;
    for (int i=0; i<SIZE; i++)
    {
        for (int j=0; j<SIZE; j++) cout << *(*(arr+i)+j) << ' ';
        cout << endl;
    }
    return 0;
}