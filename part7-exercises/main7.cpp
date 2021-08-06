#include <iostream>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <iomanip>
using namespace std;

#define ENTER 13

class money
{
private:
    char *str;          // Входная строка
    char *alternaty;    // Выходная (без ',', '$')
public:
    money(const char *s) { strcpy(str,s); }
  //  ~money() { delete[]alternaty; }
    long double mstold(void);
};

long double money::mstold(void)
{
    /*
        Темп это массивчик, в котором собраны все элементы, которые могут быть в лонг дабле.
    */
    char temp[] {'.','0','1','2','3','4','5','6','7','8','9'};
    int n = strlen(str);
    alternaty = new char[n]; // выделяется память под итоговую строку
    int count=0;
    // В итоговую строку засовываем только те символы, которые имеются в temp. 
    // Брейк нужен для того, чтобы лишний раз не проходится по циклу, когда условие выполнено
    for (int i=0; i<n; i++)
        for (int j=0; j<11; j++)
            if (str[i]==temp[j]) 
            {
                alternaty[count] = str[i];
                count++;    break;
            }
    // Закидываем символ окончания стркои в массивчик
    alternaty[count] = '\0';
    cout << alternaty << endl;
    // stold - преобразует стринг в лонг дабл
    return stold(alternaty);
}

char* write(void)
{
    /*
        im это первая строка. Она вспомогательная, чтобы только чекать поток.
    */
    char *im = new char[256];     int i=1;      char ch = 'a'; 
    im[0]='$';   //Выводим символ доллара   
    cout << "How much money do u have? " << im[0];
    
    /* 
        А это строка, под которую выделено памяти как раз под нужный поток.
        Нужный поток содежит цифры, точку, запятыЕ, доллар. 
        В потоке запрещён ввод всего остального. 
        Этот поток помещается в "мнимый" массив
        Реальный массив, re, имеет в распоряжении память, как раз под нужный поток.
    */
    char *re; 
    while ((ch=getch())!=ENTER) 
    {
        if ((ch <= '9' && ch >= '0') || ch=='.' || ch==',') 
        { 
            im[i] = ch;
            cout << im[i];
            i++;
        }
    }
    re = new char[i];
    for (int j=0; j<i; j++) re[j]=im[j]; 
    re[i] = '\0';
    cout << endl << strlen(re) << ' ' << i << endl;
    delete[]im;
    return re;
}

int main(int arc, char **argv)
{
    char *str = write();
    money line1(str);
    /* 
        Ниже это флажки манипуляторы. fixed - означает вывод с плавающей точкой. 
        showpoint - генерирует символ с десятичной запятой.    
        setprecision - сколько символов после точки выводить
    */
    cout << '$' << setiosflags (ios::fixed) << setiosflags (ios::showpoint) << setprecision(7)
           << "\n" << line1.mstold() << endl;
    return 0;
}