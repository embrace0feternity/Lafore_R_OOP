#include <iostream>
#include <array>
#include <set>
#include <vector>
#include <algorithm>

int main()
{
    using namespace std;
    array<int, 5> arr = { 2, 6, 84, 46, 4 };
    set<int> three = { 65, 139, 55, 43 };

    vector<int> victor(9);

    merge(arr.begin(), arr.end(), three.begin(), three.end(), victor.begin());
    cout << "Размер виктора: "<< victor.size() << ". Его объём: " << victor.capacity() << endl;
    for (int i : victor) cout << i << ' ';
    cout << endl;
    return 0;
}