#pragma once
#include<iostream>
#include"List.h"

using namespace std;


class Passport
{
	string name;
	string series;
	int number;

public:

};


class Visa
{
	string country;
	string date;
	string period;
};

class ForeignPassport : public Passport
{
	List<Visa> visas;

public:

	void addVisa(Visa& v)
	{
		visas.push_back(v);
	}
};