#include <iostream>

class myClass
{
private:
    int someData;
public:
    myClass(): someData(0) { std::cout << "constr " << this << std::endl; }
    myClass(int data): someData(data) { std::cout << "constr " << this << std::endl; }
    ~myClass() { std::cout << "destr" << this << std::endl; }
    void show()const { std::cout << someData << std::endl; }
    myClass operator= (myClass &other)
    {
        someData = other.someData;
        std::cout << "Copy" << std::endl; 
        return myClass(someData);
        //return *this;
    }
};

int main()
{
    myClass objA(23);
    myClass objB;
    objB = objA; // i get message "Copy"
    objB.show();

    myClass objC = objA; // i don`t get message "copy" because Assignment operator != Initialization.
    //                I create new obj with copy constuctor but i use existing object with assignment operator.
    objC.show();

    myClass objD;
    //objD = objC = objB = objA;

    return 0;
}

