 ///
 /// @file    single_base_con_destructor2.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-29 22:50:30
 ///

//单基派生类的构造函数和析构函数

//如果派生类没有显示定义构造函数而基类有，则基类必须拥有默认构造函数。
#include <iostream>

using namespace std;

class Baseclass
{
private:
	int a;
public:
#if 1
	Baseclass()  //必须有
	{
		cout << "default base" << endl;
	}
#endif

	Baseclass(int i) //此时有参的构造函数没有任何作用
	{
		cout << "constructing base" << endl;
	}
};

class Derivedclass : public Baseclass
{
};

int main()
{
	Derivedclass x1;

	return 0;
}
 
