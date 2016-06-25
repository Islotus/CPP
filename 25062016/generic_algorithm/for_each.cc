 ///
 /// @file    for_each.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-25 16:01:36
 ///

//for_each()用法

#include <iostream>
#include <algorithm>  //使用for_each算法要包含的头文件
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

typedef vector<int> VI;
typedef VI::iterator itVI;

void func(VI::value_type v)  //定义一元函数func，以元素类型为参数
{
	cout << v << " ";
}

int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6};
	VI obV(arr, arr+6);
	for_each(obV.begin(), obV.end(), func);  //对obV中所有元素执行func操作
	cout << endl;

	return 0;
}

//对于for_each而言，如果是vector<int> ob;这样的，此时调用for_each(ob.begin(),ob.end(),func);函数的时候，
//func函数的参数是int(vector<int>::value_type)
//如果是map<int,string> obM;这样的，此时调用for_each(obM.begin(),obM.end(),func);函数的时候，func函数的参数是
//pair<int,string>这种数据类型的。
//总结：对于for_each的第三个参数而言，写函数的时候，函数的参数就是其中的迭代器指向的类型。
//对于vector<CMyString> 则是CMyString
//对于map<CMyString,string> 则是由CMyString和string组成的，所以是pair<CMyString,string>
