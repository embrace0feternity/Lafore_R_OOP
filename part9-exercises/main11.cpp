#include <iostream>
using namespace std;

class point
{
private:
    int x;
    int y;
public:
    point(): x(0), y(0) { }

    void set(int x, int y) { this->x = x; this->y = y; }
    void show()const { cout << x << ' ' << y << endl; }

};

class Stack
{
protected:
    enum { SIZE = 3 };
    int top;
private:
    point arr[SIZE]; 
public:
    Stack (): top(-1) { cout << "\tStack const " << this << endl; }
    ~Stack() { cout << "\tStack destr " << this << endl; }
    void push(point &other) { arr[++top] = other; }
    point pop() { return arr[top--]; }
};  

class Stack2  :  private Stack
{
public:
    Stack2(): Stack() { }
    void push(point &other)
    {
        if (top >= SIZE) { cout << "Error > Size" << endl; exit(0);}
        else Stack::push(other);
    }
    point pop()
    {
        if (top < 0) { cout << "Error < 0" << endl; exit(0); }
        else return Stack::pop();
    }
};

class pairStack  :  private Stack2
{
private:
    point coord;
public:
    pairStack(): Stack2() { }
    void push(int x, int y) { coord.set(x,y); Stack2::push(coord); }
    void pop(); 
};
void pairStack::pop()
{
    point temp = Stack2::pop();
    temp.show();
}

int main()
{
    pairStack coordinate;
    coordinate.push(3,4);
    coordinate.push(13,465);
    coordinate.push(33,44);
    coordinate.pop();
    coordinate.pop();
    coordinate.pop();
    return 0;
}
