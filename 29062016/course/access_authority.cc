 ///
 /// @file    access_authority.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-29 17:24:54
 ///

//不同继承方式，访问权限的问题

#include <iostream>

using namespace std;

class CA
{
private:
	int x;
protected:
	int y;
public:
	int z;
};

class CB
:private CA  //protected private
{
public:
	void fun()
	{
		z = 7;
		y = 3;
//		x = 4;
		cout << z << endl;
	}
};

int main()
{
	CB b;
//	b.z = 10;
//	b.y = 3;
//	b.x = 4;
	
	return 0;
}

//总结如下：
//1.public继承方式的时候，在子类中不能访问基类的私有成员，可以访问基类的公有成员和保护成员
//	定义的子类对象，不能访问基类的私有成员和保护成员，可以访问基类的公有成员
//2.protected继承方式的时候，在子类中不能访问基类的私有成员，可以访问基类的公有成员和保护成员
//	定义的类对象，不能访问基类中的任何成员
//3.private继承方式的时候，在子类中不能访问基类的私有成员，可以访问基类的公有成员和保护成员
//	定义的子类对象，不能访问基类的任何成员
