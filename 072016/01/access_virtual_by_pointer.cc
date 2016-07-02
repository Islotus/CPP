 ///
 /// @file    access_virtual_by_pointer.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-07-02 22:58:56
 ///

//通过指针访问虚函数
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
	void print()
	{
		cout << "base::print()" << endl;
	}
//	virtual
	void func()
	{
		cout << "base::func()" << endl;
	}
};
 
class child
: public base  //如果这里不写public,默认情况下是private继承
{
public:
	void disp()
	{
		cout << "hello, child" << endl;
	}
	void print()
	{
		cout << "child::print()" << endl;
	}
	virtual
	void func1()
	{
		cout << "child::func1()" << endl;
	}
};

int main()
{
	base obj_base;  //创建一个基类对象
	base *pBase = &obj_base;  //使用基类对象地址为基类指针赋值
	pBase->disp();  //使用基类指针调用虚函数

	child obj_child;  //创建一派生类对象
	child *pChild = &obj_child;  //使用派生类对象地址为派生类指针赋值
	pChild->disp();  //使用派生类指针调用虚函数

	cout << endl;
	pBase = pChild;  //将派生类指针赋值给基类指针
	pBase->disp();  //使用基类指针调用虚函数
#if 0
	pBase->func();
//	pBase->func1();  //error:'class base' has no member named in 'func1'
//	这句话已经证实，pBase = pChild；即基类指针由派生类对象赋值，用指针调用函数时，这个指针能力大小只能是调
//	用基类中的函数，虚函数和非虚函数（因为指针的类型是base基类）。在派生类中有的，而在基类中没有的，不论是不
//	是虚函数，都不能用此类指针调用（平级指针当然可以）。
	pBase->print();
#endif

	cout << endl;
	pChild = (child *)&obj_base;  //反向转换，使用基类对象地址为派生类指针赋值
	pChild->disp();  //使用派生类指针调用虚函数，只取决与赋值对象
	pChild->func();
//	pChild->func1();//能执行，但是会(core dumped).这是不允许的

	pChild->base::disp();  //使用类名加作用域限定符指明要调用的版本，静态联编


}

