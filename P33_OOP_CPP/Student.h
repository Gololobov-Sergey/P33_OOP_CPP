#pragma once
#include<iostream>
#include"myFunc.h"

using namespace std;

enum TYPE_STUDENT 
{
	ASPIRANT, DOCTOR, INTERN
};

class Student
{
	//TYPE type;

	char* name;
	int age;

	//vector<int> marks;

	int* marks = nullptr;
	int size = 0;

	static int count;

	const int id;

public:


	Student(int id = 0) : Student(id, "No name", 0) {}

	Student(int id, const char* n, int a) : id{id}
	{
		//type = TYPE::ASPIRANT;
		setAge(a);
		setName(n);
		//cout << "Constructor" << endl;
		count++;
	}

	~Student()
	{
		delete name;
		delete marks;
		//cout << "Destructor" << endl;
		count--;
	}


	Student(const Student& obj) : id(obj.id)
	{
		age = obj.age;
		size = obj.size;
		name = new char[strlen(obj.name) + 1];
		strcpy_s(name, strlen(obj.name) + 1, obj.name);
		marks = new int[size];
		for (size_t i = 0; i < size; i++)
		{
			marks[i] = obj.marks[i];
		}
		//cout << "Constructor Copy" << endl;
		count++;
	}

	Student& operator=(const Student& obj)
	{
		if (this == &obj)
			return *this;

		delete name;

		age = obj.age;
		size = obj.size;
		name = new char[strlen(obj.name) + 1];
		strcpy_s(name, strlen(obj.name) + 1, obj.name);
		marks = new int[size];
		for (size_t i = 0; i < size; i++)
		{
			marks[i] = obj.marks[i];
		}

		return *this;
	}


	void setAge(int a)
	{
		if (a > 100 || a < 0)
			return;
		age = a;
	}

	int getAge() const
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

	char* getName() const
	{
		return name;
	}

	void print() const
	{
		cout << "Name  : " << name << endl;
		cout << "Age   : " << age << endl;
		cout << "Marks : ";
		for (size_t i = 0; i < size; i++)
		{
			cout << marks[i] << " ";
		}
		cout << endl << endl;
	}

	void addMark(int mark)
	{
		if(mark > 0 && mark < 13)
			addValueArray(marks, size, mark);
	}

	int* getMarks() const
	{
		return marks;
	}

	int getSizeMarks() const
	{
		return size;
	}

	int getSumMarks() const
	{
		int sum = 0;
		for (size_t i = 0; i < size; i++)
		{
			sum += marks[i];
		}
		return sum;
	}

	static int getCount()
	{
		return count;
	}

	friend ostream& operator<<(ostream& out, const Student& st);

	bool operator<(const Student& st)
	{
		if(strcmp(this->name, st.name) == -1)
			return true;
		return false;
	}

};

int Student::count = 0;


ostream& operator<<(ostream& out, const Student& st)
{
	out << setw(10) << left << st.name << setw(5) << left << st.age << " ";
	for (size_t i = 0; i < st.size; i++)
	{
		out << st.marks[i] << " ";
	}
	return out;
}