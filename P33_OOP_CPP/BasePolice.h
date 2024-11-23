#pragma once
#include<iostream>


#include"List.h"
#include"BTree.h"
#include"Menu.h"



using namespace std;

typedef bool BOOL_;

class Protocol
{
	size_t id;
	string number;
	string numPP;
	string date;
	size_t summ;
	BOOL_  pay = false;
	 
public:

	friend istream& operator>> (istream& in, Protocol p);
	friend ofstream& operator<< (ofstream& in, const Protocol& p);
};


istream& operator>>(istream& in, Protocol p)
{
	cout << "ID        : "; in >> p.id; in.ignore();
	cout << "Number TZ : "; getline(in, p.number);
	cout << "Date      : "; getline(in, p.date);
	cout << "Num PP    : "; getline(in, p.numPP);
	cout << "Summa     : "; in >> p.summ; in.ignore();
	return in;
}
class BasePolice
{
	BTree<string, List<Protocol>> base;

public:
	void menu()
	{
		while (true)
		{
			system("cls");
			int c = Menu::select_vertical({ "Add protocol", "Print number", "Print diapason", "Pay protoñol", "Exit" }, HorizontalAlignment::Center);
			switch (c)
			{
			default:
				break;
			}
		}
	}
};

