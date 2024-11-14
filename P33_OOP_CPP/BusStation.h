#pragma once
#include<iostream>
#include<Windows.h>
#include"Queue.h"

using namespace std;

class Passenger
{
	int time = 0;

public:
    void addTime()
    {
        time++;
    }
};


void IncTime(Passenger& p)
{
    p.addTime();
}

class Bus
{

};

class BusStation
{

    int tpas = 2;
    int tbus = 10;
	Queue<Passenger> pass;


public:

	void model()
	{


        int i = 0;

        while (true)
        {
            if (i % tpas == 0)
            {
                cout << "Pass" << endl;
                // pass++ q
            }

            if (i % tbus == 0)
            {
                cout << "Bus" << endl;

            }

            i++;
            Sleep(300);
            pass.for_each(IncTime);
        }
	}
};

