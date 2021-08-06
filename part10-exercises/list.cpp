/*
 * main.cpp
 *
 *  Created on: 27 ���. 2021 �.
 *      Author: Streh
 */

#include <iostream>
using namespace std;

class cell
{
public:
	int data;
	cell* next;									//	pointer to the next object;
public:
	cell(): data(0), next(nullptr)
	{
		cout << "cell constructor: " << this << endl;
	}
	~cell() {	cout << "cell destructor: " << this << endl;   }
};



class linklist
{
private:
	cell *first; 								//	pointer to the current object;
	int size;
public:
	linklist(): first(nullptr), size(0) { }
	~linklist();

	void push(int data);
	void pushindex(int index);

	void show();

	void pop();
	void poplast();
	void popindex(int index);

	void sort();
};
linklist::~linklist()
{
	while(first)
	{
		cell *temp = first;
		first=temp->next;
		delete temp;
		size--;
	}
}


void linklist::push(int data)
{
	cell *temp = new cell;
	temp->data = data;
	temp->next = first;
	first = temp;
	size++;
}
void linklist::pushindex(int index)
{
	cout << "write data: ";
	int d;	cin >> d;
	if (index >= size)
	{
		cout << "List doesn`t contain as many elements" << endl;
	}	else	if (index == 0)  push(d);
	else
	{
		cell *previous = first;
		for (int i=0; i<index-1; i++) previous = previous->next;
		cell *after = previous->next;

		cell *add = new cell;
		add->data = d;
		add->next = after;
		previous->next = add;
	}
}
// cin >> d;

void linklist::show()
{
	cout << "-----size: " << size << endl;
	cell *current = first;
	while(current)
	{
		cout << "data: "<< current->data << "\t\taddr: " << current << endl;
		current = current->next;
	}
}

void linklist::pop()
{
	cell *deleted = first;
	first = deleted->next;
	size--;
	delete deleted;
}

void linklist::poplast()
{
	cell *deleted = first;
	while(deleted->next != nullptr)
		deleted = deleted->next;
	cell *current = first;
	while(current->next != deleted)
		current = current->next;
	delete deleted;
	current->next = nullptr;
	size--;
}

void linklist::popindex(int index)
{
	if (index >= size) cout << "Out of range; Index is bigger than size" << endl;
	else	if (index == 0) pop();
	else 	if (index == size-1) poplast();
	else
	{
		cell *previous = first;
		for (int i=0; i<index-1; i++) previous = previous->next;
		cell *deleted = previous->next;
		cell *after = deleted->next;
		delete deleted;
		previous->next = after;
		size--;
	}
}

void linklist::sort()
{

}


void menu()
{
	cout << "-----Menu-----" << endl;
	cout << "1. Add head" << endl;
	cout << "2. Add number on index" << endl;
	cout << "3. Delete head" << endl;
	cout << "4. Delete number on index" << endl;
	cout << "5. Sort list" << endl;
	cout << "6. Show list" << endl;
}






int main(int argc, char **argv)
{
	linklist list;
	list.push(5);
	list.push(83);
	list.push(24);
	list.push(70);
	list.push(54);
	list.show();
	//list.popindex(4);
	//list.show();

	//list.sort();
	list.show();


	return 0;
}



