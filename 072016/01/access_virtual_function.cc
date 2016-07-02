 ///
 /// @file    access_virtual_function.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-07-02 21:48:29
 ///

//虚函数的访问
#include <iostream>

using namespace std;

class base  //基类定义
{
public:
	virtual
	void disp()  //虚函数
	{
		cout << "hello, base" << endl;
	}
};

class child
: public base  //派生类定义
{
public:
	void disp()  //虚函数的覆盖（对普通函数来说，是隐藏）
	{
		cout << "hello, child" << endl;
	}
};

int main()
{
	return 0;
}

//如果父类没有virtual关键字，则此时对于子类对象而言，基类的disp是被子类的disp函数隐藏的，即使基类此时的
//disp函数带有参数，也不能直接用子类对象去访问父类的disp函数。此时必须使用子类对象.基类名::disp的形式访问。


