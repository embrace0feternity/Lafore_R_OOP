#include <iostream>
#include <list>
#include <algorithm>

int main()
{
    using namespace std;
    list<int> lst = { 3, 6, 8, 2, 9, 14, -5 };
    list<int>::iterator first = lst.begin();
    list<int>::iterator last = lst.end();
    --last;
    while(first != last){
        swap(*first, *last);
        first++;
        if (first == last) break;
        last--;
    }
    for (const auto &i : lst) cout << i << ' ';
    cout << endl;

    return 0;
}