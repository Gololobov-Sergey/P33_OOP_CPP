#pragma once


class Array
{
	int* arr;
	int size;

public:
	Array()
	{
		arr = nullptr;
		size = 0;
	}

	explicit Array(int s)
	{
		create(s);
	}

	~Array()
	{
		delete arr;
	}

	Array(const Array& obj)
	{
		size = obj.size;
		arr = new int[size];
		for (size_t i = 0; i < size; i++)
		{
			arr[i] = obj.arr[i];
		}
	}

	void create(int s)
	{
		size = s;
		arr = new int[size];
	}

	void fill() const
	{
		for (size_t i = 0; i < size; i++)
		{
			arr[i] = rand() % 10;
		}
	}

	void print() const
	{
		for (size_t i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}


	void add(int value);

};

void Array::add(int value)
{
	int* temp = new int[size + 1];
	for (size_t i = 0; i < size; i++)
	{
		temp[i] = arr[i];
	}
	temp[size] = value;
	delete arr;
	arr = temp;
	size++;
}