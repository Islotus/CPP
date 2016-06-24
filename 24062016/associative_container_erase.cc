 ///
 /// @file    associative_container_erase.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-24 09:41:53
 ///

//关联式容器 associative container 
//元素的删除
//>1.UINT ob.erase(keywork)
//删除容器ob中所有关键字为keyword的元素，返回删除元素的个数（见代码）
//>2.void ob.erase(p)
//从ob中删除迭代器p所指向的元素，p必须存在，且不能为ob.end(),因为ob.end()是最后一个元素的下一个位置
//并不真正存在
//>3.void ob.erase(q1, q2)
//从ob中删除半开区间[q1, q2)之间的所有元素
//>4.void clear(void)
//删除ob中的所有元素，等价于void ob.erase(ob.begin(),ob.end());

//删除元素erase格式
#include <iostream>
#include <map>
#include <string>
#include <utility>

using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::multimap;
using std::string;
using std::pair;

typedef map<int,string> CM;  //typedef简化定义
typedef CM::value_type CMV;  //CMV实际上等价于pair<int,string>
typedef CM::iterator CMI;
typedef multimap<int,string> MCM;
typedef MCM::iterator MCMI;


void disp(CM &x)  //定义CM类型元素遍历输出函数
{
	CMI it = x.begin();
	CMI itend = x.end();
	for(; it != itend; ++it)
		cout << (*it).first << " " << (*it).second << endl;
}

void disp(MCM &x)  //重载MCM类型元素遍历输出函数
{
	MCMI it = x.begin();
	MCMI itend = x.end();
	for(; it != itend; ++it)
		cout << (*it).first << " " << (*it).second << endl;
}

int main()
{
	CMV arr[3] = {CMV(1, "A"), CMV(2, "B"), CMV(1, "C")};  //相当于定义了一个pair<int,string>数组

	//1.map
	CM obM(arr, arr+3);  //创建map<int,string>对象
	disp(obM);  //元素遍历输出

	CM::size_type num1 = obM.erase(1);
	cout << "删除所有关键字为1的元素后：" << endl;
	disp(obM);
	cout << "共删除了" << num1 << "个元素" << endl << endl;
	

	//2.multimap
	MCM obMM(arr, arr+3);  //创建multimap<int,string>对象
	disp(obMM);  //元素遍历输出

	MCM::size_type num2 = obMM.erase(1);  //
	cout << "删除所有关键字为1的元素后" << endl;
	disp(obMM);
	cout << "共删除了" << num2 << "个元素" << endl;

	return 0;

}
 
