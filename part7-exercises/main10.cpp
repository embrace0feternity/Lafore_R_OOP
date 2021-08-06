#include <iostream>
#include <random>
#include <time.h>
using namespace std;

class matrix
{
    int rows, colums;
    int **arr;
public:
    matrix(const int &r, const int &c); 
    ~matrix();
    
    void put();
    int get(int r, int c) { return arr[r][c]; }

};
matrix::matrix(const int &r, const int &c)
{
    rows = r; colums = c;
    arr = new int*[rows];
    for (int i=0; i<rows; i++)        *(arr+i) = new int[colums];
} 
matrix::~matrix()
{
    for (int i=0; i<rows; i++) delete[] *(arr+i);
    delete[]arr;
}


void matrix::put()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < colums; j++)
        {
            arr[i][j] = rand()%9+1;
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    } 
}

int main()
{
    srand(time(0));
    int rows, colums, data;
    cout << "Write size of matrix:\n rows number: "; cin >> rows;
    cout << " colums number: "; cin >> colums; 
   
    matrix m(rows, colums);
    cout << endl << endl;
    m.put();

    int temp1, temp2;

    for (int i=0; i<(rows*colums)/2; i++) 
    {
        temp1 = -1 + rand()%rows+1;
        temp2 = -1 + rand()%colums+1;
        cout << i+1 << "-й по счёту символ: " << m.get(temp1,temp2) << endl;
    }
    return 0;
}