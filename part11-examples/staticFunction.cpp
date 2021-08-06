#include <iostream>

class myClass
{
private:
    static int counter;
    int id;
public:
    myClass() { counter++; id = counter; }
    ~myClass() { counter--; std::cout << "Delete " << id << std::endl; }
    /* 
            static function is general for every object and i can call this function without object.
        Other function (without key word "static") i mustn't call in external class or function (like main())
        using class_name:: 
    */ 
    static void showCounter() { std::cout << "Total: " << counter << std::endl; }
    void showId()const { std::cout << "Id: " << id << std::endl; }
};
int myClass::counter=0;

int main()
{
    myClass obj_1;
    myClass::showCounter();
    
    myClass obj_2, obj_3;
    myClass::showCounter();
    myClass::showCounter();
    
    obj_1.showId();
    obj_2.showId();
    obj_3.showId();
    return 0;
}