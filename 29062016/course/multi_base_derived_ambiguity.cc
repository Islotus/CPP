 ///
 /// @file    multi_base_derived_ambiguity.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-29 20:43:07
 ///

//多基类继承时的二义性问题
//以及解决方案
#include <iostream>

using namespace std;

class A  //类A的定义
{
public:
	void print()  //类B中同样定义了print函数
	{
		cout << "Hello, this is A" << endl;
	}
};

class B  //类B的定义
{
public:
	void print()  //类B中同样定义了print函数
	{
		cout << "Hello, this is B" << endl;
	}
};

class C
:public A
,public B  //类C由类A和类B共同派生而来
{
public:
	void disp()
	{
		A::print();  //编译器无法决定采用A类中定义的版本还是B类中的版本
			//1.指明采用A类中定义的版本
	}

	//重载print函数，根据条件调用不同基类的print函数
	void print()
	{
		if(true)
			A::print();
		else
			B::print();
	}

};

//最好在类C中也定义一个同名print函数，根据需要调用A::print()还是B::print(),从而实现对基类同名函数的隐藏。

int main()
{
#if 0  //问题
	C c;
	c.disp();  //派生类内访问对象成员的二义性
	c.print();  //外部通过派生类对象访问基类成员的二义性
#endif

#if 1  //多基类继承时的二义性问题解决方案
	C c;
	c.disp();

	c.A::print();
	c.print();


#endif

	return 0;
}

