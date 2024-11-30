#pragma once

#include<iostream>

using namespace std;


class Human
{
protected:
	string name;
	int age;

public:
	Human() {}

	Human(string n, int a) : name(n), age(a) { cout << "Ctor Human" << endl; }

	void info()
	{
		cout << "Name : " << name << endl;
		cout << "Age  : " << age << endl;
	}

	void kill()
	{

	}
};


class Stud : public Human
{
	int iq;
	
public:
	Stud(string n, int a, int iq) : iq(iq), Human(n, a) { cout << "Ctor Stud" << endl; }

	void info()
	{
		name = "";
		Human::info();
		cout << "IQ   : " << iq << endl;
	}

	void kill() = delete;

};



class A
{
	int a1;

protected:
	int a2;

public:
	int a3;

	void a() {}
};

class B : private A
{
	int b1;

protected:
	int b2;

public:
	int b3;

	void b()
	{
		a();
		//a1 = 8;
		a2 = 5;
		a3 = 6;
	}
};

class C : public B
{
public:
	void c()
	{
		//a3 = 9;
	}
};