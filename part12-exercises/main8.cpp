#include <iostream>
#include <fstream>
using namespace std;

class cell
{
public:
	int data;
	cell* next;									//	pointer to the next object;
};



class linklist
{
private:
	cell *first; 								//	current object;
	int size;
	
	void push(int data);
	void pop();
	void poplast();
public:
	linklist(): first(nullptr), size(0) { }
    linklist(linklist *other);
	~linklist();

	void pushindex(int index, int d);

	void show();

	void popindex(int index);
	/*
		Через статический массив и статические функции реализовывать запись и чтение
		в файл, я думаю, не имеет смысл, т.к придется ограничить список.
	*/
	void write();
	void read();

    linklist& operator= (linklist *other);
};

linklist::linklist(linklist *other)
{
    size = 0;
    first = nullptr;
    int length = other->size;
    cell *current_other = other->first; 
    cell *current = first;
    while(length--)
    {
        current = new cell;
        current->data = current_other->data;
        current_other->next = first;
        first = current;
        size++;
    }
}

//54 70 24 83 5

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

void linklist::pushindex(int index, int d)
{
	if (index > size)
	{
		cout << "List doesn`t contain as many elements" << endl;
	}	else	if (index == size)  push(d);
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


void linklist::write()
{
	std::ofstream outfile("main8_list.dat", std::ios::binary | std::ios::out | std::ios::app);
	if (!outfile)
	{
		std::cerr << "Error" << std::endl;
		exit(1);
	}
	cell *ptr = this->first;
	for (int i=0; i<size; i++)
	{
		int data = ptr->data;
		outfile.write(reinterpret_cast<char*>(&data),sizeof(int)); 
		ptr = ptr->next;
	}
	outfile.close();
}

void linklist::read()
{
	std::ifstream infile("main8_list.dat", std::ios::binary | std::ios::in);
	if (!infile)
	{
		std::cerr << "Error" << std::endl;
		exit(2);
	}
	
	int data;
	infile.seekg(0, std::ios::end);
	int size = infile.tellg() / sizeof(data);
	infile.seekg(0);
	for (int i = size; i>0; i--)
	{
		infile.read(reinterpret_cast<char*>(&data),sizeof(data));
		push(data);
	}
}

linklist& linklist::operator= (linklist *other)
{
    int length = other->size;
    cell *current_other = other->first; 
    cell *current = first;
    while(length--)
    {
        current = new cell;
        current->data = current_other->data;
        current_other->next = first;
        first = current;
        size++;
    }
    return *this;
}

void menu()
{
	cout << "-----Menu-----" << endl;
	cout << "1. Add number on index" << endl;
	cout << "2. Delete number on index" << endl;
	cout << "3. Show list" << endl;
}


int main(int argc, char **argv)
{
	linklist list1;
	
	// for (int i=0; i<10; i++) 
	// {
	// 	list1.pushindex(i, i);
	// }
	// list1.write();
	
	list1.read();
	list1.show(); 
	

	return 0;
}



