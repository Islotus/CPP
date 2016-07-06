 ///
 /// @file    access_virtual_pointer.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-07-06 11:10:00
 ///

//通过指针访问虚函数
#include <iostream>

using namespace std;

class base
{
public:
	virtual void disp()
	{
		cout << "hello, base" << endl;
	}
	virtual void test()
	{
		cout << "base::test()" << endl;
	}
};

class derived
: public base
{
public:
	void disp()
	{
		cout << "hello, derived " << endl;
	}
#if 1
	void test()
	{
		cout << "derived::test()" << endl;
	}
#endif
};

int main()
{
	base obj_base;  //创建一个基类对象
	base *pBase = &obj_base;  //使用基类对象为基类指针赋值
	pBase->disp();  //使用基类指针调用虚函数

	cout << endl;
	derived obj_derived;  //创建一个派生类对象
	derived *pDerived = &obj_derived;  //使用派生类对象地址为派生类指针赋值
	pDerived->disp();  //使用派生类指针调用虚函数

	cout << endl;
	pBase = pDerived;  //将派生类指针赋值给基类指针
	pBase->disp();  //调用基类指针调用虚函数
//	pBase->test();  //error:calss base has no member named test;这说明，基类指针只能调用基类里面的函数。
//	用派生类对象给基类指针赋值，严格上来说是派生类创建基类，基类中同名函数被派生类函数覆盖了。

	cout << endl;
	pDerived = (derived*)&obj_base;  //反向转换，使用基类对象地址为派生类指针赋值
	//用基类对象为派生类指针赋值，就是用基类对象创建派生类对象，这样派生类中同名函数被基类中同名函数覆盖，
	//基类指针只能调用基类中的函数。（这样用会产生潜在风险，因为派生类对象一般比基类对象占用更多的空间
	//最好不要这样用）
	pDerived->disp();  //使用派生类指针调用虚函数，只取决于赋值对象
	pDerived->test();

	return 0;
}
 
