#include <iostream>
#include <string.h>
#include <cstdlib>

using namespace std;

int isFree(string str);

class Distance
{
private:
    int feet;
    float inches;
public:
    Distance(): feet(0), inches(0.0) { }
    Distance(int f, float i): feet(f), inches(i) { }
    void setDistance();

    friend ostream& operator<< (ostream &out, Distance &other);
};

void Distance::setDistance() // получение длины от пользователя
{
    string str;
    while(true)
    {
        cout << "Введите футы: "; 
        cin.unsetf(ios::skipws);
        cin >> str; // Получаю футы как строку. Если будет введено дробное значение, пользователь получит сообщение об этом 

        if (isFree(str)) // Проверка строки. Если все правильно...
        {
            cin.ignore(20, '\n');   // убираем из буфера 20 символо, включая '\n'
            feet = atoi(str.c_str()); // перевод строки в инт
            break;
        }
        // Иначе очищаем буфер и выводим смс об ошибке.
        cin.ignore(20, '\n');
        cerr << "Футы должны быть целым числом!" << endl; 
    }
    while(true)
    {
        cout << "Введите дюймы: ";
        cin.unsetf(ios::skipws);
        cin >> inches;
        if (inches < 0 || inches >= 12)
        {
            cerr << "1 дюйм должен быть от 0 до 11.99" << endl;
            cin.clear(ios::failbit); // Имитировать ошибку
        }
        if (cin.good()) // Ввод правильный?
        {
            cin.ignore(20, '\n');
            break; 
        }
        cin.clear(); // Очищам байт флагов. Теперь ошибок нет
        cin.ignore(20, '\n'); // Съедам буффер
        cout << "Неправильный ввод дюймов" << endl;
    }
}

ostream& operator<< (ostream &out, Distance &other)
{
    out << "Distance: " << other.feet << '-' << other.inches;
    return out;
}

int isFree(string str)
{
    int len = str.length(); 
    if (len == 0 || len > 10) // Если ничего не введено или введено слишком много символов
        return 0;   
    for (int i=0; i<len; i++)
        if (str[i] < '0' || str[i] > '9') 
        {
            cout << "Вы, вероятно, вводите не целочисленное значение" << endl;
            return 0; // Если встречаем символ, отличный от нуля - ошибка
        }
    return 1;    
}

int main()
{
    Distance d1;
    int i=5;
    while(i--)
    {
        d1.setDistance();
        cout << d1 << endl;
    }
    return 0;
}