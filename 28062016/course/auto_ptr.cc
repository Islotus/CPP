 ///
 /// @file    auto_ptr.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-28 21:57:45
 ///

#include <memory>
#include <iostream>
 
using std::cin;
using std::cout;
using std::endl;
using std::auto_ptr;

int main()
{
	double* pd = new double(88.88);
	auto_ptr<double> app(pd);  //以后对原指针pd的操作，就可以借助智能指针（本质对象，重载了*,->,）app来完成
	cout << "*app = " << *app << endl;  //调用原指针指向的值
//	cout << "app = " << app << endl;  //Error,auto_ptr,没重载<<运算符
	cout << "app.get()" << app.get() << endl;  //获取原生态的指针
	cout << "pd       " << pd << endl << endl;

	int * p1 = new int(5);
	auto_ptr<int> api(p1);
	auto_ptr<int> api2(api);  
	//复制语义:这里有缺陷，因为执行复制语句后，原来的指针就被赋值成0了，后面都不能使用了
	//即表达的是值语义，但是实现有缺陷，在底层已经发生了所有权的转移
	cout << "*api = " << *api2 << endl;
	cout << "api = " << *api << endl;  //Segment fault，api已经不能再使用了

	return 0;
}

