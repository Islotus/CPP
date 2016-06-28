 ///
 /// @file    unique_ptr.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-28 23:09:32
 ///
 
#include <iostream>
#include <memory>
#include <vector>

using std::cout;
using std::endl;
using std::unique_ptr;
using std::vector;

unique_ptr<int> getValue()
{
	unique_ptr<int> upi(new int(88));
	return upi;
}

int main()
{
	//unique_ptr无法进行复制或赋值，表达的是对象语义
	unique_ptr<int> upi(new int(6));
	//unique_ptr<int> upi2(upi); //Error

//	unique_ptr<int> upi2 = upi;
//	//Error,因为upi为有名对象，不能进行赋值操作，调用的是复制构造函数

	unique_ptr<int> upi3(new int(8));
//	upi3 = upi;  //Error
	
	unique_ptr<int> upi4 = getValue();
	//getValue返回的是匿名对象，调用的是移动构造函数
	cout << "*upi4 = " << *upi4 << endl;

	vector<unique_ptr<int> > vecUqi;
//	vecUqi.push_back(upi4);  //Error,因为upi4是有名函数，会调用复制构造函数
	vecUqi.push_back(std::move(upi4));  //完成了移动语义，在该语句以后不能再使用upi4
		//unique_ptr能够作为容器的元素
//	cout << "*upi4 = " << *upi4 << endl;//Segment fault,
	return 0;

}


