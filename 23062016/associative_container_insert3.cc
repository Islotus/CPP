 ///
 /// @file    associative_container_insert3.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-23 22:35:47
 ///

//关联式容器 associative container
//元素的插入
//void insert(i,j)
//i,j是一对输入迭代器，此函数用于将[i,j)区间的元素插入到ob中。

#include <iostream>
#include <map>
#include <string>
#include <utility>

using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::multimap;
using std::string;
using std::pair;

int main()
{
	pair<int,string> arr[4] = {
		pair<int,string>(7, "G"), pair<int,string>(3, "C"),
		pair<int,string>(5, "E"), pair<int,string>(1, "A")
	};  //创建一个pair<int,string>数组arr

	pair<int,string> t[4] = {
		pair<int,string>(2, "B"), pair<int,string>(4, "D"),
		pair<int,string>(6, "F"), pair<int,string>(1, "X")
	};  //创建一个pair<int,string>数组t

	cout << "下面是对map的插入操作：" << endl;
	map<int,string> obM(arr, arr+4);  //基于arr创建map对象obM

	cout << "插入前：" << endl;
	for(map<int,string>::iterator itM = obM.begin(); itM != obM.end(); ++itM)
	{
		cout << (*itM).first << " " << (*itM).second << endl;
	}

	obM.insert(t, t+4);  //执行插入操作

	cout << "插入后：" << endl;
	for(map<int,string>::iterator itM = obM.begin(); itM != obM.end(); ++itM)
	{
		cout << (*itM).first << " " << (*itM).second << endl;
	}

	cout << endl << "下面是对multimap的插入操作：" << endl;
	multimap<int,string> obMM(arr, arr+4);  //基于arr创建multimap对象obMM

	cout << "插入前：" << endl;
	for(multimap<int,string>::iterator itMM = obMM.begin(); itMM != obMM.end(); ++itMM)
	{
		cout << (*itMM).first << " " << (*itMM).second << endl;
	}

	obMM.insert(t, t+4);  //执行插入操作

	cout << "插入后：" << endl;
	for(multimap<int,string>::iterator itMM = obMM.begin(); itMM != obMM.end(); ++itMM)
	{
		cout << (*itMM).first << " " << (*itMM).second << endl;
	}

	return 0;
}
 
