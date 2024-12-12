#pragma once
#include<iostream>
#include<fstream>

using namespace std;


class ILogProvider
{
public:
	virtual void SaveError(string message) = 0;
};


class ConsoleLog : public ILogProvider
{
public:

	virtual void SaveError(string message) override
	{
		cout << message << endl;
	}
};


class FileLog : public ILogProvider
{
	string path;

public:
	FileLog(string path) : path(path)	{ }

	virtual void SaveError(string message) override
	{
		ofstream out(path, ios::app);
		out << message << endl;
		out.close();
	}
};