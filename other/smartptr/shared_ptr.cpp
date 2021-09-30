#include <iostream>

using namespace std;

template <typename T>
class Shared_ptr
{
    unsigned int *count;
    T *ptr;
public:
    Shared_ptr(T *ptr = nullptr): ptr(ptr) { count = new unsigned int; *count = 0; }
    ~Shared_ptr() { 
        if (*count == 0) { 
            delete ptr; 
            delete count; 
        } 
        else --(*count);
    }
    
    Shared_ptr(Shared_ptr<T> &other){
        ++(*other.count);
        count = other.count;
        ptr = other.ptr;
    }
    Shared_ptr& operator= (Shared_ptr<T> &other){
        if (&other == this) 
            return *this;
        ++(*other.count);
        count = other.count;
        ptr = other.ptr;
        return *this;
    }

    T& operator *()const { return *ptr; }
    T* operator ->()const { return ptr; }

    template <typename V>
    friend std::ostream& operator << (std::ostream &out, const Shared_ptr<V> &other)
    {
        out << other.ptr;
        return out;
    }
};

class Item
{
    float weight;
public:
    Item(float w = 0): weight(w) { cout << "Create Item" << endl; }
    ~Item() { cout << "Destroy Item" << endl; }
    friend std::ostream& operator << (std::ostream &out, const Item &other)
    {
        out << other.weight;
        return out;
    }
};

int main()
{
    Shared_ptr<Item> item1(new Item(44.3));
    Shared_ptr<Item> item2(item1);
    
    std::cout << "Значение: " << *item1 << "\t Адрес: " << item1 << std::endl;

    std::cout << "Значение: " << *item2 << "\t Адрес: " << item2 << std::endl;

    Shared_ptr<Item> item3;
    item3 = item1;
    {
        Shared_ptr<Item> item4(new Item(50));
        std::cout << "Значение: " << *item4 << "\t Адрес: " << item4 << std::endl;
       
    }

    std::cout << "Значение: " << *item1 << "\t Адрес: " << item1 << std::endl;

    std::cout << "Значение: " << *item3 << "\t Адрес: " << item3 << std::endl;

    return 0;
}