 ///
 /// @file    bind2.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-26 21:14:09
 ///
 
//Example 2---std::bind
#include <iostream>
#include <functional>

void f(int n1, int n2, int n3, const int& n4, int n5)
{
	std::cout << n1 << ' ' << n2 << ' ' << n3 << ' ' << n4 << ' ' << n5 << '\n';
}

int g(int n1)
{
	return n1;
}

struct Foo
{
	void print_sum(int n1, int n2)
	{
		std::cout << n1+n2 << '\n';
	}
	int data = 10;
};

int main()
{
	using namespace std::placeholders;  //for _1, _2, _3, ...

	//demonstrates argument reordering and pass-by-reference
	int n = 7;
	//(_1 and _2 are from std::palceholders, and represent future arguments that will be passed to f1)
	auto f1 = std::bind(f, _2, _1, 42, std::cref(n), n);
	n = 10;
	f1(1, 2, 1001);  //1 is bound by _1, 2 is bound by _2, 1001 is unused

		//bind to a member function
	Foo foo;
	auto f3 = std::bind(&Foo::print_sum, &foo, 95, _1);
	f3(5);

	//bind to member data
	auto f4 = std::bind(&Foo::data, _1);  //_1位置占的是对象的位置，就是把对象绑定到&Foo::data上
	std::cout << f4(foo) << '\n';

	return 0;
}
