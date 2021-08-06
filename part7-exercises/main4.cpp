#include <iostream>
#include <random>
#include <time.h>
using namespace std;

int max(int *arr, int &n)
{
    int max = 0;
    for (int i=0; i<n; i++) if (max < arr[i]) max = arr[i];
    return max;
}

int main()
{
    srand(time(0)); // allow delete psevdo random :)
    int *arr;       int n;
    cout << "Write a number of elements" << endl;           cin >> n;

    arr = new int[n];
    for(int i=0; i<n; i++) 
    {
        arr[i] = rand()%10+1;
        cout << arr[i] << ' ';
    }
    cout << endl << "Maximum in array: " << max(arr,n) << endl;
    delete[]arr;
}