 ///
 /// @file    mem_fn.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-26 23:40:52
 ///

//成员函数适配器，也是两个：
//>mem_fun();  //容器参数为类指针
//>mem_fun_ref();  //容器参数为类对象
//>mem_fn()  //两者都能用（c++11）

//mem_fn用法示例
#include <iostream>
#include <functional>

using std::cin;
using std::cout;
using std::endl;
using std::mem_fn;

struct Foo
{
	void display_greeting()
	{
		cout << "Hello,world.\n";
	}
	void display_number(int i)
	{
		cout << "number: " << i << '\n';
	}
	int data = 7;
};

int main()
{
	Foo f;

	auto greet = mem_fn(&Foo::display_greeting);
	greet(f);

	auto print_num = mem_fn(&Foo::display_number);
	print_num(f, 42);

	auto access_data = mem_fn(&Foo::data);
	cout << "data: " << access_data(f) << '\n';

	return 0;
}
 
