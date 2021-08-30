/*
        Рассмотрите класс Distance из программы ENGLCON, глава 6 «Объекты и 
    классы». Используя цикл, аналогичный приводимому в программе DISKFUN 
    в этой главе, получите несколько значений от пользователя и запишите 
    их в файл. Добавьте их к уже записанным там данным (при их наличии). 
    При окончании пользователем ввода прочитайте файл и выведите на эк- 
    ран все значения. 
*/

#include <fstream>
#include <iostream>
#include <conio.h>

class Distance
{
private:
    int feet;
    double inches;
public:
    void setData();
    void showData();
};

void Distance::setData()
{
    std::cout << "Введите футы: ";      std::cin >> feet;   
    std::cout << "Введите дюймы: ";     std::cin >> inches; 
}

void Distance::showData()
{
    std::cout << "----------------" << std::endl;
    std::cout << "Расстояние - \'" << feet << '-' << inches << "\'" << std::endl;
}


int main()
{
    Distance *drr[100];
    char ch = 'a';  int i=0;
    std::cout << "Работать в выбранном файле или создать новый? (\'d\' or \'c\') ";  std::cin >> ch;
    if (ch == 'd') 
    {   
        std::cout << "Прошлый файл удален" << std::endl; 
        remove("Distance.dat");
    }
    else 
        std::cout << "Выбрана работа с ранее созданным файлом" << std::endl;

    std::fstream ffile;
    std::cout << "Хотите записать или прочитать информацию? (\'w\' or \'r\') "; std::cin >> ch;
    if (ch == 'w')
    {
        i = 0;
        ffile.open("Distance.dat", std::ios::out | std::ios::binary | std::ios::app);
        if (!ffile)
        {
            std::cout << "Ошибка при работе с файлом" << std::endl;
            exit(1);
        }
        do
        {
            drr[i] = new Distance;
            drr[i]->setData();
            // Записал код, который поможет в чтении. А именно покажет, дошел ли до конца файла или нет.
            ffile.write(reinterpret_cast<char *>(&i),sizeof(i)); 
            ffile.write(reinterpret_cast<char *>(drr[i]),sizeof(*drr[i]));
            std::cout << "Продолжить или прекратить запись? (\'c\' or \'s\') " << std::endl;
            i++;
        } while ((ch = getch())!='s');
        ffile.close();
    }
    else if (ch == 'r')
    {
        int count = 0;
        ffile.open("Distance.dat", std::ios::in | std::ios::binary);
        if (!ffile)
        {
            std::cout << "Ошибка при работе с файлом" << std::endl;
            exit(1);
        }
        while(true)
        {   
            ffile.read(reinterpret_cast<char *>(&i),sizeof(i));  // Эта запись нужно только как код
            if (ffile.eof()) break;
            drr[count] = new Distance;
            ffile.read(reinterpret_cast<char *>(drr[count]),sizeof(*drr[count]));
            drr[count]->showData();
            count++;
        }
        std::cout << "Было прочитано " << count << " записей" << std::endl;
        ffile.close();
    }
    
    return 0;
}