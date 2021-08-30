#include <iostream>
using namespace std;

class employee
{
protected:
    enum { SIZE = 20 };
    char arr[SIZE];
    unsigned int number;
public:
    employee() {}
    friend istream& operator >> (istream &, employee &);
    friend ostream& operator << (ostream &, employee &);
};

istream& operator >> (istream &in, employee &other)
{
    std::cout << "Имя: ";
    in >> other.arr; 
    std::cout << "Номер: ";
    in >> other.number;
    return in;
}

ostream& operator << (ostream &out, employee &other)
{
    out << "Имя: " << other.arr << "\tНомер: " << other.number << std::endl;
    return out;
}

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
    class cell
    {
    public:
        T data;
        cell *next;
    };
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
    employee empl1[SIZE];
    linklist<employee> list1;
    
    for (int i=0; i<SIZE; i++) { std::cin >> empl1[i]; list1.push(empl1[i]); }
    list1.showList();
    std::cout << "------------------------" << std::endl;
    for (int i=0; i<SIZE-2; i++) list1.pop();
    list1.showList();

    return 0;
}