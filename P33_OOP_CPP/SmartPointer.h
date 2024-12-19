#pragma once


template<class T>
class SmartPointer
{
	T* ptr;

public:
	SmartPointer(T* ptr) : ptr(ptr)	{ }

	~SmartPointer() { delete ptr; }

	SmartPointer(const SmartPointer& obj) = delete;
	/*{
		ptr = new T();
		*ptr = *obj.ptr;
	}*/

	SmartPointer(const SmartPointer&& obj)
	{
		ptr = obj.ptr;
		obj.ptr = nullptr;
	}

	SmartPointer& operator=(const SmartPointer& obj) = delete;
	/*{ 
		if (&obj == this)
			return *this;

		delete ptr;

		ptr = new T();
		*ptr = *obj.ptr;

		return *this;
	}*/

	SmartPointer& operator=(const SmartPointer&& obj)
	{
		if (&obj == this)
			return *this;

		delete ptr;

		ptr = obj.ptr;
		obj.ptr = nullptr;

		return *this;
	}

	T& operator*() { return *ptr; }

	T* operator->() { return ptr; }
};

