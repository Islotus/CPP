 ///
 /// @file    access_virtual_func.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-07-03 14:22:43
 ///

//在类内的成员函数中访问该类层次中的虚函数，要使用this指针
#include <iostream>

using namespace std;

class base  //基类定义
{
public:
	virtual
	void disp()  //虚函数disp
	{
		cout << "hello, base" << endl;
	}

	void call_base_1()
	{
		this->disp();  //或直接用disp()
	}

	void call_base_2()
	{
		base::disp();  //去掉base::再试试
	}
};

class child
: public base  //派生类定义
{
public:
	void disp()  //对虚函数进行了覆盖定义
	{
		cout << "hello, child" << endl;
	}

	void call_child_1()
	{
		disp();  //等价于this->disp();
	}

//	函数call_base_1()在child类中虽然没有直接写出来，
//	但还是继承过来了，默认和base类的代码是一样的
//	void call_base_1()
//	{
//		this->disp();
//	}
//
//	函数call_base_2()在child类中虽然没有直接写出来，
//	但还是继承过来了，默认和base类的代码是一样的
//	void call_base_2()
//	{
//		base::disp();
//	}
};


int main()
{
	base obj_Base;  //调用一个基类对象
	child obj_Child;  //声明一个派生类对象
	obj_Base.call_base_1();  //基类对象调用非虚函数call_base_1()
	obj_Child.call_child_1();  //派生类对象调用非虚函数call_child_1()
	obj_Base.call_base_2();  

	cout << endl;

	base *pBase = & obj_Base;  //声明一基类指针，并用基类对象地址为其初始化
	pBase->call_base_1();  //使用基类指针在成员函数中调用虚函数
	pBase->call_base_2();

	cout << endl;

	pBase = &obj_Child;  //用派生类对象地址为基类指针初始化
	pBase->call_base_1();  //使用基类指针在成员函数内调用虚函数
		//这里形成了覆盖，派生类的disp()函数隐藏了父类的disp()当用pBase指针访问时，正真调用的是
		//派生类中的函数，指针仍然是基类的。只是有派生类中基类的部分创建了一个基类。
	pBase->call_base_2();

	return 0;
}
 
