#include <iostream>

using namespace std;

class Item
{
    float weight;
    int *count;
public:
    Item(float w = 0.0): weight(w) { count = new int; *count = 0; cout << "Item create" << endl; }
    ~Item() { 
        if (*count == 0)
        {
            delete count; 
            cout << "Item destroy" << endl; 
        } else
            --*count;
    }
    
    Item(Item &&other); // Перемещение
    Item& operator= (Item &&other); // Перемещение
    friend ostream& operator << (ostream &out, const Item &other);
};

Item::Item(Item &&other)
{
    count = new int;
    *count = ++*other.count;
    weight = other.weight;
    other.count = nullptr;
}

Item& Item::operator= (Item &&other)
{
    if (&other == this) return *this;
    weight = other.weight;
    *count = ++*other.count;
    other.count = nullptr;
    return *this;
}

ostream& operator << (ostream &out, const Item &other)
{
    out << other.weight << ' ' << other.count;
    return out;
}

Item foo()
{
    Item item2(9.6);
    return item2;
}

int main()
{
    Item item1(3.4);
    Item item2 = foo();
    cout << "item1: " << item1 << std::endl;
    
    cout << "item2: " << item2 << std::endl;
    return 0;
}