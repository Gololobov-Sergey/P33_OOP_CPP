#include "Time.h"

Time::Time() : Time(0) { }

Time::Time(int s) : Time(0, s) { }

Time::Time(int m, int s) : Time(0, m, s) { }

Time::Time(int h, int m, int s) : hour(h), minute(m), second(s) { }

void Time::print()
{

}
