#include <iostream>

template <typename T>
class Stack
{
private:
    T arr[100];
    int top;
public:
    Stack(): top(-1) { }
    void push(T data) { arr[++top] = data; }
    T pop() { return arr[top--]; }
};

int main()
{
    Stack<float> st1;
    st1.push(12.3);
    st1.push(5.12);
    st1.push(76.3);
    for (int i=0; i<3; i++) std::cout << st1.pop() << std::endl;

    Stack<int> st2;
    st2.push(2);
    st2.push(6);
    st2.push(14);
    for (int i=0; i<3; i++) std::cout << st1.pop() << std::endl;
    return 0;
}