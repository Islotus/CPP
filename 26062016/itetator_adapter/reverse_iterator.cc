 ///
 /// @file    reverse_iterator.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-26 19:33:07
 ///

//迭代器适配器 iterator adapter 
//从某种意义上讲，前面介绍的流迭代器也是迭代器适配器，此外，还包括反向迭代器和插入迭代器。和使用流迭代器一样，
//使用反向和插入迭代器都必须包含头文件<iterator>

//反向迭代器 reverse_iterator
#include <iostream>
#include <iterator>  //使用reverse_iterator和ostream_iterator包含的文件
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::reverse_iterator;
using std::vector;
using std::ostream_iterator;

int main()
{
	int arr[5] = {1, 2, 3, 4, 5};
	vector<int> obV(arr, arr+5);  //
	ostream_iterator<int,char> osi(cout, " ");  //创建输出流迭代器

	vector<int>::reverse_iterator rit = obV.rbegin();  //创建反向迭代器
	copy(rit, obV.rend(), osi);  //输出操作 = copy(ob.rbegin(), ob.rend(), osi)

	cout << endl;

	for(; rit != obV.rend(); ++rit)
		cout << *rit << " ";
	cout << endl;

	return 0;
}

