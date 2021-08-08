#include <iostream>
#include <random>
#include <time.h>
#include <string.h>


class publications
{
private:
    std::string name;
    float price;
public:
    publications(): name("\'N/A\'"), price(0.0) { }

    virtual void setData()
    {
        std::cout << "Введите название книги из списка публикации: "; getline(std::cin,name); 
        std::cout << "Введите её стоимость: "; std::cin >> price;
    }
    virtual void getData()const 
    {
        std::cout << "--- Название: " << name << std::endl;
        std::cout << "--- Стоимость: " << price << std::endl;
    }
    virtual bool isOversize()=0;
};


class book  :   public publications
{
private:
    int pages;
public:
    book(): publications(), pages(0) { }

    void setData() 
    { 
        std::cout << " --- Книга ---" << std::endl;
        publications::setData();
        std::cout << "Введите количество страниц в книге: "; std::cin >> pages;
    }
    void getData()const 
    { 
        std::cout << std::endl << "Книга" << std::endl;
        publications::getData();
        std::cout << "--- Страниц: " << pages << std::endl; 
    }
    virtual bool isOversize()
    {
        if (pages >= 800)
        {
            std::cout << "Ошибка. Книг, в которых более 800 страниц, нет в списке публикации!" << std::endl;
            return true;
        }   else return false;
    }    
};

class type  :   public publications
{
private:
    float min;
public:
    type(): publications(), min(0.0) { }
    
    void setData() 
    { 
        std::cout << " --- Аудио книга ---" << std::endl;
        publications::setData();
        std::cout << "Введите количество минут этой аудиокниги: "; std::cin >> min; 
    }
    void getData()const 
    {
        std::cout << std::endl << "Аудио книга:" << std::endl; 
        publications::getData();
        std::cout << "--- Минут: " << min << std::endl; 
    }

    virtual bool isOversize()
    {
        if (min >= 90.0)
        {
            std::cout << "Ошибка. Аудиокниг, длительность которых более 90 минут, нет в списке публикации!" << std::endl;
            return true;
        }   else return false;
    }  
}; 

int main()
{
    srand(time(0));
    int size = 4;
    publications* publ[size];
    std::cout << "Привет. Введите данные книги или аудиокниги для проверки их в списке публикаций." << std::endl;
    for (int i=0, temp; i<size; i++)
    {
        temp = rand()%2;
        if (temp) // Есть temp = 1 создаём объект книги, иначе аудио
        {
            publ[i] = new book;
            publ[i]->setData();
            if (publ[i]->isOversize()) { delete publ[i]; i--; size--; }/* можно было конечно написать функцию,
            в которой бы создавался новый массив указателей на объекты класса с количеством указателей SIZE - 1,
            копировать содержимое из publ во вновь созданный массив*/
        }
        else
        {
            publ[i] = new type;
            publ[i]->setData();
            if (publ[i]->isOversize()) { delete publ[i]; i--; size--; }
        }
        getchar();
    }
    for (int i=0; i<size; i++) publ[i]->getData();

    return 0;
}
