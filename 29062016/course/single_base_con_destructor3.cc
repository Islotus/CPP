 ///
 /// @file    single_base_con_destructor3.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-29 23:05:12
 ///

//单基派生类的构造函数和析构函数

//如果派生类有构造函数，基类有默认构造函数，则创建派生类的对象时，基类的默认构造函数会自动调用，如果想调用
//基类的有参构造函数，必须在派生类构造函数的初始化列表中显示调用基类的有参构造函数。

//也就是说，在派生类中如果不显示调用基类的有参构造函数，派生类的构造函数会自动调用基类的默认构造函数。
//如果想调用基类的有参构造函数，必须在派生类的构造函数中显示调用。
//基类中如果存在有参构造函数，那么必须显示提供默认构造函数，因为有参构造函数会屏蔽默认构造函数
#include <iostream>

using namespace std;

class Baseclass
{
private:
	int a;
public:
#if 1
	Baseclass()  //用于检测基类的是否被自动调用
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
	Derivedclass(int i)  //自动调用基类的默构造函数
	{
		cout << "default derived " << endl;
	}

	Derivedclass(int i, int j)
//	:Baseclass(j)  //此时显示调用基类有参构造函数
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


 
