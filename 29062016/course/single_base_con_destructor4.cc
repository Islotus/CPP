 ///
 /// @file    single_base_con_destructor4.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-29 23:37:47
 ///

//单基派生类的构造函数和析构函数

//如果派生类和基类都有构造函数，但基类没有默认的无参构造函数，即基类的构造函数均带有参数，则派生类的每一个构造函数
//必须在其初始化列表中显示的去调用基类的某个代参的构造函数。如果派生类的初始化列表中没有显示调用则会出错，因为基类
//中没有默认的构造函数。

#include <iostream>

using namespace std;

class Baseclass
{
private:
	int a;
public:
#if 0  //就算这里定义了默认构造函数，但是派生类中显示调用了有参构造函数，这里不调用
	Baseclass()
	{
		cout << "default base" << endl;
	}
#endif
	Baseclass(int i)
	{
		cout << "constructing base" << endl;
	}
};

class Derivedclass : public Baseclass
{
public:
	Derivedclass(int i):Baseclass(i)  //自动调用基类的默认构造函数
	{
		cout << "default derived" << endl;
	}

	Derivedclass(int i, int j)
	:Baseclass(j)  //此时显示调用基类的有参构造函数
	{
		cout << "constructing derived" << endl;
	}
};

int main()
{
	Derivedclass x1(5, 7);
	Derivedclass x2(5);

	return 0;
}

