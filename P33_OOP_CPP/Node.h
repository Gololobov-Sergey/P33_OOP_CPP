#pragma once

template<class T, class TPri = int>
struct Node
{
	T value;
	TPri priority;
	Node* next;

	Node(T val) : value(val), next(nullptr), priority(TPri()) {}
	Node(T val, TPri pri) : value(val), next(nullptr), priority(pri) {}
};

