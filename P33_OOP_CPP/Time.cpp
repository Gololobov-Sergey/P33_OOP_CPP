#include<iostream>

#include "Time.h"

using namespace std;

Time::Time() : Time(0) { cout << "C0" << endl; }

Time::Time(int s) : Time(0, s) { cout << "C1" << endl; }

Time::Time(int m, int s) : Time(0, m, s) { cout << "C2" << endl; }

Time::Time(int h, int m, int s) : hour(h), minute(m), second(s) { cout << "C3" << endl; }

void Time::print()
{

}
