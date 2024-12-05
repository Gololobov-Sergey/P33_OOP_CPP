#pragma once
#include<iostream>
#include<fstream>

using namespace std;


class Shape
{
protected:
	int x, y;

public:
	Shape(int x, int y) : x(x), y(y) {}

	virtual ~Shape() {}

	virtual void save(ofstream& out) = 0;
	virtual void load(ifstream& in) = 0;
	//virtual void show() = 0;
};


class Square : public Shape
{
	int a;

public:

	Square(int x, int y, int a) : Shape(x, y), a(a) {}

	virtual void save(ofstream& out) override
	{
		out << "S" << endl;
		out << x << " " << y << " " << a << endl;
	}

	virtual void load(ifstream& in) override
	{
		in >> x >> y >> a;
	}
};


class Rectangle_ : public Shape
{
	int width;
	int height;

public:
	Rectangle_(int x, int y, int w, int h) : Shape(x, y), width(w), height(h) {}

	virtual void save(ofstream& out) override
	{
		out << x << " " << y << " " << width << " " << height << endl;
	}

	virtual void load(ifstream& in) override
	{
		in >> x >> y >> width >> height;
	}
};

class Circle : public Shape
{
	int radius;

public:

	Circle(int x, int y, int radius) : Shape(x, y), radius(radius) {}

	virtual void save(ofstream& out) override
	{
		out << "C" << endl;
		out << x << " " << y << " " << radius << endl;
	}

	virtual void load(ifstream& in) override
	{
		in >> x >> y >> radius;
	}
};
