#pragma once
#include<iostream>

using namespace std;

class Engine
{
public:
	void start()
	{
		cout << "Engine started" << endl;
	}

	void stop()
	{
		cout << "Engine stoped" << endl;
	}
};


class Car
{
	Engine* engine;

public:
	Car() { engine = new Engine; }

	~Car() { delete engine; }

	void move()
	{
		engine->start();
		cout << "Car move" << endl;
		engine->stop();
	}
};