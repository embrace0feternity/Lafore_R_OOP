#include <iostream>
#include <string>
#include <regex>
#include <sstream>
#include <memory>
#include <deque>

// Все выводы программы, кроме результата, предназначены для меня, для более простого дебага. Я их не стал удалять

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

/*
    Теперь я буду использовать не стек, а stlвский контейнер. Выбор был между декой и вектором,
    потому что они имеют итератор произвольного доступа, а в листах двунаправленный итератор.
    Выбрал деку потому что операции вставки/удаления в произвольном месте в деке быстрее чем в векторе
*/

class Line  // Класс для работы с выражением
{
private:
    int length;
    std::string str;
public:
    Line(std::string s): str(s) { length = s.length(); }
    void parse(std::deque<std::shared_ptr<Token> > &deq); // Только разбиение строки
    void tempResult(std::deque<std::shared_ptr<Token> > &deq); // Определение промежуточных и итогового результатов
};

class Exceptions // исключения
{
public:
    std::string what;
    Exceptions(const std::string str): what(str) { }
};

int getPriority(char ch);

void Line::parse(std::deque<std::shared_ptr<Token> > &deq)
{
    // Регулярка формата 1 || 1.3, т.е. только число
    std::regex regexNumber("^(\\d+\\.?)(\\d+)?"); 
    // Регулярка операторов
    std::regex regexOperator("^([+-/*\\(\\)])");
    int length = str.length();
    std::string strNumber, strOperator; // строки для чисел и операторов
    
    std::smatch m; // Содержит инфу о найденных совпадениях
    while(!str.empty()) // до конца строки
    {
        // Ищю в строке str регулярку числа. m - smatch - содержит рез поиска. 
        if (std::regex_search(str, m, regexNumber)) 
        {
            strNumber = m.str(); // Вывел результат в строку 
            
            str.erase(0, strNumber.length()); // Удалил найденное число из строки
            std::cout << "Строки-число: "<< strNumber << std::endl;
            std::cout << "Исходная строка: " << str << std::endl;

            // Буфер-поток. 
            std::stringstream ss;   double number;
            ss << strNumber; // Записываю в поток строку-число
            /*
                Вывожу ЧИСЛО из буфера. (число получилось преобразованием string в double). Проблема такого
                преобразования - точность. Выводится только 3 знака после запятой.
            */
            ss >> number; 
            // Умный указатель чтобы не думать об отчистке памяти
            std::shared_ptr<Number> pNumber(new Number(number));
            std::cout << "pNumber->getNumber: " << pNumber->getNumber() << std::endl;
            deq.push_back(pNumber); // Запись указателя в деку
            std::cout << std::endl;
        }
        else
        {
            std::regex_search(str, m, regexOperator); // Тоже самое с оператором....
            strOperator = m.str();
            
            // ((1+3)*2-3)*1
            str.erase(0, strOperator.length());
            std::cout << "Строка-оператор: "<< strOperator << std::endl;
            std::cout << "Исходная строка: " << str << std::endl;
            
            std::shared_ptr<Operator> pOperator(new Operator(strOperator[0]));
            std::cout << "pNumber->getNumber: " << pOperator->getOperator() << std::endl;
            deq.push_back(pOperator);
            // Как только встречаю закрывающуюся скобку, начинаю промежуточный (скобочнный) расчёт
            if (strOperator == ")")  
            {
                for (const std::shared_ptr<Token> &i : deq) std::cout << i->getNumber() << ' ' << i->getOperator() << std::endl;        
                tempResult(deq); // вызываю функцию вычисления
            }
        }
    }
    for (auto const &i : deq) std::cout << i->getNumber() << ' ' << i->getOperator() << std::endl;
    tempResult(deq);     
 }

void Line::tempResult(std::deque<std::shared_ptr<Token> > &deq)
{
    double sNumber, fNumber;   char lastOperator='a', op;
    int brPos = 0;    
    
    /*
        2 варианта:
        идти с начала или с конца. С конца у меня реализовать не получилось)
        Поэтому пошел с начала. В смысле с начала?
        (1+2+3) = ( 1 + 2 + 3 ) - если идти с начала
        (1+2+3) = ) 3 + 2 + 1 ( - если идти с конца
        Для правильного рассчёта скобочного выражения нужна найти открывающуюся скобку
    */
    
    /*
        Реверс итератор на самый первый (с конца) элемент деки.
        Предпочёл реверс вместо обычного итератора только потому, что...
        ... 1000 элементов + ((4 + 3 + ... еще 1000 элементов
        Проще пройти с конца выражения до первой скобки '(',
        чем топать с начала выражения, перебирая каждую скобку, при этом не зная,
        это последняя скобка или нет. 
    */
    std::deque<std::shared_ptr<Token> >::reverse_iterator iter = deq.rbegin();
    for (iter; iter != deq.rend(); iter++) // иду до тех
    {
        std::shared_ptr<Token> test = *iter;
        if (test->getOperator() == '(') { break; } // Нашел скобку
        brPos++; // Позиция скобки '('
    }
    int i;
    /*
        Позиция начала скобочного выражения. А если скобок в выражении нет, то позиция = 0, 
        тк brPos будет совпадать с длиной выражения.
    */
    i = deq.size() - brPos; 
    while(deq.size() != 1 && i < deq.size()) 
    {   
        if ((sNumber = deq[i]->getNumber()) == 0) break; // Первое число
        if ((lastOperator = deq[i+1]->getOperator()) == ')') break; // Первый оператор
        fNumber = deq[i+2]->getNumber(); // Второе число
        if (deq.size()-i>3) op = deq[i+3]->getOperator(); else op = ')'; // Второй оператор
        std::cout << "sNumber: " << sNumber << "\tlastOperator: "
            << lastOperator << "\tfNumber: " << fNumber << std::endl;
        if ((getPriority(lastOperator) <= (getPriority(op))) || op == ')') // Просмотр уровней приоритета
        { 
            /*
                Если можно произвести вычисления, т.е приориотеты выполняются, то удаляю
                из деки 2 числа и первый оператор
            */
            deq.erase(deq.begin()+i, deq.begin()+i+3); 
            std::cout << "Size: " << deq.size() << std::endl;
            for (const std::shared_ptr<Token> &i : deq) std::cout << i->getNumber() << ' ' << i->getOperator() << std::endl;        
            
            // Тут считаю        
            if (lastOperator == '+') fNumber = (fNumber + sNumber);
            else
            if (lastOperator == '-') fNumber = (sNumber-fNumber);
            else
            if (lastOperator == '*') fNumber = (sNumber * fNumber);
            else
            if (lastOperator == '/') fNumber = (sNumber / fNumber);
            std::cout << fNumber << std::endl;
            std::shared_ptr<Token> pNumber(new Number(fNumber));
            
            // И вставляю результат расчёта в деку
            deq.insert(deq.begin()+i,pNumber);
            std::cout << "Size: " << deq.size() << std::endl;
            brPos -= 2; 
            i = deq.size() - brPos; // Начинаю снова с того же места, где стоит скобка '('
            // Алгоритм выполняется до тех пор, пока в скобках не останется 1 числа. 
            for (const std::shared_ptr<Token> &i : deq) std::cout << i->getNumber() << ' ' << i->getOperator() << std::endl;         
        }   
        else i += 2; // Если приоритеты не выполняются, пропускаю число и оператор и перехожу к след. паре
    }
    /*
        Если в выражении были скобок, при этом длина выражения не равна 1,
        т.е скобочное выражение равно такому: ... - (1+1) = .. - (2)
    */
    if (deq.size() != 1 || i != 0) 
    {
        deq.pop_back(); // Удаляю скобку ')'
        deq.erase(deq.begin()+deq.size()-2, deq.begin()+deq.size()-1); // Удаляю скобку '('
    }
    std::cout << "Возврат:\n-----------------------------------------------------\n";
    for (const std::shared_ptr<Token> &i : deq) std::cout << i->getNumber() << ' ' << i->getOperator() << std::endl;
    std::cout << "Возврат:\n-----------------------------------------------------\n";
}

int getPriority(char ch)
{
    if (ch == '(' || ch == ')') return 1;
    else
    if (ch == '*' || ch == '/') return 2;
    else
    if (ch == '+' || ch == '-') return 3;
    return 0;
}

int main()
{
    std::cout << "Запишите выражение: " << std::endl;
    std::string str;
    
    while(true)
    {
        getline(std::cin, str);        
        unsigned int length = str.length();
        try
        {
            if (length < 3) throw Exceptions("Невозможно посчитать. Выражение слишком мало!");
            int lbrack=0, rbrack=0;
            for (int i=0; i<length; i++)
            {
                if (str[i] == '(') lbrack++;
                else
                    if (str[i] == ')') rbrack++;
                if (rbrack > lbrack) throw Exceptions("Ошибка. Закрывающая скобка не может идти раньше открывающейся!");
            }
            if (rbrack != lbrack) throw Exceptions("Кол-во скобок не совпадает");
        }
        catch(Exceptions& e)
        {
            std::cerr << e.what << '\n';
            std::cout << "Попробуйте ввести еще раз" << std::endl;
            continue;
        }
        break;
    }
    std::deque
    <std::shared_ptr<Token> > deq;
    Line test(str);
    test.parse(deq);
    double result = deq[0]->getNumber();
    std::cout << "Результат равен "<< result << std::endl;
    deq.pop_back();
    return 0;
}


// 1)        (5-2)*6+2-(2+3)*2 = 10                                   +
// 2)        (((1+1))+1) = 3                                          +
// 3)        ((((1+1)))) = 2                                          +   
// 4)        ((25-5)*5+100)+300 = 500                                 +
// 5)        (100-50*10+1000-100) = 500                               +
// 6)        ((1-2)*5+10) = 5                                         +
// 7)        25*10/5-10*3-5 = 15                                      +
// 8)        1000-100*2*2+400/2-200+900 = 1500                        +
// 9)        100-5*4-20-5-5+50*3+100*2*3/20 = 200 + 30 = 230          +
// 10)       10+10*20-5 = 205                                         +
// 11)       10.5+18.9*23.5-4.65 = 450                                +
// 12)       10000/10/10/10*100/10/10/10 = 1                          +
// 13)       10000/1000/10 = 1                                        +
// 14)       10000/10/1000 = 1                                        +
// 15)       10000/1000+2000-1500-200-100/2-50 = 210                  +
// 16)       1000-100-200-100-200 = 400                               +
