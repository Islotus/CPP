 ///
 /// @file    common_base_ambiguity.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-29 22:09:35
 ///


//共同基类带来的二义性
//解决方案：
//使用虚基类解决共同基类带来的二义性问题
#include <iostream>

using namespace std;

class A  //公共基类
{
protected:  //protected成员列表
	int x;
public:
	A(int xp = 0)
	{
		x = xp;
	}

	void SetX(int xp)  //设置protected成员x的值
	{
		x = xp;
	}

	void print()
	{
		cout << "this is x in A: " << x << endl;
	}

};

class B : virtual public A
//class B : public A  //类B由类A派生而来
{
};

class C : virtual public A
//class C : public A  //类C由类A派生而来
{
};

class D : public B, public C  //类D由类B和类C派生而来
{
};

int main()
{
#if 0  //共同基类带来的二义性问题
	D d;  //声明一个D类对象exD
	d.SetX(5);  //SetX()具有二义性，系统不知道是调用B类的还是C类的SetX()函数
	d.print();  //print()具有二义性
#endif

#if 1  //共同基类带来的二义性问题的解决方案 ： 虚基类
	D d;  //声明一个D类队象exD

	d.SetX(5);  //SetX函数，因为virtual派生，在D中只有一个版本，不会二义
	d.print();  //print函数，因为virtual派生，在D中只有一个版本，不会二义

	d.A::print();  //还可以用类名显示说明调用函数的版本
	d.B::print();
	d.C::print();
	
#endif

	return 0;
}


