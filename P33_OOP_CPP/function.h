#pragma once

template<class T>
void addValueArray(T*& arr, int& size, T value)
{
	T* t = new T[size + 1];
	for (size_t i = 0; i < size; i++)
	{
		t[i] = arr[i];
	}

	t[size] = value;

	delete arr;

	size++;

	arr = t;
}
