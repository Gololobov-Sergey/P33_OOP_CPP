#pragma once

class Time
{
	int hour;
	int minute;
	int second;

public:

	Time(); 
	
	Time(int s);
	
	Time(int m, int s);

	Time(int h, int m, int s);

	void print();
};

