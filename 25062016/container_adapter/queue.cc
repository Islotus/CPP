 ///
 /// @file    queue.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-26 10:55:58
 ///

//queue 
//queue有两个指针，一个front(),指向队头，一个back()，指向队尾。
//同样有push(elmetype),pop()

//queue用法示例
#include <iostream>
#include <queue>

using std::cin;
using std::cout;
using std::endl;
using std::queue;

int main()
{
	queue<int> obQ;
	int i = 0;
	for(; i < 10; ++i)
	{
		obQ.push(i);  //把元素一个一个存入到queue中
		cout << obQ.back() << "已入对列" << endl;
	}
	cout << "现在queue的容量：" << obQ.size() << endl << endl;
	cout << "queue是否为空：" << obQ.empty() << endl;
//	cout << "queue是否为满：" << obQ.full() << endl << endl;  //Error,queue没有成员函数full()
	for(i = 0; i< 10; ++i)
	{
		cout << obQ.front() << "准备出队列" << endl;
		obQ.pop();  //把元素一个一个出栈
	}
	cout << "现在queue的容量：" << obQ.size() << endl << endl;
	cout << "queue是否为空：" << obQ.empty() << endl << endl;

	return 0;
}

