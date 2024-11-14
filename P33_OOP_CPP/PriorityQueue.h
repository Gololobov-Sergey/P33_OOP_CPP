#pragma once
#include<initializer_list>


#include"Node.h"

using namespace std;


template<class T, class TPri = int>
class PriorityQueue
{
	Node<T>* first = nullptr;
	Node<T>* last = nullptr;
	size_t size;

public:
	PriorityQueue();
	~PriorityQueue();
	PriorityQueue(const PriorityQueue& q);
	PriorityQueue& operator=(const PriorityQueue& q);

	void   enqueue(const T& value, TPri priority);
	void   dequeue();

	T      peek();
	size_t length();
	void   clear();
	void   print();

};

template<class T, class TPri>
PriorityQueue<T, TPri>::PriorityQueue()
{
}



template<class T, class TPri>
PriorityQueue<T, TPri>::~PriorityQueue()
{
	clear();
}

template<class T, class TPri>
PriorityQueue<T, TPri>::PriorityQueue(const PriorityQueue& q)
{
}

template<class T, class TPri>
PriorityQueue<T, TPri>& PriorityQueue<T, TPri>::operator=(const PriorityQueue& q)
{
	return PriorityQueue<T, TPri>();
}

template<class T, class TPri>
void PriorityQueue<T, TPri>::enqueue(const T& value, TPri priority)
{
	Node<T, TPri>* newNode = new Node<T, TPri>(value, priority);

	if (size == 0)
	{
		first = last = newNode;
		size++;
		return;
	}

	if (priority <= last->priority)
	{
		last->next = newNode;
		last = newNode;
	}
	else if (priority > first->priority)
	{
		newNode->next = first;
		first = newNode;
	}
	else
	{
		Node<T, TPri>* pos = first;
		while (priority <= pos->next->priority)
		{
			pos = pos->next;
		}
		newNode->next = pos->next;
		pos->next = newNode;
	}
	size++;

}

template<class T, class TPri>
void PriorityQueue<T, TPri>::dequeue()
{
	if (size > 0)
	{
		Node<T>* temp = first;
		first = first->next;
		delete temp;
		size--;
	}
}

template<class T, class TPri>
T PriorityQueue<T, TPri>::peek()
{
	return first->value;
}

template<class T, class TPri>
size_t PriorityQueue<T, TPri>::length()
{
	return size;
}

template<class T, class TPri>
void PriorityQueue<T, TPri>::clear()
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

template<class T, class TPri>
void PriorityQueue<T, TPri>::print()
{
	Node<T>* temp = first;
	while (temp)
	{
		cout << "(" << temp->priority << ", " << temp->value << ") ";
		temp = temp->next;
	}
	cout << endl;
}
