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

	Array& operator=(const Array& obj)
	{
		if (this == &obj)
			return *this;

		delete arr;

		size = obj.size;
		arr = new int[size];
		for (size_t i = 0; i < size; i++)
		{
			arr[i] = obj.arr[i];
		}

		return *this;
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

	Array operator+(const Array& a);

	Array operator+(int a);
	
	void operator+=(const Array& a);

	int& operator[](int index);

	void operator()(int s);


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

Array Array::operator+(const Array& a)
{
	Array newArr(this->size + a.size);

	for (size_t i = 0; i < this->size; i++)
	{
		newArr.arr[i] = this->arr[i];
	}

	for (size_t i = 0; i < a.size; i++)
	{
		newArr.arr[i + this->size] = a.arr[i];
	}
	
	return newArr;
}

void Array::operator+=(const Array& a)
{
	*this = *this + a;
}

int& Array::operator[](int index)
{
	return arr[index];
}

void Array::operator()(int s)
{
	delete arr;
	size = s;
	arr = new int[size];
	fill();
}
