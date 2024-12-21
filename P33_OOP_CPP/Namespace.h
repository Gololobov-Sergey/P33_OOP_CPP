#pragma once
#include<iostream>

using namespace std;

namespace FOO
{
	void foo()
	{
		cout << "FOO::Foo" << endl;
	}

	namespace DOO
	{
		void foo2()
		{
			cout << "FOO::DOO::foo" << endl;
		}
	}

	
}