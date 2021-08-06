#include <iostream>
using namespace std;

class stack
{
    static const int MAX = 10;
    int st[MAX];
    int top;
public:
    stack():top(0) {}
    void push(int data) { st[top++]= data; }
    int pop() { return st[--top]; }
};

int main()
{
    stack s1;
    s1.push(111);
    s1.push(211);
    cout << "1: " << s1.pop() << endl;
    cout << "2: " << s1.pop() << endl;
    return 0;
    
}
