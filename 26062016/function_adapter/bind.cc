 ///
 /// @file    bind.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-26 20:45:25
 ///

//函数适配器共有如下3种：
//1.绑定器，有两个：
//bind1st(函数对象，指定值);  //将指定值绑定到函数对象的第1个参数上
//bind2nd(函数对象，指定值);  //将制定值绑定到函数对象的第2个参数上
//bind(函数对象，指定值...C++11)  //绑定的参数的个数不受限制；对于不事先绑定的参数，需要传std::palceholders
//进去，从_1开始，一次递增  //也就是说，如果事先不绑定，就让std::palceholders::_1,._2先占着位置，等传参数
//时再补上

//Example 1---std::bind
#include <iostream>
#include <functional>

int Func(int x, int y)
{}
auto bf1 = std::bind(Func, 10, std::placeholders::_1);
//bf1(20);  //> same as Func(10,20)

class A
{
public:
	int Func(int x, int y)
	{}
};

int main()
{
	A a;
	auto bf2 = std::bind(&A::Func, a, std::placeholders::_1, std::placeholders::_2);  //类中的成员函数，要特别注意
	bf2(10, 20);  //>same as a.Func(10, 20)

	auto bf3 = std::bind(&A::Func, a, std::placeholders::_1, 100);
	bf3(10);  //>same as a.Func(10, 100) 
}
 
