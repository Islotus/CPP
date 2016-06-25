 ///
 /// @file    replace_if.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-25 16:32:42
 ///

//repalce_if()使用示例
#include <iostream>
#include <algorithm>  //使用for_each算法要包含的头文件
#include <functional>  //使用less<>类模板要用的头文件
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::less;

typedef vector<int> VI;
typedef vector<int>::iterator itVI;

void disp(VI::value_type v)
{
	cout << v << " ";
}

int main()
{
	int arr[] = {1,2,3,4,5,6,7,8,9};
	VI obV(arr, arr+9);
	less<int> lt;  //创建less<int>类函数对象
//	replace_if(obV.begin(), obV.end(), bind2nd(lt,3), 7);  //将ob中小于3的元素全不替换成7
	replace_if(obV.begin(), obV.end(), bind1st(lt,3), 7);  //如果执行这句，则 1 2 3 7 7 7 7...
	
	for(itVI itV = obV.begin(); itV != obV.end(); ++itV)
	{
		cout << *itV << " ";
	}
	cout << endl;

#if 1
	cout << "for_each(): " << endl;
	for_each(obV.begin(), obV.end(), disp);
	cout << endl;
#endif
	
	return 0;
}
 
