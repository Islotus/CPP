 ///
 /// @file    priority_queue.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-26 11:22:43
 ///

//priority_queue队列
//部分成员函数：
//Element access: top
//Modifiers: push,pop,swap,emplace

//priority_queu用法示例
#include <iostream>
#include <queue>
#include <deque>

using std::cin;
using std::cout;
using std::endl;
using std::priority_queue;
using std::deque;

//priority_queue允许对存储的元素设置优先级。
//优先级队列的一个实例是机场行李检查队列。30分钟后即将离港的航班的乘客通常会设置高的优先级别。
//优先队列的例子如下：

int main()
{
	int i = 0;
	int arr[10] = {0, 1, 3, 2, 5, 6, 9, 8, 7, 4};
	priority_queue<int> obRQ;
//	priority_queue<int,deque<int>,greater<int> > obRQ;	
	for(i = 0; i < 10; ++i)
	{
		obRQ.push(arr[i]);  //把元素一个一个存入到priority_queue中，并且在内部进行排序
		cout << obRQ.top() << "是目前这个队列中优先级别最高的" << endl;
	}
	cout << "现在priority_queue的容量：" << obRQ.size() << endl << endl;

	for(i = 0; i < 10; ++i)
	{
		cout << obRQ.top() << "准备出队列" << endl;
		obRQ.pop();  //把元素一个一个出栈
	}
	cout << "现在priority_queue的容量：" << obRQ.size() << endl;

	return 0;
}

//优先队列是队列的一种，不过它可以按照自定义的一种方式（数据的优先级）来对对队列中的数据进行动态的排序
//每次的push和pop操作，队列都会动态的调整，已达到我们预期的方式来存储。
//例如：我们常用的操作就是对数据排序，优先队列默认的是数据大的优先级高
//所以我们无论按照什么顺序push一堆数，最终在队列里总是top出最大的元素。
//用法：
//示例：将元素5,3,2,4,6一次push到优先队列中，print其输出。
//1.标准库默认使用元素类型的<操作符来确定它们之间的优先级关系。
//priority_queue<int> pq;
//通过 < 操作符可知在整数中元素大的优先级高，故示例1中输出结果为:6 5 4 3 2
//
//2.数据越小，优先级越高
//priority_queue<int,vector<int>,greater<int> > pq;
//其中
//第二个参数为容器类型，默认为deque
//第三个参数为比较函数
//故示例2中输出结果为：2 3 4 5 6
//
//3.自定义优先级，重载比较符号
//重载默认的 < 符号
//struct node
//{
//	friend bool operator <(node n1, node n2)
//	{
//		return n1.priority < n2.priority;
//	}
//	int priority;
//	int value;
//};
//这是，需要为每个元素自定义一个优先级。
//
//注：
//重载 > 号会编译出错，因为标准库默认使用元素类型的 < 操作符来确定它们之间的优先级关系。
//而且自定义类型的 < 操作符与 > 操作符并无直接关系

