#pragma once
#include<iostream>

using namespace std;


class Printable
{
public:
	virtual void print() = 0;
};

class Animal
{
	string name;
	int age;

public:
	Animal(string name, int age) : name(name), age(age) {  }

	virtual ~Animal() { cout << "Dest Animal" << endl; }

	void info() const
	{
		cout << "Name : " << name << endl;
		cout << "Age  : " << age << endl;
	}

	virtual void voice()
	{
		cout << "????????" << endl;
	}
};

//void Animal::voice()
//{
//	cout << "????????" << endl;
//}


class Cat : public Animal, public Printable
{
	int mouse = 0;

public:
	Cat(string name, int age) : Animal(name, age) {}

	~Cat() { cout << "Dest Cat" << endl; }

	virtual void voice() override
	{
		cout << "Mau Mau" << endl;
	}

	virtual void print() override
	{
		info();
	}

	void CatchMouse()
	{
		mouse++;
	}

	void getMouse()
	{
		cout << mouse << endl;
	}

};


class SiamCat : public Cat
{
public:
	SiamCat(string name, int age) : Cat(name, age) {}

	virtual void voice() override
	{
		cout << "Myau Myau" << endl;
	}
};


class Dog : public Animal
{
public:
	Dog(string name, int age) : Animal(name, age) {}

	virtual void voice() override
	{
		cout << "Gaw Gaw" << endl;
	}
};


class Fish : public Animal
{
public:

	Fish(string name, int age) : Animal(name, age) {}

	virtual void voice() override
	{
		//Animal::voice();
	}
};

