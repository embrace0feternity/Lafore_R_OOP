#include <iostream>
using namespace std;

class Character
{
public:
    Character(string name) { cout << "Character " << name << endl; }
};

class Elf : virtual public Character
{
public:
    Elf(string name, int power): Character(name) { cout << "Elf " << power << endl; }
};

class Archer : virtual public Character
{
public:
    Archer(string name, int power): Character(name) { cout << "Archer " << power << endl; }
};

class ElfArcher : public Elf, public Archer
{
public:
    ElfArcher(string name, int power): Elf(name, power), Archer(name, power), Character(name) 
        { cout << "Create hero" << endl; }
};

int main()
{
    ElfArcher("Meneltor", 45);
    return 0;
}