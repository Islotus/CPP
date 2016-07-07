 ///
 /// @file    sizeof_class2.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-07-07 22:57:06
 ///

//
#include <iostream>
 
using namespace std;

class A
{
	int i;
	void f();
	virtual void run() {}
	virtual void run1() {}
	virtual void run2() {}
};
class B
: virtual public A
{
	virtual void run() {}
	virtual void run1() {}
	virtual void run3() {}
};

int main()
{
	cout << "sizeof(A) = " << sizeof(A) << endl;
	cout << "sizeof(B) = " << sizeof(B) << endl;

	return 0;
}
