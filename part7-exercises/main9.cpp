#include <iostream>
#include <conio.h>
using namespace std;

class queue
{
    const static int SIZE = 3;
    int array[SIZE];
    int head, chead;
    int tail, ctail;
public:
    queue(): head(0), tail(0), chead(0), ctail(0) { for (int i=0; i<SIZE; i++) array[i]=0; }
    void put(int data) 
    {   
        chead++;
        if (head == SIZE) head=0;
        array[head++] = data; 
    }

    void get() 
    { 
        if (chead == ctail) { chead = ctail = 0; cout << "Nothing" << endl; }
        else 
        {   
            if (tail == SIZE) tail=0;
            cout << array[tail++] << endl;
            ctail++;
        }   
    }
};

int main()
{
    queue q;
    char ch='a';
    cout << "1. Put to array\n2. Get from array\nsmth else. Exit" << endl;
    while ((ch = getch())!= 13)
    {
        switch (ch)
        {
        case '1':
            int data;
            cout << "What do u want to add? ";            cin >> data; 
            q.put(data);
            break;
        case '2':
            cout << "You get "; 
            q.get();
            break;
        default:
            break;
        }
    }
    return 0;
}