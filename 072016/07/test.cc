 ///
 /// @file    test.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-07-07 21:28:48
 ///

//测试C++虚继承
#include <iostream>

using namespace std;

#if 1  //情形1
class a1
{
	virtual void func();
};

class b1
: virtual public a1
{
	virtual void foo();
};
#endif
#if 1  //情形2
class a2
{
	virtual void func();
};
class b2
: public a2
{
	virtual void foo();
};
#endif
#if 1  //情形3
class a3
{
	virtual void func();
	char x;
};
class b3
: public virtual a3
{
	virtual void foo();
};
#endif
#if 4  //情形4
class a4
{
	virtual void func();
	char x;
};
class b4
: public a4
{
	virtual void foo();
};
#endif

int main()
{
	cout << "情形1：" << endl;
	cout << "sizeof(a1) = " << sizeof(a1) << endl;
	cout << "sizeof(b1) = " << sizeof(b1) << endl;

	cout << "情形2：" << endl;
	cout << "sizeof(a2) = " << sizeof(a2) << endl;
	cout << "sizeof(b2) = " << sizeof(b2) << endl;

	cout << "情形3：" << endl;
	cout << "sizeof(a3) = " << sizeof(a3) << endl;
	cout << "sizeof(b3) = " << sizeof(b3) << endl;

	cout << "情形4：" << endl;
	cout << "sizeof(a4) = " << sizeof(a4) << endl;
	cout << "sizeof(b4) = " << sizeof(b4) << endl;
	return 0;
}

