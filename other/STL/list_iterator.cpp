// Решил написать собственный итератор для двухсвязного списка, чтобы лучше понять их работу

#include <iostream>

template <typename T>
class list;

template <typename T>
class Node
{
private:
    friend list<T>; // Делаю другом список для доступа из списка к скрытым полям
    T data; // значение в ячейке
    Node *next; // указатель на след. ячейку
    Node *prev; // указатель на пред. ячейку
public:
    Node(T d): data(d), next(nullptr), prev(nullptr) { }
    Node() { }
};


template <typename T>
class list
{
private:
    Node<T> *head; // Указатель на начало списка
    Node<T> *tail; // Указатель на конец списка
    int size;
public:
//--------------------------------------------------------
    class iterator
    {
    private:
        Node<T> *iter; // Указатель на ячейку    
    public:
        iterator(): iter(nullptr) {  } // Стандартный конструктор 
       // iterator(const iterator &i): iter(i.iter) { std::cout << "qwer" << std::endl; } // Конструктор копирования
        iterator(Node<T> *cell): iter(cell) { } // Конструктор с 1м аргументом для установки begin и end контейнера
        iterator& operator = (const iterator &i) { iter = i.iter; return *this; } // оператор присваивания
        T& operator *() { // оператор разыменования 
            if (iter == nullptr) { std::cerr << "null" << std::endl; exit(0); }
            else return iter->data;
        }
        bool operator != (const iterator &other)const{
            bool t;
            return t = (other == *this)? false : true;
        }
        bool operator == (const iterator &other)const{
            bool t;
            return t = (iter == other.iter)? true : false;
        }
        // Постфиксная форма. Продвижение вперед на 1 элемент
        iterator operator ++ (int){
            iterator temp = *this;
            if (iter != nullptr || iter->next != nullptr){
                iter = iter->next;
            } 
            return temp;
        }
        // Префиксная форма. Продвижение вперед на 1 элемент
        iterator& operator ++ () {
            if (iter != nullptr || iter->next != nullptr)      iter = iter->next;
            return *this;
        }
        // Постфиксная форма. Продвижение назад на 1 элемент
        iterator operator -- (int) {
            iterator temp = *this;
            if (iter != nullptr || iter->prev != nullptr)      iter = iter->prev; 
            return temp;
        }
        // Префиксная форма. Продвижение назад на 1 элемент
        iterator& operator -- () {
            if (iter != nullptr || iter->prev != nullptr)      iter = iter->prev; 
            return *this;
        }
    };
//-------------------------------------------------------
    list(): head(new Node<T>), tail(head), size(0) // Создание фиктивного элемента, который будет и head и tail
    {
        tail->next = tail->prev = nullptr; // Список пустой. Соседей нет.
        var_begin = iterator(head); // Устанавка итератор начала на фиктивный элемент
        var_end = iterator(tail); // Устанавка итератора окончания контейнера на фиктивный элемент
    }
    bool isEmpty() {
        bool t;
        // Проверка на отсутствие элементов в списке
        return t = (head == tail)? true : false; 
    }
    void push_back(T data); // добавление в конец (к tail, перед фиктивным элементом)
    void push_front(T Data); // добавление вперед (к head)
    void pop_back(); // удаление с конца
    void pop_front();
    iterator& begin() { return var_begin; }
    iterator& end() { return var_end; }
private:
    iterator var_begin; // Итератор на начало контейнера
    iterator var_end; // Итератор на фиктивный элемент в конце контейнера
};

template <typename T>
void list<T>::push_front(T data)
{
    // Нет проверки на 1й элемент, т.к первый элемент всегда будет в списке. Это фиктивный элемент
    Node<T> *temp = new Node<T>(data); // новый элемент
    temp->next = head; temp->prev = nullptr; // связывание элементов
    head->prev = temp;
    head = temp;
    var_begin = iterator(head); // Корректировка итератора
    size++; // ++ счётчик
}

template <typename T>
void list<T>::push_back(T data)
{
    if (isEmpty()) push_front(data); // Если в списке ничего нет
    else
    {
        Node<T> *temp = new Node<T>(data);
        temp->prev = tail->prev; // связь последнего реального элемента 
        tail->prev->next = temp; // с вставляемым
        tail->prev = temp;  // связь фиктивного элемента с
        temp->next = tail;  // вставляемым
        size++;
    }
}

template <typename T>
void list<T>::pop_back()
{
    if (!isEmpty())
    {
        if (tail->prev == head) pop_front();
        else    {
            Node<T> *temp = tail->prev;
            tail->prev = temp->prev;
            temp->prev->next = tail; 
            delete temp;
        }
    }
    size--;
}


template <typename T>
void list<T>::pop_front()
{
    if (!isEmpty())
    {
        Node<T> *temp = head;
        head = temp->next;
        head->prev = nullptr;
        delete temp;
        var_begin = iterator(head);
    }
    size--;
}

int main()
{
    list<int> l;
    l.push_back(2);
    l.push_back(3);
    l.push_front(1);
    list<int>::iterator iter;
    iter = l.begin();
    std::cout << "Итератор на начало контейнера: "<< *iter << std::endl;

    std::cout << "Список элементов до удаления: " << std::endl;
    
    for (iter = l.begin(); iter != l.end(); ++iter)
        std::cout << *iter << ' ';
    std::cout << std::endl;

    l.pop_front();
    l.pop_front();
    l.pop_back();

    std::cout << "Список элементов после удаления: " << std::endl;
    for (iter = l.begin(); iter != l.end(); iter++)
        std::cout << *iter << ' ';
    std::cout << std::endl;
    

    for (int i=0; i<6; i++) l.push_back(i+1);
    iter = l.end();
    std::cout << "Список элементов. Вывод с конца" << std::endl;
    while(iter != l.begin())
    {
        --iter; // перешел с фиктивного элемента на реальный
        std::cout << *iter << ' ';
    }
    std::cout << std::endl;
    return 0;
}