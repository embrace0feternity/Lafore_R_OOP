#include <iostream>
using namespace std;

class A
{
private:
    int privA;
public:
    int publB;
protected:
    int protC;
};

/*
    Имеются 3 спецификатора доступа: public, private, protected.
    Спецификатор доступа позволяют изменять доступ членов базового класса в наследниках. Это никак не влияет на 
    собственные (не наследуемые) члены наследников. Это влияет только на то, могут ли объекты дочерних классов
    получать доступ к базовому классу.
*/

class B : public A // ОБЩЕЕ наследование.
{
    /*
        Общее наследование означает, что: 
            - public члены базового класса остаются public в наследнике
            - protected остаются protected в наследнике
            - private доступен методам базового класса, но недоступен членам наследника
    */
public:
    void foo()
    {
        publB = 7; //   Класс Б является ОБЩИМ наследником. Это общее наследование. ЧЛЕНЫ класса Б имеют доступ к 
        protC = 5; // протектед и паблик полям и методам базового класса.  
        privA = 10; // К прайват полям доступа нет.
    }
};

class C : private A // Чатсное наследование
{
    /*
        Частное наследование означает, что: 
            - public члены базового класса станут private членами наследника
            - protected члены базового класса станут private членами наследника
            - private члена базового класса по прежнему недоступны наследнику
    */
public:
    void foo()
    {
        publB = 7; //   Класс С является ЧАСТНЫМ наследником. Это частное наследование. ЧЛЕНЫ класса С имеют доступ к
        protC = 5; // протектед и паблик полям и методам базового класса
        privA = 10; // К прайват полям доступа нет.
    }
};

class D : protected A // Тоже частное наследование, но
{
    /*
            - public члены базового класса станут protected членами наследника
            - protected члены базового класса станут protected членами наследника
            - private члена базового класса по прежнему недоступны наследнику
    */
public:
    void foo()
    {
        publB = 7;
        protC = 5;
        privA = 10;
    }
};
// Тогда в чем отличие ОБЩЕГО и ЧАСТНОГО наследования?
// В полях и методах, которые доступны ОБЪЕКТАМ класса.

int main()
{
    A a1;
    a1.publB; // Доступ разрешен, так это public секция. 
    a1.privA; // Доступ запрещен, тк это private секция.
    a1.protC; // Доступ запрещен, тк это protected.

    B b2_public;
    b2_public.foo(); // Разрешен доступ к public членам самого наследника
    b2_public.publB; // Разрешено. Доступ publB в наследнике из базового класса разрешен
    b2_public.privA; // Запрещено. Доступ privA в наследнике из базового запрещен
    b2_public.protC; // Запрещено. Доступ protC в наследнике из базового запрещен

    C c3_private;
    c3_private.foo();  // Доступ разрешен к полям и методам public пространства самого наследника.
    c3_private.publB;  // Запрещен, тк поля public базового класса стали private наследника
    c3_private.privA;  // Запрещен, тк private, т.е нет доступа к private членам базового класса.
    c3_private.privC;  // Запрещен, тк поля protected базового класса стали private наследника

    D d4_protected;
    d4_protected.foo(); 
    d4_protected.publB;
    d4_protected.privA;
    d4_protected.protC;
    return 0;
}