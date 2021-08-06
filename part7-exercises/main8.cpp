#include <iostream>
using namespace std;

class safearray
{
private:
    enum {SIZE = 100};
    int arr[SIZE];
public:
    void putel(int &i, int &el)
    {
        if (i>=0 && i<=SIZE) arr[i]=el; else cout << "Out of array. Try again" << endl; 
    }
    int getel(int &i) { if (i>=0 && i<=SIZE) return arr[i]; }
};

int main()
{
    int choose=1, index, data;
    safearray arr;
    while(choose!=0)
    {
        cout << "What do you want to do? Get array data or write data in array..." << endl;
        cin >> choose;

        if (choose == 1)
        {
            cout << "Write an index of array the will be filled: ";        cin >> index;
            cout << endl << "Write data which will be in array: ";         cin >> data;
            arr.putel(index,data);
        }
        else if (choose == 2)
        {
            cout << endl << "Write an index of array the will be filled: ";        cin >> index;
            cout << arr.getel(index) << endl;
        }
    }
    return 0;
}