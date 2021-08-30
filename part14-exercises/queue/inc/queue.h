#include <iostream>
#include <string>

#ifndef INC_QUEUE_H_
#define INC_QUEUE_H_ 1

class exeptions
{
public:
	std::string where;
	std::string what;
	exeptions(std::string where, std::string what): where(where), what(what) { }
};

template <typename T>
class Queue
{
private:
	class Node
	{
	public:
		T data;
		Node *next;			// ��������� �� ��������� �������
		Node *previous;		// ��������� �� ����������
		Node(T data): data(data), next(nullptr), previous(nullptr) { }
	};
	Node *head;
	Node *tail;
	int size;
public:
	Queue(): head(nullptr), tail(nullptr), size(0){  }
	~Queue();

	Queue(const Queue<T> &);
	Queue<T>& operator= (const Queue<T> &);

	void push(T data);
	void pop();
	void showQueue()const;
};

/*
 * 		���������� ����������� ������� ��������� ������ Queue ���������� � ��������� queue.cpp
 * 	�����.
 * 		C++ ����������� ����� �� �����������. ��� ����������� .h � main.cpp, ����������� ���-
 * 	������� ������ ���������� � main.cpp. ���������� ������, ��� ����� ������� ��������� ������-
 * 	���� ������ ���� <int>, ������� ��� � ������������ ���� ��� ��� ����� main.cpp
 * 		����� �������� ���������� queue.cpp, ���������� �������, ��� � �����������
 * 	��������� ������� ������ <int> � �� ������� ���������� ������� <int>.
 * 		��������� ������, �.� ���������� �� ������ ����� ������ ����������� �������.
 *
 * 		����� �������� ������, ����� ���������� .cpp ����� #include. �� ��� .cpp ������ ����
 * 	���������, ����� �� ����������� ��� ����� � ������ ������.
 * 		����� ������� inline ���� � ���������� � queue.h ��� ������ �������� ��� �����������
 * 	������� ������ � .h. ��� � � ������. � ���� ���� ��� �� ���������� ������� inline ����
 * 	� Eclipse IDE
 *
 */

template<typename T>
Queue<T>::~Queue()
{
	while(tail)
	{
		Node *temp = tail;
		tail = temp->previous;
		delete temp;
		size--;
	}
}


template<typename T>
Queue<T>::Queue(const Queue<T> &other)
{
	if (other.size == 0) throw exeptions("Copy contructor error.", "Queue has no elements");
	size = 0;
	/*
	 * 		���� ���� ����� ���������� ������������ �����������, �������� � head, �� ���������
	 * 	������ � �������� �������� ���������. �.� ������ ������ ���������� ����� ��������� �
	 * 	������� ��������� ������
	*/
	Node *current = other.tail;
	Node *temp;
	while (current)
	{
		temp = new Node(current->data);
		if (size == 0) head = tail = temp;
		else
		{
			temp->next = head;
			head->previous = temp;
			head = temp;
		}
		current = current->previous;
		size++;
	}
}


template<typename T>
Queue<T>& Queue<T>::operator= (const Queue<T> &other)
{
	if (other.size == 0) throw exeptions("Operator= error.", "Queue has no elements");
	size = 0;
	Node *current = other.tail;
	Node *temp;
	while (current)
	{
		temp = new Node(current->data);
		if (size == 0) head = tail = temp;
		else
		{
			temp->next = head;
			head->previous = temp;
			head = temp;
		}
		current = current->previous;
		size++;
	}
	return *this;
}


template<typename T>
void Queue<T>::push(T data)
{
	Node *temp = new Node(data); 		// this->data = data, next = previous = nullptr
	if (size == 0)	head = tail = temp;
	else
	{
		temp->next = head;
		head->previous = temp;
		head = temp;
	}
	size++;
}


template<typename T>
void Queue<T>::pop()
{
	if (size == 0) throw exeptions("Error recovering from the queue.", "Queue is empty");
	Node *temp = tail;
	if (tail == head)
	{
		delete head;
		head = tail = nullptr;
	}
	else
	{
		tail = temp->previous;
		tail->next = nullptr;
		delete temp;
	}
	size--;
}



template<typename T>
void Queue<T>::showQueue()const
{
	if (size == 0) throw exeptions("ShowQueue error.", "Queue is empty");
	std::cout << "ShowQueue" << std::endl;
	Node *temp = head;	int count = 1;
	while(temp)
	{
		std::cout << temp->data;
		if (size == 1)
		{
			std::cout << " <--- head = tail;" << std::endl;
			break;
		}
		else if (count == 1) std::cout << " <--- head;";
		else if (count == size) std::cout << " <--- tail;";
		std::cout << std::endl;
		count++;	temp = temp->next;
	}
	std::cout << std::endl;
}





#endif /* INC_QUEUE_H_ */
