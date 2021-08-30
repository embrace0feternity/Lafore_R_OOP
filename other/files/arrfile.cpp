#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    int SIZE = 5;
    int arr[SIZE];
    for (int i=0; i<SIZE; i++) arr[i] = i*i;
    ofstream outfile("Test.txt", ios::binary | ios::app);
    for (int i=0; i<SIZE; i++) outfile.write(reinterpret_cast<char*>(arr+i), sizeof(arr[0]));
    cout << "Данные записаны" << endl;
    outfile.close();

    for (int i=0; i<SIZE; i++) arr[i] = 0;

    ifstream infile("Test.txt", ios::binary);
    for (int i=0; i<SIZE; i++) 
    {
        infile.read(reinterpret_cast<char*>(arr+i), sizeof(arr[0]));
        cout << arr[i] << ' ';
    }
    cout << endl;
    return 0;
}