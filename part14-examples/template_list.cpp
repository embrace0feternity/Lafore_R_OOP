#include <iostream>

template <typename T>
class cell
{
public:
    T data;
    cell *next;
};

template <typename T>
class linklist
{
private:
    cell<T> *first;
    int top;
public:
    linklist(): first(nullptr), top(0) { }
    ~linklist();
    
    void push(T data);
    void pop();
    void showList()const;
};

template <typename T>
linklist<T>::~linklist()
{
    while(first)
    {
        cell<T> *temp = first;
        first = temp->next;
        delete[] temp;
        top--;
    }
}

template <typename T>
void linklist<T>::push(T data)
{
    cell<T> *temp = new cell<T>;
    temp->data = data;
    temp->next = first;
    first = temp;
    top++;
}

template <typename T>
void linklist<T>::pop()
{
    cell<T> *temp = first;
    first = temp->next;
    delete[]temp;
    top--;
}

template <typename T>
void linklist<T>::showList()const
{
    cell<T>* temp = first;
    while(temp)
    {
        std::cout << temp->data << std::endl;
        temp = temp->next; 
    }
}

int main()
{
    const int SIZE = 5;

    linklist<int> list1;
    for (int i=0; i<SIZE; i++) list1.push(i*i);
    list1.showList();
    std::cout << "------------------------" << std::endl;
    for (int i=0; i<SIZE-2; i++) list1.pop();
    list1.showList();

    std::cout << std::endl << std::endl;

    linklist<char> list2;
    for (int i=0; i<SIZE; i++) list2.push('a'+i);
    list2.showList();
    std::cout << "------------------------" << std::endl;
    for (int i=0; i<SIZE-2; i++) list2.pop();
    list2.showList();
    return 0;
}