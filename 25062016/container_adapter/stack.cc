 ///
 /// @file    stack.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-25 23:18:38
 ///

//容器适配器 container adapter
//容器适配器可以看做是对容器的封装，使其具有某些特殊的功能。容器适配器让一种已存在的容器类型采用另一种不同的
//抽象类型的工作方式实现，只是发生了接口转换而已。
//标准库提供了三种序列式容器适配器：
//stack(deque,list)  queue(deque,list)  priority_queue(vector,deque)
//所有适配器都定义了两个构造函数：默认构造函数用于创建空对象，而带一个容器参数的构造函数将参数容器的副本作为
//其基础值。
//默认的stack和queue都基于deque容器实现，而priority_queue则在vector容器上是实现。在创建适配器时，通过将一个顺序容器
//指定为适配器的第二个类型参数，可以覆盖其关联的基础容器类型。

//stack用法实现
#include <iostream>
#include <stack>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::stack;
using std::string;

int main()
{
	stack<int,vector<int> > obS;  //使用vector取代其默认的deque作为stack的实现基础
	for(int i = 1; i <= 20; ++i)
	{
		obS.push(i);
	}
#if 1
	while(obS.size() > 0)
	{
		int x = obS.top();
		cout << x << " ";
		obS.pop();
	}
	cout << endl;
#endif
#if 0
	while(obS.size() > 0)
	{
//		int x = obS.top();
//		cout << x << " ";
//	cout<< obS.pop();  //Error,std::stack::pop返回值为void,
	}
	cout << endl;
#endif


	cout << endl;
	stack<string,vector<string> > obSs;  //不能写成stack<string,vector<string>> obS;
	for(char c = 'A'; c <= 'Z'; ++c)
	{
		string s(2,c);  //创建string类对象s，大小2字符,存放两个字符c
		obSs.push(s);
//		cout <<s << " ";
	}

	while(obSs.size() > 0)
	{
		string s = obSs.top();
		cout << s << " ";
		obSs.pop();
	}
	cout << endl;

	return 0;
}

