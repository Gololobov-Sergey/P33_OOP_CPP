#pragma once
#include<iostream>
#include"function.h"

using namespace std;

class Student
{

	char* name;
	int age;
	int* marks = nullptr;
	int size = 0;

	static int count;

public:

	

	Student()
	{
		age = 0;
		setName("No name");
		cout << "Constructor" << endl;
	}

	Student(const char* n, int a)
	{
		setAge(a);
		setName(n);
		cout << "Constructor" << endl;
	}

	~Student()
	{
		delete name;
		delete marks;
		cout << "Destructor" << endl;
	}

	void setAge(int a)
	{
		if (a > 100 || a < 0)
			return;
		age = a;
	}

	int getAge()
	{
		return age;
	}

	void setName(const char* n)
	{
		if (name != nullptr)
			delete name;

		name = new char[strlen(n) + 1];
		for (size_t i = 0; i < strlen(n) + 1; i++)
		{
			name[i] = n[i];
		}
	}

	char* getName()
	{
		return name;
	}

	void print()
	{
		cout << "Name  : " << name << endl;
		cout << "Age   : " << age << endl;
		cout << "Marks : ";
		for (size_t i = 0; i < size; i++)
		{
			cout << marks[i] << " ";
		}
		cout << endl;
	}

	void addMark(int mark)
	{
		if(mark > 0 && mark < 13)
			addValueArray(marks, size, mark);
	}

	int* getMarks()
	{
		return marks;
	}


	static int getCount()
	{
		return count;
	}
};

int Student::count = 100;
