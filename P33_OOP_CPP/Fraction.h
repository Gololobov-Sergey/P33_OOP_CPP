#pragma once
#include <iostream>
#include"Reservoir.h"
using namespace std;

class Fraction
{
	int num;
	int den;

public:
	Fraction() : num(0), den(1) {}
	Fraction(int num, int den) {
		if (den == 0) {
			cout << "Знаменатель не может быть нулем!" << endl;
		}
		this->num = num;
		this->den = den;

	}
	int getNum();
	int getDen();
	void setNum(int num);
	void setDen(int den);
	Fraction add(const Fraction& obj);
	Fraction min(const Fraction& obj);
	void print() const;
	Fraction multiply(const Fraction& other);
	Fraction divide(const Fraction& other);

	Fraction operator-();

	Fraction operator++(); //pre

	Fraction operator++(int); //post

	

	Fraction operator+(Fraction f);


	auto operator<=>(const Fraction& f) const;


	operator float();
	operator Reservoir();

	void operator()(int a, int b);

	friend ostream& operator<<(ostream& out, const Fraction& f);

};

ostream& operator<<(ostream& out, const Fraction& f)
{
	out << f.num << "/" << f.den;
	return out;
}

void Fraction::setDen(int den)
{
	this->den = den;
}
int Fraction::getNum()
{
	return num;
}
int Fraction::getDen()
{
	return den;
}
void Fraction::setNum(int num)
{
	this->num = num;
}
Fraction Fraction::add(const Fraction& other) {
	int newNum = num * other.den + other.num * den;
	int newDen = den * other.den;
	return Fraction(newNum, newDen);
}
Fraction Fraction::min(const Fraction& obj)
{
	int newNum = num * obj.den - obj.num * den;
	int newDen = den * obj.den;
	return Fraction(newNum, newDen);

}
Fraction Fraction::multiply(const Fraction& other) {
	int newNum = num * other.num;
	int newDen = den * other.den;
	return Fraction(newNum, newDen);
}


Fraction Fraction::divide(const Fraction& other) {
	if (other.num == 0) {
		throw invalid_argument("Деление на ноль!");
	}
	int newNum = num * other.den;
	int newDen = den * other.num;
	return Fraction(newNum, newDen);
}

Fraction Fraction::operator-()
{
	return Fraction(-num, den);
}

Fraction Fraction::operator++()
{
	num += den;
	return *this;
}

Fraction Fraction::operator++(int)
{
	Fraction res = *this;
	num += den;
	return res;

}

inline Fraction Fraction::operator+(Fraction f)
{
	int newNum = num * f.den + f.num * den;
	int newDen = den * f.den;
	return Fraction(newNum, newDen);
}

Fraction::operator float()
{
	return (float)num / den;
}

Fraction::operator Reservoir()
{
	return Reservoir(TYPE::LAKE, "werwer", num, den, 0);
}

void Fraction::operator()(int a, int b)
{
	num = a;
	den = b;
}


auto Fraction::operator<=>(const Fraction& f) const
{
	return (float)num / den <=> (float)f.num / f.den;
}


void Fraction::print() const 
{
	cout << num << "/" << den << endl;
}


//Fraction operator+(Fraction f1, Fraction f2)
//{
//	int newNum = f1.getNum() * f2.getDen() + f2.getNum() * f1.getDen();
//	int newDen = f1.getDen() * f2.getDen();
//	return Fraction(newNum, newDen);
//}