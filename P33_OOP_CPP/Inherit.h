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


class Device
{
public:
	int id;

	Device(int id) : id(id) {}

	int getId() { return id; }
};

class WiFi : virtual public Device
{
public:
	WiFi(int id) : Device(id) {}
	
};

class LAN : virtual public Device
{
public:
	LAN(int id) : Device(id) {}
};

class Router : public WiFi, public LAN
{
public:
	Router(int idWiFi, int idLAN) : WiFi(idWiFi), LAN(idLAN), Device(200) {}

};

