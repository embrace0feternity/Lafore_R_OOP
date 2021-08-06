#include <iostream>
using namespace std;

class Stack
{
protected:
    enum { SIZE = 3 };
    int top;
private:
    int arr[SIZE]; 
public:
    Stack (): top(-1) { cout << "\tStack const on" << endl; }
    ~Stack() { cout << "\tStack destr on" << endl; }
    void push(int data) { arr[++top] = data; }
    int pop() { return arr[top--]; }
};  

class Stack2:public Stack
{
public:
    void push(int data)
    {
        if (top >= SIZE) { cout << "Error > Size" << endl; exit(0);}
        else Stack::push(data);
    }
    int pop()
    {
        if (top < 0) { cout << "Error < 0" << endl; exit(0); }
        else Stack::pop();
    }
};


int main()
{
    Stack2 s;

    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    return 0;
}
