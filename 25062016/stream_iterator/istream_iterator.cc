 ///
 /// @file    istream_iterator.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-25 15:07:20
 ///

//输出流迭代器 istream_iterator
//输出流迭代器的定义为:
//istream_iterator<class T1,class T2=char>迭代器名(istream_type & ist);
//如：
//istream_iterator<int,char> isi(cin);
//现在isi就是一个输入流迭代器，通过isi可使用cin接收int数据类型的键盘输入，结束符为非数字字符


#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::istream_iterator;
using std::vector;

int main()
{
	vector<int> obV;  //创建vector<int>容器obV
	istream_iterator<int,char> itis(cin);  //创建输入流迭代器itis
	copy(itis, istream_iterator<int,char>(),back_inserter(obV));  //将输入流插入到obV中
	//只做了解
	for(vector<int>::iterator itV = obV.begin(); itV != obV.end(); ++itV)
		cout << *itV << " ";
	cout << endl;

	getchar();
	return 0;
}
 
