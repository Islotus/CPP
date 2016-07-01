 ///
 /// @file    virtual_function.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-07-01 21:00:47
 ///

//Example1:
#include <iostream>

using namespace std;

class Base
{
public:
	virtual
	int func(int x)
	{	
	   cout << "int Base::func(int)" << endl;
	   return x;
	}
};

class Derived
: public Base
{
public:
#if 1
	virtual
	float func(int x)
	{
		cout << "float Derived::func(int)" << endl;
		float y = (float)x;
		return y;
	}
#endif
};

void test(Base &x)
{
	cout << "x = " << x.func(5) << endl;
}


int main()
{
	Base base;
	Derived derived;
	test(base);
	test(derived);

	return 0;
}

