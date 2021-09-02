#include <iostream>
#include <string.h>

/*
        В стеке нельзя просто так хранить разные типы данных. Потому что стек - по сути, массив. 
    Типы данных не совпадают по размеру, а указатели разных типов данных, хоть и совпадают по размеру, 
    нельзя хранить в стеке (массиве). Ругается компилятор.
        Можно создать классы, каждый из которых отвечает за конкретный тип данных. Эти классы нужно сделать 
    наследниками от одного и того же базового класса. И тогда можно будет хранить в стеке указатели на разные
    типы данных (которые будут представлены производными классами), потому что указатель, который имеет тип
    базового класса, может хранить в себе указатели на объекты производных классов.
        Поскольку базовому классу не нужно хранить в себе собственные данные, можно сделать его абстрактным.
    Объекты такого класса нам не нужны.
        Еще нужно переопределить виртуальные функции базового класса во всех проиводных классах, даже 
    если функция не будет использоваться в каком-то производном классе. Она выполняет роль фиктивной функции.
    Отсутствие переопределения функций в производных классах сделает их абстрактными.
*/

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
    Number(double n): num(n) { }
    char getOperator() override { return ' '; } // Фиктивная функция
    double getNumber() override { return num; }
    
};

class Operator : public Token // Класс для хранения символьных составляющих стека
{
private:
    char sign;
public:
    Operator(char ch): sign(ch) { }
    char getOperator() override { return sign; }
    double getNumber() override { return 0.0; } // Фиктивная функция
};

class Stack
{
private:
    int top;
    Token *st[100]; /* Создал массив на n элементов, в котором храню указатели на производные от абстрактного класса
        объекты класса*/
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
            n1 = new Number(temp);    // Создаём объект, помещаем в стек указатель на объект
            std::cout << "В стек: " << n1->getNumber() << std::endl;
            stack->push(n1);
        }
        else 
        if (str[i] == '+' || str[i] == '-' || str[i] == '/' || str[i] == '*')
        {
            
            if (stack->getSize() == 0) // Если это первый оператор - кидаем его в стек
            {
                op1 = new Operator(str[i]);
                std::cout << "В стек: " << op1->getOperator() << std::endl;
                stack->push(op1);
            }
            else    // А если нет - достаем из стека 2 элемента
            {
                lastNumber = stack->pop();
                lastOperator = stack->pop();
                std::cout << lastNumber->getNumber() << ' ' << lastOperator->getOperator() << " <- из стека" << std::endl;

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
                    std::cout << "В стек: " << lastNumber->getNumber() << ' ' << lastOperator->getOperator() << std::endl;
                } // Иначе выполняем промежуточное вычисление
                else
                {
                    double buff;    // Буфер для промежуточного вычисления
                    char ch = lastOperator->getOperator();
                    Token *temp = stack->pop();
                    
                    /*
        Вот в эту ловушку я попался
                        50 - 30 - 5. Необходимо осторожно обрабатывать выражения с минусами.
                        Если из стека доставать 2 числа и оператор, то получится следующие:
                        30 - 5 = 25. Добавим в стек 25. В итоге в стеке 25, -, 50.
                        Обработка последнего вычисления даст результат 25. Это ошибка!
                        Если текущий оператор '-' (назову его ОПЕРАТОР A), то необходимо проверять еще 
                        1 оператор из стека (ОПЕРАТОР В).
                        В случае оператор В тоже равен '-', то оператор A нужно заменить с '-' на '+'.
                    */

                    if (ch == '-' && stack->getSize() != -1) 
                    {
                        Token *check = stack->pop(); // Оператор B
                        if (check->getOperator() == '-') // Равен ли он тоже '-'
                            ch = '+'; // замена на '+' оператора А
                        stack->push(check); // Возвращаю в стек оператор В, равный '-'
                    }else
                    if (ch == '+' && stack->getSize() != -1) // Если оператор А = '+' 
                    {
                        // 100 - 30 + 80
                        Token *check = stack->pop(); // достал из стека оператор B
                        if (check->getOperator() == '-') // если он равен -
                        { 
                            ch = '-'; // то А изменяю на '-'
                            Operator *op1 = new Operator('+'); // и добавляю в стек новый оператор В (вместо '-' = '+')
                            std::cout << op1->getOperator() << " <- в стек" << std::endl;
                            stack->push(op1);
                            Token* t = temp; // меняю местами указатели на объекты типа Number для правильного вычисления
                            temp = lastNumber;
                            lastNumber = t;
                        }
                        else stack->push(check);
                    }
                    std::cout << temp->getNumber() << " <- из стека" << std::endl;
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
                    std::cout << "В стек: " << n1->getNumber() << std::endl;
                    stack->push(n1);     // Записываем в стек новый элемент (посчитанный результат)
                }
                op1 = new Operator(str[i]); 
                stack->push(op1); // Записываем текущий оператор в стек.
                std::cout << "В стек: " << op1->getOperator() << std::endl;
            }
        }
    } 
    return true;    
}
// 1000 - 800 - 200
// 10000/1000+2000-1500-200-100/2-50
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
            std::cout << lastNumber->getNumber() << ' ' << lastOperator->getOperator() << std::endl;
            double buff;    
            char ch = lastOperator->getOperator();
            Token *temp = stack->pop();
            std::cout << temp->getNumber() << std::endl;

            // Это такой же блок проверки, как и в parse()
            if (ch == '-' && stack->getSize() != -1) 
            {
                Token *check = stack->pop(); 
                if (check->getOperator() == '-') 
                    ch = '+'; 
                stack->push(check); 
            }else
            if (ch == '+' && stack->getSize() != -1) 
            {
                Token *check = stack->pop();
                if (check->getOperator() == '-')
                { 
                    ch = '-';
                    Operator *op1 = new Operator('+');
                    std::cout << op1->getOperator() << " <- в стек" << std::endl;
                    stack->push(op1);
                    Token* t = temp;
                    temp = lastNumber;
                    lastNumber = t;
                }
                else stack->push(check);
            }

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
            std::cout << "В стек: " << n1->getNumber() <<  std::endl;
            stack->push(n1);   
        }
    }
    else
    {
        std::cout << "У вас ошибка в выражении." << std::endl;
        return 0;
    }
    Token *res = stack->pop(); 
    double result = res->getNumber(); // Поместил рез в переменную 
    std::cout << "Результат: ";
    delete res; // И отчистил память
    return result;
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

// 25*10/5-10*3-5 = 15
// 1000-100*2*2+400/2-200+900 = 1500
// 100-5*4-20-5-5+50*3+100*2*3/20 = 200 + 30 = 230 
// 10+10*20-5 = 205
// 10.5+18.9*23.5-4.65 = 450
// 10000/10/10/10*100/10/10/10 = 1
// 10000/1000+2000-1500-200-100/2-50 = 210
// 1000-100-200-100-200 = 400
