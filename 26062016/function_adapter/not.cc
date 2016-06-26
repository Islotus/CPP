 ///
 /// @file    not.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-26 21:33:49
 ///

//函数适配器 function adapter
//否定器，也有两个
//>not1()  //用于逆转一元断言，如not1(bind2nd(lt,3)),见示例代码
//>not2()  //用于逆转二元断言

//否定器not1的使用
#include <iostream>
#include <algorithm>  //for_each头文件
#include <functional>  //使用less<>类模板要用的头文件
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::less;
using std::for_each;

typedef vector<int> VEC;
typedef vector<int>::iterator ITV;

int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6};
	VEC obV(arr, arr+6);
	less<int> lt;  //创建less<int>类函数对象
	replace_if(obV.begin(), obV.end(), not1(bind2nd(lt, 3)), 7);  // 1 2 7 7 7 7 

	for(ITV it = obV.begin(); it != obV.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	return 0;

}
 
