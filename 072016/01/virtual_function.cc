 ///
 /// @file    virtual_function.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-07-01 21:00:47
 ///

//Example1:
#include <iostream>

using namespace std;

#if 0
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
		float y = x*1.0;
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

#endif



#if 1
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
//此处虚函数和基类的虚函数不是完全相同，既不构成覆盖，又不构成重载，但是可以编译成功。
//C++认为派生类中的虚函数是重定义函数，是隐藏的，失去了虚特性。在调用的过程中始终调用的是
//基类的虚函数。
	virtual
	int func(float x)
	{
		cout << "int Derived::func(float)" << endl;
		int y = (int)x;
		return y;
	}
};

void test(Base &x)
{
	cout << "x = " << x.func(5) << endl;
}

int main()
{
	Base bc;
	Derived de;
	test(bc);
	test(de);

	de.func(5);  
	Base &refbase = de;
	refbase.func(5);

	return 0;
}
//讲解：对于派生类而言，基类的虚函数被派生类的虚函数隐藏了。
如果用派生类的对象直接去调用则只存在派生类的虚函数。对于通过多态（基类指针或引用指向派生类之后）去调用虚函数，
则始终调用的基类的虚函数，此时派生类的虚函数被隐藏了。也就是说：相对基类而言，派生类的虚函数被隐藏，相对派生类
而言，基类的虚函数被隐藏。只跟调用的对象有关，跟指向的内容无关。

自己总结：
用多态时，利用指针只能访问派生类对象中的基类的部分。利用派生类的对象时，要考虑隐藏和重定义的函数。

#endif



