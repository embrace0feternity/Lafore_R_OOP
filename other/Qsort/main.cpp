#include <random>
#include <time.h>
#include <iostream>
using namespace std;

const     int SIZE = 7;

void Qsort(int *arr, int first, int last)
{
    int f = first, l = last;
    int mid = arr[(f + l)/2];
    cout << "Mid: " << mid << endl;
    int temp;
    while(f <= l)
    {
        while (arr[f] < mid) f++;
        while (arr[l] > mid) l--;
        cout << "arr[f]: " << arr[f] << "    arr[l]: " << arr[l] << endl;
        if (f<l)
        {
            temp = arr[f];
            arr[f] = arr[l];
            arr[l] = temp;
            f++;
            l--;   
        } 
    }
    for (int i=0; i<SIZE; i++) cout << arr[i] << ' ';
    cout << endl;
    if (first < l) Qsort(arr, first, l);
    if (f < last) Qsort(arr, f, last);
 
}
int main()
{
    int arr[SIZE] = { 4,9,7,6,2,3,8 };
    for (int i=0; i<SIZE; i++) {
        //arr[i]= 1 + rand()% 9;
        cout << arr[i] << ' ';
    }
    cout << endl;
    int first = 0, last = SIZE - 1;
    Qsort(arr, first, last);

    cout << " Qsort"<< endl;
    //for (int i=0; i<10; i++) cout << arr[i] << ' ';
    cout << endl;
    return 0;
}