 ///
 /// @file    multiset.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-23 15:19:34
 ///

//关联式容器 associative container
//使用multiset 需要包含头文件<set>
//multiset的创建方式与set相同，也是3中方式
//multiset与set不同之处在于其允许出现相同的关键字

//multiset容器的使用：关键字允许重复，按照关键字排序
#include <iostream>
#include <set>

using std::cin;
using std::cout;
using std::endl;
using std::multiset;

int main()
{
	int arr[9] = {2, 1, 3, 5, 4, 6, 3, 5, 6};
	multiset<int> msetI(arr, arr+9);
	cout << msetI.size() << endl;

	multiset<int>::iterator iter = msetI.begin();
	while(iter != msetI.end())
	{
		cout << *iter << " ";
		++iter;
	}
	cout << endl;

	for(auto &mem : msetI)  //c++11版本才允许这样用，g++ multiset.cc -std=c++11
		cout << mem << " ";
	cout << endl;

#if 0  
	while(auto &mem : msetI)  //Error，while中不允许这样用，只有for中可以这样用
		cout << mem << " ";
	cout << endl;
#endif

	return 0;
}
 
