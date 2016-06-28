 ///
 /// @file    test_RAII.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-28 21:06:58
 ///
 
#include "RAII.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class SomeResource
{
public:
	SomeResource()
	{
		cout << "SomeResource()" << endl;
	}

	~SomeResource()
	{
		cout << "~SomeResource()" << endl;
	}
};

class Example
{
public:
	Example()
	:_p1(new SomeResource())  //有可能发生内存泄露
	,_p2(new SomeResource())
	{
		cout << "Example()" << endl;
	}

	Example(const Example & rhs)
	:_p1(new SomeResource(*rhs._p1)) 
	 //rhs是Example类的一个对象，rhs._p1是Example类对象中的成员变量，也即RAII类的对象，由于RAII类重载了
	 //解引用运算法*，故，*rhs._p1就是资源对象本身
	,_p2(new SomeResource(*rhs._p2))
	{
		cout << "Example(const Example & rhs)" << endl;
	}

	Example & operator =(const Example & rhs)
	{
		if(this == &rhs)
			return *this;
		*_p1 = *rhs._p1;
		*_p2 = *rhs._p2;
		return *this;
	}

	~Example()
	{
		cout << "~Example()" << endl;
//		delete _p1;
//		delete _p2;
	}
private:
	RAII<SomeResource> _p1;
	RAII<SomeResource> _p2;

};
 
int main()
{
	Example em;

	return 0;
}


