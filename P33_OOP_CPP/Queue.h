#pragma once
#include<initializer_list>


#include"Node.h"

using namespace std;


template<class T>
class Queue
{
	Node<T>* first = nullptr;
	Node<T>* last  = nullptr;
	size_t size;

public:
	Queue();
	Queue(initializer_list<T> list);
	~Queue();
	Queue(const Queue& q);
	Queue& operator=(const Queue& q);

	void enqueue(const T& value);
	void dequeue();

	T peek();
	size_t length();
	void clear();
	void print();

	void ring();

	void for_each(void(*func)(T&));
};

template<class T>
Queue<T>::Queue()
{
}

template<class T>
Queue<T>::Queue(initializer_list<T> list)
{
	for (T elem : list)
	{
		enqueue(elem);
	}
}

template<class T>
Queue<T>::~Queue()
{
	clear();
}

template<class T>
Queue<T>::Queue(const Queue& q)
{
}

template<class T>
Queue<T>& Queue<T>::operator=(const Queue& q)
{
	// TODO: вставьте здесь оператор return
	return nullptr;
}

template<class T>
void Queue<T>::enqueue(const T& value)
{
	if (size == 0)
	{
		first = last = new Node<T>(value);
	}
	else
	{
		last->next = new Node<T>(value);
		last = last->next;
	}
	size++;
}

template<class T>
void Queue<T>::dequeue()
{
	if (size > 0)
	{
		Node<T>* temp = first;
		first = first->next;
		delete temp;
		size--;
	}
}

template<class T>
T Queue<T>::peek()
{
	return first->value;
}

template<class T>
size_t Queue<T>::length()
{
	return size;
}

template<class T>
void Queue<T>::clear()
{
	if (size > 0)
	{
		Node<T>* temp = first;
		while (temp)
		{
			first = first->next;
			delete temp;
			temp = first;
		}
		size = 0;
	}
}

template<class T>
void Queue<T>::print()
{
	Node<T>* temp = first;
	while (temp)
	{
		cout << temp->value << " ";
		temp = temp->next;
	}
	cout << endl;
}

template<class T>
void Queue<T>::ring()
{
	/*T elem = peek();
	dequeue();
	enqueue(elem);*/

	last->next = first;
	first = first->next;
	last = last->next;
	last->next = nullptr;

}

template<class T>
void Queue<T>::for_each(void(*func)(T&))
{
	Node<T>* temp = first;
	while (temp)
	{
		func(temp->value);
		temp = temp->next;
	}
}
