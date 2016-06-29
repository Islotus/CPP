 ///
 /// @file    single_base_derived_destructor.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-30 00:16:04
 ///

//单基派生类的析构函数

//派生类的析构函数
#include <iostream>

using namespace std;

class A
{
private:
	int x;
public:
	A(int xp = 0)
	{
		x = xp;
		cout << "A的构造函数被执行" << endl;
	}
	~A()
	{
		cout << "A的析构函数被执行" << endl;
	}
};

class B : public A
{
public:
	B()
	{
		cout << "B的构造函数被执行" << endl;
	}
	~B()
	{
		cout << "B的析构函数被执行" << endl;
	}
};

class C : public A  //类C由类A派生而来
{
private:
	int y;
	B b;  //对象成员
public:
	C(int xp, int yp)  //派生类的构造函数，基类和对象成员都在初始化列表中完成初始化
	:A(xp)
	,b()
	{
		y = yp;
		cout << "C的构造函数被执行" << endl;
	}
	~C()
	{
		cout << "C的析构函数被执行" << endl;
	}
};

 
int main()
{
	C c(1, 2);  //声明一个C类对象c

	return 0;  //main函数执行完毕，c撤销，析构函数触发执行
}

