 ///
 /// @file    access_virtual_by_obname.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-07-02 22:36:42
 ///

//通过对象名访问虚函数，调用哪个函数取决于对象名的类型
#include <iostream>

using namespace std;

class base
{
public:
	virtual
	void disp()
	{
		cout << "hello, base" << endl;
	}
	virtual
	void func1()
	{
		cout << "base::func1()" << endl;
	}
};

class child
: public base
{
public:
	void disp()
	{
		cout << "hello, child" << endl;
	}
	virtual
	void func2()
	{
		cout << "child::func2()" << endl;
	}
};

int main()
{
	base obj_base;  //创建基类对象obj_base
	child obj_child;  //创建派生类对象obj_child

	obj_base.disp();  //通过对象名调用虚函数
	obj_child.disp();  //通过对象名调用虚函数
	
	cout << endl;
	obj_base.func1();
	obj_child.func2();
	obj_child.func1();

#if 0
	obj_base = obj_child;  //自己：用派生类对象给基类对象赋值时，值调用基类的部分
	obj_base.disp();

	obj_child.base::disp();  //通过类名加作用域限定符指明要调用的版本
	obj_child.child::disp();  //通过类名加作用域限定符指明要调用的版本
#endif

	return 0;
}
 
