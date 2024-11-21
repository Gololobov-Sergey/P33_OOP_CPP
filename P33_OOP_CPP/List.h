#pragma once
#include<iostream>
#include<initializer_list>
#include<cassert>

#include"Node.h"


using namespace std;

template<class T, class TPri = int>
class List
{
	Node<T, TPri>* first = nullptr;
	Node<T, TPri>* last = nullptr;
	size_t         size = 0;

	Node<T, TPri>* getNode(size_t index);

public:
	List();
	List(initializer_list<T> list);
	~List();
	List(const List& list);
	List& operator=(const List& list);

	void push_front(const T& value);
	void push_back(const T& value);
	void insert(const T& value, size_t index);

	void pop_front();
	void pop_back();
	void remove(size_t index);

	T back() const;
	T front() const;
	T& operator[](size_t index);

	size_t length() const;
	void clear();
	void print() const;
	void printReverse() const;

	void sort();
	List operator+(const List& list);
	void for_each(void(*method)(T&));
};

template<class T, class TPri>
Node<T, TPri>* List<T, TPri>::getNode(size_t index)
{
	Node<T, TPri>* temp;
	if (index < size / 2)
	{
		temp = first;
		for (size_t i = 0; i < index; i++)
		{
			temp = temp->next;
		}
	}
	else
	{
		temp = last;
		for (size_t i = 0; i < size - index - 1; i++)
		{
			temp = temp->prev;
		}
	}
	cout << 1 << endl;
	return temp;
}

template<class T, class TPri>
List<T, TPri>::List()
{
}

template<class T, class TPri>
List<T, TPri>::List(initializer_list<T> list)
{
	for (T elem : list)
	{
		push_back(elem);
	}
}

template<class T, class TPri>
List<T, TPri>::~List()
{
	clear();
}

template<class T, class TPri>
List<T, TPri>::List(const List& list)
{
}

template<class T, class TPri>
List<T, TPri>& List<T, TPri>::operator=(const List& list)
{
	return List<T, TPri>();
}

template<class T, class TPri>
void List<T, TPri>::push_front(const T& value)
{
	Node<T, TPri>* newNode = new Node<T, TPri>(value);
	if (size == 0)
	{
		first = last = newNode;
	}
	else
	{
		newNode->next = first;
		first->prev = newNode;
		first = newNode;
	}
	size++;
}

template<class T, class TPri>
void List<T, TPri>::push_back(const T& value)
{
	Node<T, TPri>* newNode = new Node<T, TPri>(value);
	if (size == 0)
	{
		first = last = newNode;
	}
	else
	{
		last->next = newNode;
		newNode->prev = last;
		last = newNode;
	}
	size++;
}

template<class T, class TPri>
void List<T, TPri>::insert(const T& value, size_t index)
{
	if (index >= 0 && index <= size)
	{
		if (index == 0)
		{
			push_front(value);
		}
		else if (index == size)
		{
			push_back(value);
		}
		else
		{
			Node<T, TPri>* pos = getNode(index - 1);
			Node<T, TPri>* newNode = new Node<T, TPri>(value);
			newNode->next = pos->next;
			pos->next->prev = newNode;
			pos->next = newNode;
			newNode->prev = pos;
			size++;
		}
	}
}

template<class T, class TPri>
void List<T, TPri>::pop_front()
{
	if (size > 0)
	{
		Node<T, TPri>* temp = first;
		first = first->next;
		delete temp;
		size--;
		if (size > 0)
		{
			first->prev = nullptr;
		}
	}
}

template<class T, class TPri>
void List<T, TPri>::pop_back()
{
	if (size > 0)
	{
		Node<T, TPri>* temp = last;
		last = last->prev;
		delete temp;
		size--;
		if (size > 0)
		{
			last->next = nullptr;
		}
		if (size == 0)
		{
			first = nullptr;
		}
	}
}

template<class T, class TPri>
void List<T, TPri>::remove(size_t index)
{
	if (index >= 0 && index < size)
	{
		if (index == 0)
		{
			pop_front();
		}
		else if (index == size - 1)
		{
			pop_back();
		}
		else
		{
			Node<T, TPri>* pos = getNode(index - 1);
			Node<T, TPri>* temp = pos->next;
			pos->next = temp->next;
			temp->next->prev = pos;
			delete temp;
			size--;
		}
	}
}

template<class T, class TPri>
T List<T, TPri>::back() const
{
	if(last)
		return last->value;
	return T();
}

template<class T, class TPri>
T List<T, TPri>::front() const
{
	if (first)
		return first->value;
	return T();
}

template<class T, class TPri>
T& List<T, TPri>::operator[](size_t index)
{
	assert(index >= 0 && index < size);
	return getNode(index)->value;
}

template<class T, class TPri>
void List<T, TPri>::clear()
{
	Node<T, TPri>* temp = first;
	while (temp)
	{
		first = first->next;
		delete temp;
		temp = first;
	}
	size = 0;
}

template<class T, class TPri>
void List<T, TPri>::print() const
{
	Node<T, TPri>* temp = first;
	while (temp)
	{
		cout << temp->value << " ";
		temp = temp->next;
	}
	cout << endl;
}

template<class T, class TPri>
void List<T, TPri>::printReverse() const
{
	Node<T, TPri>* temp = last;
	while (temp)
	{
		cout << temp->value << " ";
		temp = temp->prev;
	}
	cout << endl;
}

template<class T, class TPri>
void List<T, TPri>::sort()
{
	for (size_t i = 0; i < size - 1; i++)
	{
		for (size_t j = 0; j < size - 1 - i; j++)
		{
			Node<T, TPri>* temp = getNode(j);
			if (temp->value > temp->next->value) 
			{
				swap(temp->value, temp->next->value);
			}
		}
	}
}
