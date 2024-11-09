#pragma once
#include<iostream>
#include"Stack.h"

using namespace std;

int priority(char oper)
{
	switch (oper)
	{
	case '+': case '-': return 1;
	case '*': case '/': return 2;
	case '^': return 3;
	}
}

int calc(int a, int b, char op)
{
	switch (op)
	{
	case '+': return a + b;
	case '-': return b - a;
	case '*': return a * b;
	case '/': return b / a;
	case '^': return pow(b, a);
	}
}

class Calc
{
public:
	int operator()(string st)
	{
		Stack<int, 100> number;
		Stack<char, 100> oper;
		int i = 0;
		while (st[i] != '\0')
		{
			if (isdigit(st[i]))
			{
				number.push(st[i] - 48);
			}
			else
			{
				if (oper.isEmpty())
				{
					oper.push(st[i]);
				}
				else
				{
					if (priority(oper.peek()) > priority(st[i]))
					{
						while (priority(oper.peek()) > priority(st[i]))
						{
							int a = number.peek();
							number.pop();
							int b = number.peek();
							number.pop();
							char op = oper.peek();
							oper.pop();
							int res = calc(a, b, op);
							number.push(res);
						}
						oper.push(st[i]);
					}
					else
					{
						oper.push(st[i]);
					}
				}
			}
			i++;
		}

		//reverse stack

		while (!oper.isEmpty())
		{
			int a = number.peek();
			number.pop();

			int b = number.peek();
			number.pop();

			char op = oper.peek();
			oper.pop();

			int res = calc(a, b, op);
			number.push(res);
		}

		return number.peek();
	}
};

