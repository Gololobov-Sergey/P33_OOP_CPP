#pragma once
#include<iostream>

using namespace std;


class Animal
{
	string name;
	int age;

public:
	Animal(string name, int age) : name(name), age(age) { voice(); }

	virtual ~Animal() { cout << "Dest Animal" << endl; }

	void info()
	{
		cout << "Name : " << name << endl;
		cout << "Age  : " << age << endl;
	}

	virtual void voice() = 0;
};

void Animal::voice()
{
	cout << "????????" << endl;
}


class Cat : public Animal
{
public:
	Cat(string name, int age) : Animal(name, age) {}

	~Cat() { cout << "Dest Cat" << endl; }

	virtual void voice() override
	{
		cout << "Mau Mau" << endl;
	}
};


class SiamCat : public Animal
{
public:
	SiamCat(string name, int age) : Animal(name, age) {}

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
		Animal::voice();
	}
};

