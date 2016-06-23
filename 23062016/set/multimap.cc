 ///
 /// @file    multimap.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-23 17:15:37
 ///

//multimap与map的关系，类似于multiset与set的关系，使用multimap同样要包含同文件<map>
//multimap的创建方式与map相同，有3种方式。
//multimap与map的不同之处在于其允许出现相同的元素。此时不支持[]随机操作

//multimap容器的使用：关键字允许重复，按照关键字排序
#include <iostream>
#include <map>
#include <utility>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::multimap;
using std::pair;
using std::string;

#define pairtype pair<int,string>

int main()
{
	//pair<int, string>模板类的用法
	pairtype t(9, "Asia");
	cout << t.first << " " << t.second << endl;

	//创建pair<int,string>型数组
	pairtype arr[4] = {
		pairtype (9, "Asia"), pairtype (4, "Africa"), pairtype (1, "Euro"), pairtype (4, "America")};
	multimap<int,string> obMM(arr, arr+4);  //用迭代器区间构造obMM
	cout << obMM.size() << endl;  //输出obMM中的元素个数

	multimap<int,string>::iterator it = obMM.begin();
	while(it != obMM.end())
	{
		cout << (*it).first << " : " << (*it).second << endl;
		++it;
	}
	
	cout << "用auto关键字进行输出，c++11版本" << endl;
	for(auto &mem : obMM)  //要加上-std=c++11，也即g++ multimap.cc -std=c++11
		cout << mem.first << " : " << mem.second << endl; 

	return 0;
}
 
