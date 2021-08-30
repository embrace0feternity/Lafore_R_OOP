#include <iostream>

class Stack
{
private:
    enum { SIZE = 4 };
    int arr[SIZE];
    int top;
public:
    class Range{

    };
    int n;
    Stack(): top(-1) { }
    void push(int data) { if (top >= SIZE-1) throw n; arr[++top] = data; }
    int pop() { if (top < 0) throw n; return arr[top--]; }
};

int main()
{
    Stack st1;
    try
    {
        st1.push(2);
        st1.push(6);
        st1.push(14);
        st1.push(65);
        st1.push(1);
        for (int i=0; i<3; i++) std::cout << st1.pop() << std::endl;
    }
    catch(int n)
    {
        std::cerr << "Стек переполнен или пуст!" << std::endl;
    }
    std::cout << "Конец" << std::endl;
    
    return 0;
}