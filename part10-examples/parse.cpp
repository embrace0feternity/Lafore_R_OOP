#include <iostream>
#include <string.h>
using namespace std;

class Stack
{
protected:
    static const int SIZE=20;                   
    char st[SIZE];          
    int top;                                    
public:
    Stack(): top(0) { }
    void push(int data) { st[++top] = data; }
    int pop() { return st[top--]; }
    int getSize() { return top; }       // it need below to calculate how many elements are contained in stack;
};

class expression : public Stack 
{
private:
    char *expr;     // user`s expression
    int len;        // it`s length
public:
    expression(char *str): Stack() { expr = str; len = strlen(expr); } // insted inheritance can use field "Stack s"
    void parse();           // calculeting
    int solution();         // total result;
}; 

void expression::parse()
{
    char ch;                // current symbol
    char lastoperator;      
    char lastvalue;
    for (int i=0; i<len; i++)
    {
        ch = expr[i];
        if (ch>='0' && ch<='9') push(ch-48); // 48 = '0'
        else if (ch == '+'|| ch == '-' || ch == '*' || ch == '/')
        {
            if (getSize() == 1) push(ch); // if this is a figure, throw it away in stack;
            else
            {
                /*
                    else if i find second operand, take 2 last stack`s elements.
                    3+6*5;
                    there will be taken 6 and '+'. 3 will be still in stack
                */
                lastvalue = pop();
                lastoperator = pop();
                // 3+6*5. '*' and '/' has more priority than '+' and '-'
                if ((ch == '*' || ch == '/') && (lastoperator == '-' || lastoperator == '+'))
                {
                    push(lastoperator);     // throw in stack 2 last elements;
                    push(lastvalue);
                }
                /* else i have expression like this "3*6+5", only one element is being in stack; it is '3'
                '6' and '*' aren`t there */
                else
                {
                    switch (lastoperator)
                    {
                    case '+':
                        push(pop() + lastvalue);    // take 3 from stack and + 6. Temporary res put in stack                 
                        break;
                    case '-':
                        push(pop() - lastvalue);    // -//-              
                        break;
                    case '*':
                        push(pop() * lastvalue);    // -//-                
                        break;
                    case '/':
                        push(pop() / lastvalue);    // -//-                 
                        break;
                    default:
                        cout << "---ERROR---" << endl;
                        exit(1);
                    }
                }
                push(ch); // put last operator. If i have 3*6+5 i put '+' in stack
            }
        }
        else
        {
            cout << "Unknown symbol" << endl;
            exit(1);
        }
    }
}

int expression::solution()
{
    /*
        in this function i calculate total result.
        In previous function i calculeted this: "18+5"
    */
    char lastvalue;
    char lastoperator;
    while (getSize()>1)
    {
        lastvalue = pop();              // i take 2 elements from stack: '5' and '+'
        lastoperator = pop();
        switch (lastoperator)
                    {
                    case '+':
                        push(pop() + lastvalue);    // + 18 and put result in stack                  
                        break;
                    case '-':
                        push(pop() - lastvalue);                      
                        break;
                    case '*':
                        push(pop() * lastvalue);                      
                        break;
                    case '/':
                        push(pop() / lastvalue);                      
                        break;
                    default:
                        cout << "---ERROR---" << endl;
                        exit(1);
                    }
        
    }
    // i have only 1 element in stack and it is my total result
    return int(pop()); // return total result
}

int main()
{
    char answer='a';
    const int SIZE = 20;
    char str[SIZE];
    cout << "Write an expression for example: \'3+6/7-7*1\'" << endl;
    do
    {
        cin >> str;
        expression *expr = new expression(str);
        expr->parse();
        cout << "Result: " << expr->solution() << endl;
        cout << "Would u like to calcule one more time? "; cin >> answer;
    } while (answer == 'y' || answer == 'Y');
    cout << "buy" << endl;
    return 0;
}
