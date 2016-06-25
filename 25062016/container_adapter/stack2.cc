 ///
 /// @file    stack2.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-25 23:57:51
 ///

//stack用法示例2

#include <iostream>
#include <stack>

using std::cin;
using std::cout;
using std::endl;
using std::stack;

int main()
{
	int i = 0;
	stack<int> obS;  //默认使用deque实现，这里的类型为int
	for(i = 0; i < 10; ++i)
	{
		obS.push(i);  //把元素一个一个存入到stack中
		cout << obS.top() << "已入栈" << endl;
	}

	cout << "现在stack的容量：" << obS.size() << endl << endl;
	for(i = 0; i < 10; ++i)
	{
		cout << obS.top() << "准备出栈" << endl;
		obS.pop();  //把元素一个一个出栈
	}

	cout << "现在stack的容量：" << obS.size() << endl << endl;

//	for_each()不能在此使用，因为for_each()要知道头迭代器的位置，而stack没有
#if 0
	cout << "for(auto s : obS): " << endl;  //Error,我认为，是因为找不到stack的起始位置，无法进行迭代
	for(auto s : obS)                       //故，stack不能用for_each()和auto关键字访问其内的元素
		cout << s << " ";
	cout << endl;
#endif
	return 0;
}


