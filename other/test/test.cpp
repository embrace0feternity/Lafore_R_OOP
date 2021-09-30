#include <iostream>
#include <memory>
#include <string>

using namespace std;

class solder{
    string name;
    weak_ptr<solder> target;

public:
    solder(string name): name(name) { cout << "Create solder" << endl; }
    ~solder() { cout << "delete solder" << endl; }
    void setTarget(shared_ptr<solder>& ptr )
    {
        target = ptr;
    }
};

int main()
{
    auto Archer = make_shared<solder>("vlad");  
    auto Pickman = make_shared<solder>("egor"); // a = 1 : p = 1
    
    Archer->setTarget(Pickman); // a = 1 : p = 2
    
    cout << Pickman.use_count() << endl;
    cout << Archer.use_count() << endl;

    Pickman->setTarget(Archer); // a = 2 : p = 2 

    cout << Pickman.use_count() << endl;
    cout << Archer.use_count() << endl;

    return 0;
}