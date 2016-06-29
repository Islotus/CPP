 ///
 /// @file    single_base_con_destructor.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-29 22:40:46
 ///

//单基派生类的构造函数和析构函数
//系统会首先通过派生类的构造函数来调用基类的构造函数，完成基类成员的初始化，而后对派生类中新增的成员进行初始化


//如果派生类有显示定义构造函数，而基类没有，则创建派生类的对象时，派生类相应的构造函数会被自动调用，此时都自动
//调用了基类缺省的无参构造函数，如例：

#include <iostream>
using namespace std;

class Baseclass
{
private:
	int a;
public:
	Baseclass()  //用于检测基类的缺省的无参构造函数是否被自动调用
	{
		cout << "default base" << endl;
	}
};

class Derivedclass : public Baseclass
{
public:
	Derivedclass()
	{
		cout << "default" << endl;
	}

	Derivedclass(int i)
	{
		cout << "constructing " << endl;
	}
};

int main()
{
	Derivedclass x1(5);
	Derivedclass x2;

	return 0;
}
 
