 ///
 /// @file    single_base_derived_constructor.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-30 00:02:36
 ///

//派生类构造函数的调用顺序
#include <iostream>

using namespace std;

class A  //类A的定义
{
private:  //private成员列表
	int x;
public:
	A(int xp = 0) //构造函数，带缺省参数
	{
		x = xp;
		cout << "A的构造函数被执行" << endl;
	}
};

class B  //类B定义
{
public:
	B()  //无参构造函数
	{
		cout << "B的构造函数被执行" << endl;
	}
};

class C : public A  //类C由类A派生而来
{
private:
	int y;
	B b;
public:
	C(int xp, int yp)
	:A(xp)  //构造函数，基类构造函数在初始化表中调用
	,b()  //必须加()，表示调用B的无参构造函数，不加括号是错的
	{
		y = yp;
		cout << "C的构造函数被执行" << endl;
	}
};
 
int main()
{
	C c(1, 2);

	return 0;
}


