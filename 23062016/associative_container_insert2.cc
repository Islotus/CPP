 ///
 /// @file    associative_container_insert2.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-23 22:31:54
 ///

//关联式容器 associative container
//元素的插入
//iterator ob.insert(p,t) 
//从迭代器p开始搜素应将t插入到ob中的位置。适用于4个关联式容器。
//对于set/map，只有当ob中不包含t时才进行插入。无论是否插入，都返回一个指向t关键字的iterator
//对于multiset/multimap，将t插入到ob中，返回指向t的iterator；p的作用是加快查找速度

//insert函数格式的示例代码iterator ob.insert(p, t)

#include <iostream>
#include <map>
#include <utility>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::multimap;
using std::pair;
using std::string;

int main()
{
	pair<int,string> arr[4] = {
		pair<int,string>(7, "G"),
		pair<int,string>(3, "C"),
		pair<int,string>(5, "E"),
		pair<int,string>(1, "A")
	};  //创建一个pair<int,string>数组arr
	pair<int,string> t(1, "X");

	//1.希望将t(1, "X")插入map中
	cout << "希望将(1,X)插入map中，结果：" << endl;
	map<int,string> obM(arr, arr+4);  //基于arr创建map对象obM
	map<int,string>::iterator p = obM.begin();
	++p;
	map<int,string>::iterator res = obM.insert(p, t);

	for(map<int,string>::iterator itM = obM.begin(); itM != obM.end(); ++itM)
	{
		cout << (*itM).first << " " << (*itM).second << endl;
	}
	cout << "返回：" << (*res).first << " " << (*res).second << endl;

	//2.希望将t(1,X)插入multimap中
	cout << endl << "希望将(1, \"X\")插入multimap中，结果：" << endl;
	multimap<int,string> obMM(arr, arr+4);
	multimap<int,string>::iterator p1 = obMM.begin();
	++p1;
	++p1;
	multimap<int,string>::iterator res1 = obMM.insert(p1, t);
	
	for(multimap<int,string>::iterator itMM = obMM.begin(); itMM != obMM.end(); ++itMM)
	{
		cout << (*itMM).first << " " << (*itMM).second << endl;
	}
	cout << "返回：" << (*res1).first << " " << (*res1).second << endl;

	return 0;
}
 
