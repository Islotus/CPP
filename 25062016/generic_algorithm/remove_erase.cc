 ///
 /// @file    remove_erase.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-25 17:24:33
 ///

//remove_erase用法示例
#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

void disp(vector<int>::value_type v)
{
	cout << v << " ";
}

int main()
{
	vector<int> obV;
	obV.reserve(10);  //预先开10个空间
	cout << obV.size() << endl;
	cout << obV.capacity() << endl;
	for(int i = 1; i<= 10; ++i)
	{
		obV.push_back(i);
	}
	obV[3] = obV[5] = obV[9] = 99;
	cout << "添加并修改完数据后：" << "obV.size()" << obV.size() << endl;
	//用迭代器输出元素
	for(vector<int>::iterator itV = obV.begin(); itV != obV.end(); ++itV)
	{
		cout << *itV << " ";
	}
	cout << endl;

//	remove(obV.begin(), obV.end(), 99);
	obV.erase(remove(obV.begin(), obV.end(), 99),obV.end());
	cout << "remove完数据后：" << "obV.size()" << obV.size() << endl;

	//用关键字auto输出元素
	for(auto it : obV)  //c++11之后才有的，故g++ remove_erase.cc -std=c++11
	{
		cout << it << " ";
	}
	cout << endl;
#if 1
	//用for_each()输出元素
	for_each(obV.begin(), obV.end(), disp);
	cout << endl;

#endif
	
}
 
