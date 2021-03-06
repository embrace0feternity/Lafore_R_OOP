/*
        Создайте класс time, включающий себя целые значения часов, минут и се- 
    кунд. Напишите метод get_time(), спрашивающий время у пользователя, 
    и метод put_time(), выводящий время в формате 12:59:59. Внесите в функ- 
    цию get_time() проверку на ошибки, чтобы минимизировать возможность 
    неправильного ввода пользователем. Эта функция должна отдельно спра- 
    шивать часы, минуты и секунды, проверяя каждое введенное значение на 
    наличие флагов ошибок ios, а также проверяя, укладывается ли значение 
    в заданный диапазон. Для часов диапазон составляет от 0 до 23, а для ми- 
    нут и секунд — от 0 до 59. Не вводите данные в виде символьных строк с 
    последующим конвертированием. Вводите значения сразу же как int. Это 
    означает, что вы не сможете выявлять записи с ненужными здесь деся- 
    тичными запятыми, но это в данной программе не так важно. 
    В main() используйте цикл для получения значений времени от пользова- 
    теля функцией get_time(), затем для их вывода функцией put_time(): 

        Я ушел от условия и сделал так, как делал оч редко:  
    через указатели на функции. Мне понравилось
*/
#include <iostream>

void hours(int h)
{
    if (h>23 | h<0) 
    {
        std::cerr << "Часы должны иметь значение 0-23. ";
        std::cin.clear(std::ios::failbit);
    }
}

void minutes(int m)
{
    if (m>59 | m<0) 
    {
        std::cerr << "Минуты должны иметь значение 0-59. ";
        std::cin.clear(std::ios::failbit);
    }
}

void seconds(int s)
{
    if (s>59 | s<0) 
    {
        std::cerr << "Секунды должны иметь значение 0-59. ";
        std::cin.clear(std::ios::failbit);
    }
}

int check(void (*ptr)(int))
{
    int data;   
    while (true)
    {
        std::cin >> data;
        if (std::cin.fail())
        {
            std::cerr << "Неправильный формат. ";
        }
        (*ptr)(data);
        if (std::cin.good()) 
        {
            std::cin.ignore(100,'\n');
            return data;
        }
        std::cin.clear();
        std::cin.ignore(100,'\n');
        std::cout << "Попробуйте еще раз" << std::endl;
    }

}

int main()
{
    int h, m, s;
    void (*ptr)(int);
    std::cout << "Введите часы: ";
    ptr = hours;
    h = check(ptr);
    
    std::cout << "Введите минуты: ";
    ptr = minutes;
    m = check(ptr);
    
    std::cout << "Введите секунды: ";
    ptr = seconds;
    s = check(ptr);

    if (h<10) std::cout << "0";
    std::cout << h << ':';
    
    if (m<10) std::cout << "0";
    std::cout << m << ':';
    
    if (s<10) std::cout << "0";
    std::cout << s << std::endl;
    
    return 0;
}