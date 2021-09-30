#include <iostream>
#include <memory>

class Item
{
    std::string name = "N/A";
    static int count;
public:
    Item() { std::cout << ++count << " create" << std::endl; }
    Item(const std::string &str): name(str) { std::cout << ++count << " obj with name is created" << std::endl; }
    ~Item() { std::cout << count-- << " destroy" << std::endl; }
    void show()const { std::cout << name << " objects has been created" << std::endl; }

    friend std::ostream& operator << (std::ostream &, const Item &);
};
int Item::count = 0;

std::ostream& operator << (std::ostream &out, const Item &item)
{
    out << item.name;
    return out;
}

void foo(Item* ptr)
{
    std::cout << "Addr: " << &ptr << std::endl;
}

int main()
{   
    // std::unique_ptr<Item> uniqptr = std::make_unique<Item>();
    // foo(uniqptr.get()); // get - return dummy ptr
    // uniqptr->show();
    // //uniqptr.reset(); // free resourse and set to nullptr;
    // uniqptr.reset(new Item("Vlad")); // free resourse and set to a new Item 

    // uniqptr->show();
    // Item *VladItem = uniqptr.release(); // release returns the underlying ptr and set the smart ptr to nullptr
    // delete VladItem; // Now, i responsible for freeing the resourse
    
    auto shared1 = std::make_shared<Item>("Veronika");

    Item *item = new Item;
    std::shared_ptr<Item> ptr1(item);
    std::shared_ptr<Item> ptr2(ptr1);

    return 0;
}