#pragma once
#include<iostream>
#include<iomanip>

#include"PriorityQueue.h"
#include"Queue.h"

using namespace std;

enum class DEPARTMENT
{
	GENERAL, TRANSPORT, ECONOMICS, DIRECTOR
};

ostream& operator<<(ostream& out, const DEPARTMENT& d)
{
	switch (d)
	{
	case DEPARTMENT::GENERAL:   out << "GENERAL"; break;
	case DEPARTMENT::TRANSPORT: out << "TRANSPORT"; break;
	case DEPARTMENT::ECONOMICS: out << "ECONOMICS"; break;
	case DEPARTMENT::DIRECTOR:  out << "DIRECTOR"; break;
	}
	return out;
}

class TaskPrint
{
	string fname;
	size_t time;
	DEPARTMENT department;

public:
	TaskPrint(string fn, size_t t, DEPARTMENT d) : fname(fn), time(t), department(d) { }

	size_t getTime() { return time; }

	DEPARTMENT getDepartment() { return department; }

	friend ostream& operator<<(ostream& out, const TaskPrint& tp);
};

ostream& operator<<(ostream& out, const TaskPrint& tp)
{
	out << setw(10) << left << tp.department << setw(10) << setw(10) << tp.fname << " " << tp.time << endl;
	return out;
}


class PrintServer
{
	string ip;
	PriorityQueue<TaskPrint, DEPARTMENT> qPrint;
	Queue<TaskPrint> qStats;

	TaskPrint* currentTask = nullptr;
	int leftTime = 0;

	int count = 0;
	int totalTime = 0;

public:
	PrintServer(string ip) : ip(ip)	{ }

	void addTask(TaskPrint tp)
	{
		qPrint.enqueue(tp, tp.getDepartment());
	}

	void work()
	{
		if (qPrint.length() > 0 && currentTask == nullptr)
		{
			currentTask = new TaskPrint(qPrint.peek());
			qPrint.dequeue();
			leftTime = currentTask->getTime();
		}

		system("cls");
		cout << "PrintServer : " << ip << endl;
		cout << "-----------------------------" << endl;
		cout << endl;

		cout << "Current document : left time - " << leftTime << endl;
		if (currentTask)
		{
			cout << *currentTask << endl;
		}
		else
		{
			cout << " " << endl << endl;
		}
		cout << endl;

		cout << "Waiting : " << endl;
		cout << "------------------------------" << endl;
		qPrint.print();

		gotoxy(40, 7);
		cout << "Printed : ";
		gotoxy(40, 8);
		cout << "-----------------------";
		qStats.print(40, 9);

		leftTime--;

		if (leftTime <= 0)
		{
			if (currentTask != nullptr)
			{
				totalTime += currentTask->getTime();
				count++;
				qStats.enqueue(*currentTask);
			}
			currentTask = nullptr;
			leftTime = 0;
		}

		gotoxy(0, 21);
		cout << "----------------------------------------------------------------" << endl;
		cout << "Printed : " << count << " docements, Total time : " << totalTime << " s";
	}
};

