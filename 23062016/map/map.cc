 ///
 /// @file    map.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-23 15:38:10
 ///

//关联式容器associative container
//map的元素是一对对的“关键字-值”组合。
//在map容器中，每个关键字只能出现一次，不能重复
//可使用模板类pair<class T1, class T2>来表示map容器中形如“关键字-值”的每个元素
//创建方式3种
//map支持[]下标式的随机访问，也支持迭代器访问元素

//map容器的使用:关键字不允许重复，按照关键字排序，下标法，下标表示的是关键字值，整体式value值
#include <iostream>
#include <map>
#include <string>
#include <utility>

using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::string;
using std::pair;

//#define T pair<int,string>

int main()
{
	//pair<int, string>模板类的用法
	pair<int,string> t(9, "Asia");
	cout << t.first << " " << t.second << endl;

	//创建pair<int,string>型数组
	pair<int,string> arr[4] = {pair<int,string>(9, "Asia"), pair<int,string>(4, "Africa"),
								pair<int,string>(1, "Euro"), pair<int,string>(4, "America")};
	map<int,string> obM(arr, arr+4);  //用迭代器区间构造obM
	cout << obM.size() << endl;  //输出obM中的元素个数

	map<int,string>::iterator it = obM.begin();  //创建map<int,string>模板类的迭代器，指向obM的头部
	while(it != obM.end())  //按顺序逐个输出obM中的元素
	{
		cout << (*it).first << " : " << (*it).second << endl;
		++it;
	}

	cout << "下标访问方式：" << endl;

#if 0
	int sizeM = obM.size();
	for(int i = 0; i < sizeM; ++i)
		cout << obM[i].first << " : " << obM[i].second << endl;
#endif
	//map下标运算符[]的作用是:若key存在，则返回相应的value;若key不存在，则对该key对应的value赋一个对应value类型数据的默认值并返回
	//上边一句是在网上抄的。也就是说，map下标运算符中的数值是关键字，不是keyword,obM[keyword]输出的是keyword对应的value值，
	//容器map有的话，做相应的改变，没有的话，做对应的改变。
	cout << obM[4] << " : " << obM[4]<< endl;  

	for(auto &mem : obM)  //因为map中存放的是pair模板类，这句话，表示mem代表obM的元素，也即pair，故可以调用pair中的first，second
							//函数。编译时g++ map.cc -std=c++11
		cout << mem.first << " : " << mem.second << endl;

	return 0;
}


 
