 ///
 /// @file    access_virtual_de_constructor.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-07-03 15:54:09
 ///

//构造函数或析构函数是特殊的成员函数，在其中访问虚函数时，C++采用静态联编
#include <iostream>

using namespace std;

class Base0
{
public:
	Base0()
	{
	}
	virtual
	void func1()
	{
		cout << "this is base0 func1()" << endl;
	}
	virtual
	void func2()
	{
		cout << "this is base0 func2()" << endl;
	}
	~Base0()
	{
	}
};

class Base1
: public Base0
{
public:
	Base1()
	{
		func1();
	}
//	virtual void func1()  //没有重写覆盖该虚函数，则调用父类Base0中的func1()方法
//	{
//		cout << "this is base0 func1()" << endl;
//	}
	
	virtual
	void func2()
	{
		cout << "this is base1 func2()" << endl;
	}
	~Base1()
	{
		func2();
	}
};
 
class Subclass
: public Base1
{
public:
#if 0
	Subclass()
	{
		func1();
	}
#endif

	virtual
	void func1()  //始终不会被调用
	{
		cout << "this is subclass func1()" << endl;
	}
	virtual
	void func2()
	{
		cout << "this is subclass func2()" << endl;
	}
	~Subclass()
	{
	}
};


int main()
{
	Subclass sc;
}
#if 1
结果为：this is base0 func1()
this is base1 func2()
//上面程序的分析：
继承方式为：Subclass ---（继承）--- Base1 ---（继承）---Base0
（其中，Base0中有两个虚函数，func1(),func2();Base1中只重写覆盖了父类Base0的func2(),其构造函数调用func()方法，
类Subclass中重写覆盖了func1()和func2()方法。）
当实例化子类对象Subclass的sc时，调用默认构造函数，先调用父类Base1的构造函数，而该构造函数中调用了func1()方法，
因为在其自身的类中没有重写覆盖func1()方法，则当调用父类Base0()的func1()方法，输出this is base0 func1().
当程序结束，对象sc要被释放时，调用默认的析构函数~Subclass()，自动调用父类Base1的析构函数，该析构函数中调用func2()
方法，而Base1中重写覆盖了func2()方法，所以调用自己类中的func2()方法，输出this is base1 func2().

#endif
