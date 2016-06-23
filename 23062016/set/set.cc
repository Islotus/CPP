 ///
 /// @file    set.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-23 15:00:40
 ///

//关联式容器 associative container
//set容器
//使用形式如下：
//set<存储类型[,排序函数或对象]> 容器对象名
//STL提供了3种创建set的方法
//>创建空set容器对象，如set<int> obS;
//>将迭代器的区间作为参数的构造函数，如
//int sz[9]={1,2,3,4,5,6,3,5,6}; set<int> A(sz, sz+9)
//>根据已有同类型的容器创建新容器，如 set<int> B(A);
//set不支持[]下标式的随机访问，必须通过迭代器访问元素

//set容器的使用：关键字不允许重复，按照关键字排序
#include <iostream>
#include <set>

using std::cin;
using std::cout;
using std::endl;
using std::set;

int main()
{
	int arr[9] = {2, 1, 3, 5, 4, 6, 3, 5, 6};  //定义int型数组，数组名相当于指针（迭代器）
	set<int> setI(arr, arr+9);  //将迭代器区间作为参数创建容器对象A
	cout << setI.size() << endl;  //输出A中元素个数

	set<int>::iterator it = setI.begin();  //创建set<int>::iterator迭代器it，指向A头部
	while(it != setI.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	for(auto &mem : setI)  //g++ set.cc -std=c++11,11版本之后才有的
		cout << mem << " ";
	cout << endl;

	return 0;
}

