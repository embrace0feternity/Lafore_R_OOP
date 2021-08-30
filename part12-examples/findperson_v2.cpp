#include <fstream>
#include <iostream>
#include <string.h>

class person
{
private:
    enum { SIZE = 20 };
    char name[SIZE];
    short age;
public:
    person(): age(0) {  }
    void setData()
    {
        std::cout << "Введите имя пользователя - "; std::cin.getline(name, SIZE);
        std::cout << "Введите возраст - "; std::cin >> age;
    }
    void showData()
    {
        for (int i=0; i<50; i++) std::cout << '-';
        std::cout << "\nИмя пользователя - " << name << std::endl;
        std::cout << "Возраст - " << age << std::endl;
    }
    char* getName() { return name; }
    ~person() {  }
};

inline void menu()
{
    std::cout << "\t\tМеню\n1.Запись в файл\n2.Чтение из файла\n3.Поиск в файле\n0.Выход" << std::endl;
}

int main()
{
    char ch = '1';
    while(ch != '0') 
    {   
        menu();
        person prsn[100];
        std::cin >> ch;
        if (ch == '1')
        {
            std::ofstream outfile; 
            std::cout << "Хотите отчистить файл или продолжить работу с прошлым файлом? ('y'/'n') ";
            char c;     std::cin >> c;
            if (c == 'y') 
            {
                remove("findperson_v2.txt"); // Удаляем ранее созданный файл по решению пользователя
                std::cout << "Новый файл создан" << std::endl;
            }
            else
                std::cout << "Выбрана работа с уже созданным файлом" << std::endl;
        
            // открывай файл для записи в двоичном виде. Каждая след заметка записывается в конец файла
            outfile.open("findperson_v2.txt", std::ios::binary | std::ios::app);  
            std::cout << "Введите информацию о пользователях. Максимум 100 пользователей" << std::endl; 
            // Не уследил, где в буффере остаётся '\n', но эксперементы показали, что этот символ есть
            std::cin.ignore(1,'\n');  
            c = 'a';
            int i = -1;
            do
            {
                prsn[++i].setData(); // Указываем имя и возраст людей
                /* Записываем эту информацию в файл. Мне кажется, что лучшим решением было заполнить инфу
                о людях, а потом за раз записать инфу в файл. Если не забуду, исправлю. Сейчас лень  */
                outfile.write(reinterpret_cast<char *>(prsn+i), sizeof(*prsn));
                std::cout << "Пользователь записан в файл. Хотите продолжить? ('y'/'n') " << std::endl;
                std::cin >> c;
                std::cin.ignore(1,'\n');
            } while (c == 'y');

            /*
                Тыкаем указатель в конец файла. Вычисляем в count число имеющихся в файле объектов
                Проверяю сам себя и закрываю файл.
            */
            outfile.seekp(0, std::ios::end); 
            int count = outfile.tellp() / sizeof(prsn[0]);
            std::cout << "\nПроверка:\n Вы ввели " << i+1 << " пользователей. Теперь в файле " 
                << count << " пользователей" << std::endl;
            outfile.close();            
        }
        else    if (ch == '2')
        {
            std::cin.ignore(1,'\n');
            std::ifstream infile("findperson_v2.txt", std::ios::binary); // Открываю файл для чтения
            infile.seekg(0, std::ios::end); // Указатель в конец файла
            int count = infile.tellg() / sizeof(prsn[0]); // Вычисляю кол-во объектов класса в файле
            infile.seekg(0); // Обратно укатель в начало, начинаю читать данные с начала файла
            infile.read(reinterpret_cast<char *>(prsn), count*sizeof(*prsn)); 
            for (int i=0; i<count; i++) prsn[i].showData();
            std::cout << "Выведена информация обо всех (" << count << ") пользователях" << std::endl;
        }
        else    if (ch == '3')
        {
            std::ifstream infile("findperson_v2.txt", std::ios::binary);
            const int SIZE = 20;
            char name[SIZE];
            std::cout << "Введите имя человека, которого хотите найти в списке: " << std::endl;
            
            std::cin.ignore(1, '\n');
            std::cin.getline(name, SIZE);
            int len = strlen(name);
            
            infile.seekg(0, std::ios::end);
            int count = infile.tellg() / sizeof(prsn[0]);
            infile.seekg(0);
            infile.read(reinterpret_cast<char*>(prsn),count*sizeof(*prsn));
            int cperson = 0;
            for (int i=0; i<count; i++)
            {
                char *prsnName = prsn[i].getName(); 
                int j=0;
                for (j; j<len; j++)
                    // Если все символы имени в прочитанном объекте класса совпали с введенным именем, то...
                    if (prsnName[j] == name[j]); 
                    else break;
                /* 
                    Выводим на экран инфу о пользователе. Будут выведены все пользователи, имеющие
                    вводимое имя.
                    Можно было сделать через infile.eof(), но мне этот вариант показался более привлекательным
                */
                if (j == len) { prsn[i].showData();  cperson++; }
            }
            if (cperson == 0) std::cout << "В файле не нашлось человека с таким именем!" << std::endl;
            else std::cout << "Итого: в файле нашлось " << cperson << " людей с таким именем" << std::endl;
        }
   }
    
    return 0;
}