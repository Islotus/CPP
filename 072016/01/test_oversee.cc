 ///
 /// @file    test.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-07-02 22:17:43
 ///

//
#include <iostream>
using namespace std;

class Base
{
public:
	virtual
	int func(int x)
	{
		cout << "Base::func(int)" << endl;
		return x;
	}
};

class Derived
: public Base
{
public:
	virtual
	int func(float x)
	{
		cout << "Derived::func(float)" << endl;
		int y = (int)x;
		return y;
	}
};

int main()
{
	Derived derived;
	derived.func(5);  //子类隐藏父类的func函数

	Base *pbase = &derived;  //知道用派生类中的基类的函数，因为指针时Base类型
	pbase->func(5);

	return 0;
}


