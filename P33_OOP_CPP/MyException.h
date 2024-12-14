#pragma once
#include<iostream>
#include<string>
#include<fstream>

using namespace std;



class MyException
{
	string date;
	string time;
	int line;
	string message;
	string file;

	string path;
	string message_all;

public:
	MyException(string d, string t, int l, string m, string f, string p) :date(d), time(t), file(f), line(l), message(m), path(p)
	{
		message_all = d + " | " + t + " | " + f + " | " + to_string(l) + " | " + m;
	}

	string getError()
	{
		return message_all;
	}

	void saveToFile()
	{
		ofstream out(path, ios::app);
		out << message_all << endl;
		out.close();
	}
};

