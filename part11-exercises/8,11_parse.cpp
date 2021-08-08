/*
    Реализовать упрощенный вариант польской строки (без скобок). Числа выражения имеют тип float. 
    Все остальное в книге (пример каркаса).
    Также я заимствовал код из примера parse главы 10
*/

#include <iostream>
#include <string.h>


class Token // Абстрактный класс
{
public:
    virtual char getOperator()=0;
    virtual double getNumber()=0;
};

class Number : public Token // класс для хранения вещественных составляющих стека
{
private:
    double num;
public:
    Number(double n): num(n) {  }
    char getOperator() override { return ' '; } // Фиктивная функция
    double getNumber() override { return num; }
    
};

class Operator : public Token // Класс для хранения символьных составляющих стека
{
private:
    char sign;
public:
    Operator(char ch): sign(ch) {  }
    char getOperator() override { return sign; }
    double getNumber() override { return 0.0; } // Фиктивная функция
};

class Stack
{
private:
    int top;
    Token *st[15]; /* Создал массив на 15 элементов, в котором храню указатели на производные от абстрактного класса
        объекты*/
public:
    Stack(): top(-1) {  }

    int getSize() { return top; }

    void push(Token *data) { st[++top] = data; }
    Token* pop() { return st[top--]; }
    
};

class Line  // Класс для работы с выражением
{
private:
    int length;
    std::string str;
public:
    Line(std::string s): str(s) { length = s.length(); }
    bool parse(Stack *stack);
    double calculateRetult(Stack *stack);
};

bool Line::parse(Stack *stack)
{
    if (length = 0) { std::cout << "Вы ничего не ввели!" << std::endl; return false; }
    /* 
        pos - начало числа в строке;     number - строка, в которой будет хранится это число;
        temp - вещественное число, полученное из строки;
        
        n1 - указатель на объект, в котором будет хранится вещественное значение;
        op1 - указатель на объект, в котором будет хранится оператор;
        lastNumber - указатель на объект типа Number. lastOperator - указатель на объект типа Operator;
    */
    int pos=0;    char* strNumber = new char[length];    double temp;
    Number *n1;   Operator *op1;    Token* lastNumber;   Token* lastOperator;


    for (int i=0; str[i]!='\0'; i++)
    {
        // Если след символ - оператор (или конец строки), то предыдущие символы, начиная с pos, это число
        if (str[i+1] == '+' || str[i+1] == '-' || str[i+1] == '/' || str[i+1] == '*' || str[i+1] == '\0') 
        { 
            // Копируем i-pos символов (число в исходной строке str) из строки (str) в новую строку (number)
            int j = pos;
            for (; j<=i; j++)  strNumber[j-pos] = str[j]; 

            strNumber[j-pos] = '\0';      
            pos = i + 2; // Закончилось число, оператор и след символ это начало числа

            temp = atof(strNumber);       // Преобразуем строку-число в вещественное число
            n1 = new Number(temp);    // Создаём объект, помещаем в стек
            stack->push(n1);
        }
        else 
        if (str[i] == '+' || str[i] == '-' || str[i] == '/' || str[i] == '*')
        {
            
            if (stack->getSize() == 0) // Если это первый оператор - кидаем его в стек
            {
                op1 = new Operator(str[i]);
                stack->push(op1);
            }
            else    // А если нет - достаем из стека 2 элемента
            {
                lastNumber = stack->pop();
                lastOperator = stack->pop();
                /*
                    Если операция умножения/деления предшествует сложению/вычитанию, то считаем произведение/частное.
                    Иначе обратно помещаем элементы в стек, потому что считать сумму/разность пока не вычислим
                    произведение/частное (вот пример 3+6/2)
                */
                if ((lastOperator->getOperator() == '+' || lastOperator->getOperator() == '-') 
                         && (str[i] == '*' || str[i] == '/'))
                {
                    stack->push(lastOperator);
                    stack->push(lastNumber);
                } // Иначе выполняем промежуточное вычисление
                else
                {
                    double buff;    // Буфер для промежуточного вычисления
                    char ch = lastOperator->getOperator();
                    Token *temp = stack->pop();
                    if (ch == '+') buff = (temp->getNumber() + lastNumber->getNumber());
                    else
                    if (ch == '-') buff = (temp->getNumber() - lastNumber->getNumber());
                    else
                    if (ch == '*') buff = (temp->getNumber() * lastNumber->getNumber());
                    else
                    if (ch == '/') buff = (temp->getNumber() / lastNumber->getNumber());
                    else 
                    {
                        std::cout << "Введен отличный от разрешенных оператор" << std::endl;   
                        exit(1);
                    }
                    delete n1;      // Освобождаем память уже использованных элементов
                    delete lastOperator;
                    delete temp;
                    n1 = new Number(buff); 
                    stack->push(n1);     // Записываем в стек новый элемент (посчитанный результат)
                }
                op1 = new Operator(str[i]); 
                stack->push(op1); // Записываем текущий оператор в стек.
            }
        }
    }
    return true;    
}

double Line::calculateRetult(Stack *stack)
{
    if (parse(stack))
    {
        // Выполнять, пока в стеке не будет 1 элемент - результат
        Token *lastNumber;    Token *lastOperator;
        while (stack->getSize() != 0)
        {
            lastNumber = stack->pop();
            lastOperator = stack->pop();
            double buff;    
            char ch = lastOperator->getOperator();
            Token *temp = stack->pop();
            if (ch == '+') buff = (temp->getNumber() + lastNumber->getNumber());
            else
            if (ch == '-') buff = (temp->getNumber() - lastNumber->getNumber());
            else
            if (ch == '*') buff = (temp->getNumber() * lastNumber->getNumber());
            else
            if (ch == '/') buff = (temp->getNumber() / lastNumber->getNumber());
            else 
            {
                std::cout << "Введен отличный от разрешенных оператор." << std::endl;   
                exit(1);
            }
            delete lastNumber;  
            delete lastOperator;
            delete temp;
            Number *n1 = new Number(buff); 
            stack->push(n1);   
        }
    }
    else
    {
        std::cout << "У вас ошибка в выражении." << std::endl;
        return 0;
    }
    return (stack->pop()->getNumber());
}

int main()
{
    std::cout << "Запишите выражение: " << std::endl;
    std::string str;
    getline(std::cin, str);

    Stack st;
    
    Line test(str);
    std::cout << test.calculateRetult(&st) << std::endl;
    return 0;
}

/*
2+8.39*6.31
2.5*8+7.5*2/5
*/