 ///
 /// @file    derived_to_base_override.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-30 08:56:26
 ///

//派生类对基类成员的覆盖

#include <iostream>

using namespace std;

class CBase
{
protected:
	int m_i;
public:
	int Func(int i)
	{
		return m_i;
	}
};

class CDerived
:public CBase
{
public:
	int m_i;  //隐藏基类的m_i
	int Func()  //覆盖基类的Func
	{
		m_i = 9;  //访问自身的成员
		CBase::m_i = 22;  //通过作用域解析符访问基类的成员
		return m_i;
	}
};

int main()
{
#if 0  //调用CBase类的默认构造函数，没有初始化m_i，里面放的是不定值
	CDerived obj;
	cout << obj.CBase::Func(3) << endl;
#endif

	CDerived obj;  //
	obj.Func();  //如果没有这一句的话，就无法给m_i赋值，其是不定值
	cout << "obj.CBase::Func(int)" << obj.CBase::Func(1) << endl;
	cout << "obj.CDerived::m_i" << obj.CDerived::m_i << endl;
	//obj.Func(3);  //错误！基类的Func被覆盖
	obj.CBase::Func(3);  //正确，通过作用域解析符访问基类的成员
	cout << "obj.CBase::Func(int)" << obj.CBase::Func(2) << endl;
	cout << "obj.CDerived::m_i" << obj.CDerived::m_i << endl;

	return 0;
}
 
