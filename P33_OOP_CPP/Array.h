#pragma once
#include"Fraction.h"

using namespace std;

template<class T>
class Array
{
	T* arr;
	int _size;
	int _grow = 1;
	int _capacity;

public:
	Array()
	{
		arr = nullptr;
		_capacity = 0;
	}

	explicit Array(int s, int _grow = 1)
	{
		_capacity = s;
		this->_grow = _grow;
		create(s);
	}

	~Array()
	{
		delete arr;
	}

	Array(const Array& obj)
	{
		_capacity = obj._capacity;
		_size = obj._size;
		_grow = obj._grow;
		arr = new T[_capacity];
		for (size_t i = 0; i < _capacity; i++)
		{
			arr[i] = obj.arr[i];
		}
	}

	Array& operator=(const Array& obj)
	{
		if (this == &obj)
			return *this;

		delete arr;

		_capacity = obj._capacity;
		_size = obj._size;
		_grow = obj._grow;
		arr = new T[_capacity];
		for (size_t i = 0; i < _capacity; i++)
		{
			arr[i] = obj.arr[i];
		}

		return *this;
	}


	void create(int s)
	{
		_capacity = s;
		arr = new T[_capacity];
	}

	void fill(int min, int max);

	void fill();

	void print() const
	{
		for (size_t i = 0; i < _size; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}


	void add(const T& value);

	Array operator+(const Array& a);

	void operator+=(const Array& a);

	T& operator[](int index);

	void operator()(int s);

	void for_each(void(*func)(T&));

	int size() const;

	int grow() const;

	int capacity() const;

	const T* getData() const;
};

template<class T>
void Array<T>::fill()
{
	_size = _capacity;
	for (size_t i = 0; i < _capacity; i++)
	{
		arr[i] = T();
	}
}


template<>
void Array<Fraction>::fill()
{
	_size = _capacity;
	for (size_t i = 0; i < _capacity; i++)
	{
		arr[i] = Fraction(rand() % 10, rand() % 9 + 1);
	}
}

template<>
void Array<int>::fill(int min, int max) 
{
	_size = _capacity;
	for (size_t i = 0; i < _capacity; i++)
	{
		arr[i] = rand() % (max - min + 1) + min;
	}
}

template<>
void Array<int>::fill()
{
	_size = _capacity;
	for (size_t i = 0; i < _capacity; i++)
	{
		arr[i] = rand() % 10;
	}
}


template<class T>
void Array<T>::add(const T& value)
{
	if (_size == _capacity)
	{
		T* temp = new T[_capacity + _grow];
		for (size_t i = 0; i < _size; i++)
		{
			temp[i] = arr[i];
		}
		temp[_size] = value;
		delete arr;
		arr = temp;
		_capacity += _grow;
	}
	else
	{
		arr[_size] = value;
	}
	_size++;
}

template<class T>
Array<T> Array<T>::operator+(const Array& a)
{
	Array newArr(this->_size + a._size);

	for (size_t i = 0; i < this->_size; i++)
	{
		newArr.arr[i] = this->arr[i];
	}

	for (size_t i = 0; i < a._size; i++)
	{
		newArr.arr[i + this->_size] = a.arr[i];
	}

	return newArr;
}

template<class T>
void Array<T>::operator+=(const Array& a)
{
	*this = *this + a;
}

template<class T>
T& Array<T>::operator[](int index)
{
	return arr[index];
}

template<class T>
void Array<T>::operator()(int s)
{
	delete arr;
	_size = s;
	arr = new T[_size];
	fill();
}

template<class T>
void Array<T>::for_each(void(*func)(T&))
{
	for (size_t i = 0; i < _size; i++)
	{
		func(arr[i]);
	}
}

template<class T>
int Array<T>::size() const
{
	return _size;
}

template<class T>
int Array<T>::grow() const
{
	return _grow;
}

template<class T>
int Array<T>::capacity() const
{
	return _capacity;
}

template<class T>
const T* Array<T>::getData() const
{
	return arr;
}
