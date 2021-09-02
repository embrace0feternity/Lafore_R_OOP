#include <iostream>
#include <vector>

int main()
{
    using namespace std;
    vector<int> victor = { 9, 4, 12, 42, 29, 300, -65 };
    vector<int>::iterator head = victor.begin();
    vector<int>::reverse_iterator tail = victor.rbegin();
    ++tail;
    for (int i=0; i<victor.size()/2; i++)
        swap(*head, *tail);
    
    cout << "Размер виктора: "<< victor.size() << ". Его объём: " << victor.capacity() << endl;
    for (int i : victor) cout << i << ' ';
    cout << endl;
    return 0;
}