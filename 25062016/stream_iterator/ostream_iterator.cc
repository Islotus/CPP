 ///
 /// @file    ostream_iterator.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-25 14:40:30
 ///

//输出流迭代器 ostream_iterator
//输出流迭代器的定义为：
//ostream_iterator<class T1,class T2=char> 迭代器名(ostream_type &ost,const T2 *p=0);
//如：
//ostream_iterator<int> osi(cout,"\n");
//现在osi就是一个输出流迭代器，通过osi可使用cout输出int类型的数据，结束符为换行符

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::ostream_iterator;

int main()
{
	int arr[6] = {1,2,3,4,5,6};
	vector<int> obV(arr, arr+6);
	cout << "ostream_iterator<int,char> osit(cout,\" \"):" << endl;
	ostream_iterator<int,char> osit(cout," ");
	copy(obV.begin(), obV.end(), osit);
	cout << endl;

	cout << "ostream_iterator<int> osit(cout,\" \"):" << endl;
	ostream_iterator<int> osit1(cout," ");
	copy(obV.begin(), obV.end(), osit1);
	cout << endl;

	cout << "ostream_iterator<int> osit(cout,\"\\n\"):" << endl;
	ostream_iterator<int> osit2(cout,"\n");
	copy(obV.begin(), obV.end(), osit2);
	cout << endl;
	return 0;
}

