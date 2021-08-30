// Взял пример с какого-то форума

#include <iostream>
using namespace std;

//Листинг 3.21. TDeque – контейнер-дек
class TDeque
{   class Elem;                     // опережающее объявление
  public:
    class iterator              
    {   friend class TDeque;
        iterator(Elem *el):the_elem(el){}
    public:
        // конструкторы
        iterator():the_elem(0){}
        iterator(const iterator &it):the_elem(it.the_elem){}
        // присваивание итераторов – генерируется по умочанию
        // сравнение итераторов
        bool operator==(const iterator &it) const
        { return (the_elem == it.the_elem); }
        bool operator!=(const iterator &it) const
        { return !(it == *this); }
        // продвижение к следующему элементу – только префиксная форма
        iterator& operator++()
        {   if ((the_elem!=0)&&(the_elem->next!=0))
                the_elem = the_elem->next;
            return *this;
        }
        // продвижение к предыдущему элементу – только префиксная форма
        iterator& operator--()
        {   if ((the_elem!=0)&&(the_elem->prev!=0))
                the_elem = the_elem->prev;
            return *this;
        }
        // получить ссылку на информационную часть 
        // работает справа и слева от знака присваивания
        double& operator*() const
        { if (the_elem != 0) return the_elem->item;
        else { cout << "Null iterator!" << endl; exit(1); }
        }
    private:
        Elem *the_elem;     // вот это итератор скрывает! 
    };
public:
    // создаем пустой дек – с фиктивным запредельным элементом
    TDeque():Head(new Elem()), Tail(Head), count(0)  
    { Tail->next=Tail->prev=0; 
      head = iterator(Head);            // инициализация для итератора
      tail = iterator(Tail);            // приватным конструктором
    }
    // создаем дек с единственным элементом 
    TDeque(const double& a):Head(new Elem()), Tail(Head), count(0) 
    { 
      Tail->next=Tail->prev=0;
      head = iterator(Head);
      tail = iterator(Tail);
      push_front(a);
    }
    ~TDeque();
    bool isEmpty() const                    // есть ли элементы в деке
    { bool t = (Head == Tail); return t; }
    long size() const { return count; }     // количество элементов в деке
    // методы доступа  
    iterator begin() { return head; }       // первый элемент
    iterator end()   { return tail; }       // запредельный элемент
    // методы вставки и удаления на концах дека
    void push_front(const double &a);
    void push_back(const double &a);
    void pop_front();
    void pop_back();
private:
    class Elem                          // элемент дека
    {   friend class TDeque;                    
        friend class iterator;
        Elem(const double &a):item(a){ }
        Elem(){}                 
        ~Elem(){}               // объявлять необязательно
        double item;            // информационная часть элемента
        Elem *next;             // следующий элемент    
        Elem *prev;             // предыдущий элемент
    };
    // запрещаем копировать и присваивать деки
    TDeque& operator=(const TDeque &);  
    TDeque(const TDeque &); 
    long count;                 // количество элементов
    Elem *Head;                 // Начало дека
    Elem *Tail;                 // указатель на запредельный элемент 
    // для итератора
    iterator head;
    iterator tail;
};

void TDeque::push_front(const double &a)
{   Elem *p = new Elem(a);          // образовали новый элемент
    p->next = Head; p->prev = 0;    // "привязали" 
    Head->prev = p; Head = p;       // первым в деке
    head = iterator(Head);          // корректируем итератор
    ++count;                        // добавили элемент
}
// удалить элемент
void TDeque::pop_front()
{   if (!isEmpty())                 // если есть элементы
    { Elem *p = Head;               // сохраняем указатель для удаления
      Head = Head->next;            // "отцепляем"
      Head->prev = 0;               // элемент
      head = iterator(Head);            // корректируем итератор
      --count;                      // уменьшаем количество
      delete p;                         // возвращаем память
    }
}
void TDeque::push_back(const double &a)
{   if (isEmpty()) push_front(a);   // если вставляем первый раз 
    else 
    { Elem *p = new Elem(a);        // создали элемент
        p->next = Tail;             // "привязываем"
        p->prev = Tail->prev;       // перед 
        Tail->prev->next = p;       // фиктивным 
        Tail->prev = p;                 // элементом
    }
    ++count;                        // добавили элемент
};
// удаление элемента
void TDeque::pop_back()
{   if (!isEmpty())                 // если есть элементы
    { Elem *p = Tail->prev;         // сохраняем для удаления
      if (p == 0) pop_front();      // если элемент единственный
      else 
      { p->prev->next = Tail;       // отцепляем 
        Tail->prev = p->prev;       // элемент
        delete p;                   // возвращаем память
      }
      --count;                      // уменьшаем количество
    }
}
TDeque::~TDeque()
{   Elem *delete_Elem = Head;           // удаляемый элемент
    for(Elem *p = Head; p!=Tail;)       // Пока не уперлись в запредельный
    { p = p->next;                      // подготовили следующий
      delete delete_Elem; --count;      // удалили элемент
      delete_Elem = p;                  // подготовили для удаления
    }
    delete delete_Elem;                 // удалили запредельный
}

int main()
{   
    TDeque l2;
    std::cout << *(l2.begin()) << std::endl;
    TDeque L(8.0);              // создали дек из одного элемента
    // добавляем 5 элементов в начало – стало 6
    L.push_front(1); L.push_front(2); L.push_front(3); 
    L.push_front(4); L.push_front(5);
    cout << L.size()<< endl;        // выводим количество элементов
    TDeque::iterator i;             // объявили итератор
    // вывод элементов контейнера 
    for(i = L.begin(); i != L.end(); ++i)   // изменение итератора
         cout << *i << ' ';         // вывод значения
    cout << endl;
    // добавляем пять элементов в конец дека – стало 11
    L.push_back(1); L.push_back(2); L.push_back(3); 
    L.push_back(4); L.push_back(5);
    // вывод элементов контейнера   // 0xe81940
    for(i = L.begin(); i != L.end(); ++i) 
         cout << *i << ' ';  cout << endl;
    cout << L.size()<< endl;        // выводим количество элементов
    // Обратный перебор 
    i = L.end();                // на запредельный элемент
    while(i != L.begin())           // пока не дошли до первого
    { --i;                  // сначала переходим на реальный элемент
      cout << *i << ' ';            // выводим значение
    } 
    cout << endl;
    // удалили 4 элемента в начале дека – осталось 7
    L.pop_front(); L.pop_front(); L.pop_front(); L.pop_front();
    // вывод элементов контейнера
    for(i = L.begin(); i != L.end(); ++i) 
         cout << *i << ' ';  cout << endl;
    cout << L.size()<< endl;            // выводим количество элементов
    // удалили 3 элемента в конце дека – осталось 4
    L.pop_back(); L.pop_back(); L.pop_back(); 
    // вывод элементов контейнера
    for(i = L.begin(); i != L.end(); ++i) 
         cout << *i << ' ';  cout << endl;
    cout << L.size()<< endl;            // выводим количество элементов
    return 0;                   
}       // работает деструктор, удаляя 4 элемента и запредельный элемент
