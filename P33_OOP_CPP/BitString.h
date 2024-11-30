#pragma once
#include "String.h"
class BitString : public String
{
public:

	BitString() : String() {}

	BitString(const char* st)
	{
		int i = 0;
		bool flag = true;
		while (st[i] != '\0')
		{
			if (st[i] == '0' || st[i] == '1')
			{

			}
			else
			{
				flag = false;
				copy("");
				break;
			}
			i++;
		}
		if(flag)
			copy(st);
	}


};

