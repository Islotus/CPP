 ///
 /// @file    associative_container_insert.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-23 19:57:26
 ///

//关联式容器 元素的插入 associative container
//一下insert函数中，ob代表关联式容器对象名，t对set和multiset来说是个关键字，而对map和multimap来说，是个pair结构
//>1.pair<iterator,bool> ob.insert(t)
//适用于map和set容器。返回一个pair<iterator,bool>值。当ob中不包含t时，将t插入ob中，bool为true;否则不进行插入，
//bool为false。无论是否进行了插入操作，iterator都指向关键字和t相同的元素
//>2.iterator ob.insert(t)
//适用于multiset和multimap,将t插入到ob中，并返回指向t所在位置的迭代器

//insert函数的使用1,2
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
	//insert()用法  map
	//创建一个pair<int,string>数组arr
	pair<int,string> arr[2] = {pair<int,string>(1, "A"), pair<int,string>(1, "B")};  //map关键字唯一
	pair<int,string> t(2, "B");  //待插入的pair对象
	map<int,string> obM(arr, arr+2);  //基于arr创建map对象obM
	map<int,string>::iterator itM = obM.begin();  //创建map<int,string>类内迭代器itM
	
	cout << "大小为：" << obM.size() << endl;

	cout << "插入前容器中的元素为" << endl;
	while(itM != obM.end())
	{
		cout << (*itM).first << " : " << (*itM).second << endl;
		++itM;
	}
	
	cout << (*itM).first << endl;

	itM = obM.begin();  //容器中没有相同的关键字时，从后面插入
	pair<map<int,string>::iterator,bool> res = obM.insert(t);  //将t插入obM中，返回结果保存在对象res中
			//其类型为pair<map<int,string>::iterator,bool>
	if(res.second)  //判断是否插入成功
		cout << "插入成功" << endl;
	else
		cout << "map中已包含关键字与t相同的元素" << (*res.first).first << " " << (*res.first).second << endl;

	cout << "插入后容器中的元素为" << endl;
	itM = obM.begin();
	while(itM != obM.end())
	{
		cout << (*itM).first << " : " << (*itM).second << endl;
		++itM;
	}
	
	//insert()用法
	//基于arr创建multimap对象obMM
	multimap<int,string> obMM(arr, arr+2);
	multimap<int,string>::iterator itMM = obMM.begin();  //创建multimap<int,string>类内迭代器itMM
#if 1	
	cout << "插入前容器中的元素为" << endl;
	while(itMM != obMM.end())
	{
		cout << (*itMM).first << " : " << (*itMM).second << endl;
		++itMM;
	}
#endif
	itMM = obMM.begin();
	itMM = obMM.insert(t);  //执行插入操作  //先检查前面有没有相同关键字的元素，没有的话，从后面插入
	cout << "向multimap插入的元素为：" << (*itMM).first << " " << (*itMM).second << endl;

	cout << "插入后容器中的元素为" << endl;
	itMM = obMM.begin();
	while(itMM != obMM.end())
	{
		cout << (*itMM).first << " : " << (*itMM).second << endl;
		++itMM;
	}


	t = pair<int,string>(1, "C");  //待插入的pair对象
	
	itMM = obMM.begin();
	itMM = obMM.insert(t);  //执行插入操作  //先检查前面有没有相同关键字的元素，有的话，就插入相同关键字的链表中
	cout << "向multimap插入的元素为：" << (*itMM).first << " " << (*itMM).second << endl;

	cout << "插入后容器中的元素为" << endl;
	itMM = obMM.begin();
	while(itMM != obMM.end())
	{
		cout << (*itMM).first << " : " << (*itMM).second << endl;
		++itMM;
	}


	return 0;
}
