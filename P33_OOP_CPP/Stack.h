#pragma once

#include"Node.h"


template<class T, size_t maxSize>
class Stack
{
	Node<T>* first = nullptr;
	size_t   size  = 0;

public:
	Stack();

	~Stack();

	Stack(const Stack& st);

	Stack& operator=(const Stack& st);

	bool push(const T& value);

	void pop();

	T peek() const;

	bool isEmpty() const;

	size_t length() const;

	void clear();

	void print() const;
};

template<class T, size_t maxSize>
Stack<T, maxSize>::Stack()
{
}

template<class T, size_t maxSize>
Stack<T, maxSize>::~Stack()
{
	clear();
}

template<class T, size_t maxSize>
Stack<T, maxSize>::Stack(const Stack& st)
{
	Node<T>* temp = st.first;
	first = new Node<T>(temp->value);
	Node<T>* temp1 = first;
	while (temp->next)
	{
		temp = temp->next;
		temp1->next = new Node<T>(temp->value);
		temp1 = temp1->next;
	}
	size = st.size;
}

template<class T, size_t maxSize>
Stack<T, maxSize>& Stack<T, maxSize>::operator=(const Stack<T, maxSize>& st)
{
	// TODO: вставьте здесь оператор return
}

template<class T, size_t maxSize>
bool Stack<T, maxSize>::push(const T& value)
{
	if (size < maxSize)
	{
		if (size == 0)
		{
			first = new Node<T>(value);
		}
		else
		{
			Node<T>* newNode = new Node<T>(value);
			newNode->next = first;
			first = newNode;
		}
		size++;
		return true;
	}
	return false;
}

template<class T, size_t maxSize>
void Stack<T, maxSize>::pop()
{
	if (size > 0)
	{
		Node<T>* temp = first;
		first = first->next;
		delete temp;
		size--;
	}
}

template<class T, size_t maxSize>
T Stack<T, maxSize>::peek() const
{
	return first->value;
}

template<class T, size_t maxSize>
bool Stack<T, maxSize>::isEmpty() const
{
	return size == 0;
}

template<class T, size_t maxSize>
size_t Stack<T, maxSize>::length() const
{
	return size;
}

template<class T, size_t maxSize>
void Stack<T, maxSize>::clear()
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

template<class T, size_t maxSize>
void Stack<T, maxSize>::print() const
{
	Node<T>* temp = first;
	while (temp)
	{
		cout << temp->value << " ";
		temp = temp->next;
	}
	cout << endl;
}
