/*
        Создайте класс name, включающий в себя данные из упражнения 4 (имя, 
    отчество, фамилия и номер работника). Создайте методы для этого класса, 
    осуществляющие файловый ввод/вывод данных указанного класса (с ис- 
    пользованием ofstream и ifstream). Используйте форматирование данных 
    (операторы « и »). Функции чтения и записи должны быть независи- 
    мыми: в них необходимо внести выражения для открытия соответству- 
    ющего потока, а также чтения и записи данных. 
        Функция записи может просто добавлять данные в конец файла. Функ- 
    ции чтения потребуется некоторое условие выборки конкретной записи. 
    Можно вызывать ее с параметром, представляющим собой номер записи. 
    Но как, даже зная, какую запись следует читать, функция найдет ее? Ис- 
    пользование seekg() тут не поможет, так как при форматированном вво- 
    де/выводе все записи имеют разные размеры (в зависимости от количества 
    символов в строке и разрядности числа). Поэтому придется просто счи- 
    тывать записи подряд, пока не будет найдена нужная. 
        В main() вставьте вызовы описанных выше методов, чтобы пользователь 
    мог ввести данные с их последующей записью в файл. Затем программа 
    должна выполнить чтение и продемонстрировать результаты этого чтения 
    на экране. 

*/

#include<iostream>
#include<fstream>
#include<string.h>
#include<conio.h>
#define end_of_file 2

class user
{
private:
    std::string fname;
    std::string sname;
    std::string addname;
    static int point;
public:
    unsigned long number;
    
    user() { fname = sname = addname = "N/A";   number = 0; } // Явное создание объектов. Нужно было только для теста
    void setData();     // Значения от пользователя
    void showData()const; // Вывод значений в консольку

    void write(); 
    bool read();
    friend std::ofstream& operator << (std::ofstream &, user &); // Для записи объектов через << форматирование. Так требуется по условию
    friend std::ifstream& operator >> (std::ifstream &, user &); // Для чтения объектов через >> форматирование
};
int user::point = 0; // о ней ниже, в read()

void user::setData()
{
    std::cout << "Введите имя - "; std::getline(std::cin, fname);
    std::cout << "Введите фамилию - "; std::getline(std::cin, sname);
    std::cout << "Введите отчество - "; std::getline(std::cin, addname);
    std::cout << "Номер - "; std::cin >> number;
}

void user::showData()const
{
    std::cout << "-----------------" << std::endl;
    std::cout << "Имя - " << fname << std::endl;
    std::cout << "Фамилия - " << sname << std::endl;
    std::cout << "Отчество - " << addname << std::endl;
    std::cout << "Номер - " << number << std::endl;
}

void user::write()
{
    std::ofstream outfile("main4_user.txt", std::ios::app); // Открыл файл для записи. Прошлые данные не удаляются
    if (!outfile.is_open()) // Если файл не открыт, вывод ошибки
    {
        std::cerr << "Невозможно открыть/создать файл" << std::endl;
        exit(1);
    }
    outfile << *this; // запись текущего объекта в файл
}

/*
        Поскольку по условию требуется форматированный ввод/вывод в/из файла, то ничего лучшего,
    чем реализация снизу, я не придумал...
        tellg/Sizeof не смогу использовать, тк размеры всех объектов разные. Поэтому у меня
    2 указателя. 1й - point. Статическая переменная, которая указывает на текущий объект считывания
    2й - size = размер файла.
*/
bool user::read()
{
    int size;  
    std::ifstream infile("main4_user.txt");
    if (!infile.is_open())
    {
        std::cerr << "Невозможно открыть/создать файл" << std::endl;
        exit(1);
    }
    infile.seekg(0,std::ios::end);
    size = infile.tellg(); // размер файла
    std::cout << " ---- point ----" << point << std::endl;
    infile.seekg(point); // указатель на текущий объект чтения.
    infile >> *this;

    infile.seekg(0, std::ios::cur); // Прочитал объект. Указатель находится в конце объекта чтения
    point = infile.tellg(); // Установил указатель на следующий объект.

    // end_of_file - EOF - специальный символ, который занимает 2 байта. 
    if (point >= size - end_of_file) return false;  // Определение конца файла
    return true;
}

std::ofstream& operator << (std::ofstream &out, user &other)
{
    out << other.number << other.fname << ' ' << other.sname << ' ' << other.addname << ' ';
    return out;
}

std::ifstream& operator >> (std::ifstream &in, user &other)
{
    in >> other.number >> other.fname >> other.sname >> other.addname;
    return in;
}


int main()
{
    user *usr[100];
    char ch;
    std::cout << "Читать (r) или вводить(w)? "; std::cin >> ch;
    int i;
    if (ch == 'w')
    {
        i=0;
        while(ch != 'n')
        {
            std::cin.ignore(1,'\n');
            usr[i] = new user;
            usr[i]->setData();
            usr[i]->write();
            std::cout << "Введите \'y\' для продолжения записи или \'n\' для прекращения" << std::endl;
            std::cin >> ch;
            i++;
        } 
        
    }
    else if (ch == 'r')
    {
        i=0;
        while(true)
        {
            usr[i] = new user;
            if(!usr[i]->read()) // Если символ последний
            {
                usr[i]->showData(); // Вывел его и закончил чтение
                i++;
                break;
            }
            usr[i]->showData();
            i++;
        }
    }
    for (int j=0; j<i; j++)
        delete usr[j]; // Только на этой задаче вспомнил, что нужно удалять объекты... А в пред. задачах забывал...
    return 0;
}