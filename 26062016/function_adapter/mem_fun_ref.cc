 ///
 /// @file    men_fun_ref.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-26 22:08:53
 ///

//成员函数适配器，也是两个：
//>mem_fun()  //容器参数为类指针
//>men_fun_ref()  //容器参数为类对象  //具体用法见MSDN和备注代码（备注后半部分）
//>mem_fn()  //两者都能用(C++11)
//

//c++编程过程中尽量不要使用自己写的循环，最好用for_each，
//当容器中放的是对象时，然后for_each后面的函数就要用到mem_fun_ref或mem_fun了。
//调用对象的成员函数就要用到这两个函数，别忘了这两个参数里面要加&
//
//mem_fun_ref的作用和用法根mem_fun一样，唯一的不同就是：
//当容器中存放的是对象实体的时候用mem_fun_ref，
//当容器中存放的是对象的指针的时候用mem_fun。

//成员函数适配器mem_fun_ref的用法示例
#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::for_each;
using std::mem_fun_ref;
using std::mem_fn;

 
class NumVals
{
public:
	NumVals()
	:_val(0)
	{
//		cout << "NumVals()" << endl;
	}

	NumVals(int j)
	:_val(j)
	{
//		cout << "NumVals(int)" << endl;
	}

	bool display()
	{
		cout << _val << " ";
		return true;
	}

	bool isEven()
	{
		return (bool) !(_val %2);
	}

	bool isPrime()
	{
		for(int i = 2; i <= (_val/2); ++i)
		{
			if(!(_val%i))
				return false;
		}
		return true;
	}
private:
	int _val;
};


int main()
{
	//1.
	vector<NumVals> v1(13);
	vector<NumVals>::iterator it1;
	for(int i = 0; i < 13; ++i)
	{
		v1[i] = NumVals(i+1);
	}

	cout << "v1中的原始值为：" << endl;
	for_each(v1.begin(), v1.end(), mem_fun_ref(&NumVals::display));
	cout << endl;

	//Use of mem_fun_ref calling member function through a reference
	//remove thr primes in the vector using isPrime()
	it1 = remove_if(v1.begin(), v1.end(), mem_fun_ref(&NumVals::isPrime));
		//调用对象的成员函数判断是不是质数
	cout << "v1中删除质数后剩下的值为：" << endl;
	for_each(v1.begin(), it1, mem_fun_ref(&NumVals::display));
	cout << endl << endl;

	//2.
	vector<NumVals> v2(13);
	vector<NumVals>::iterator it2;
	for(int k = 0; k < 13; ++k)
	{
		v2[k] = NumVals(k+1);
	}
	cout << "v2中的原始值为：" << endl;
	for_each(v2.begin(), v2.end(), mem_fun_ref(&NumVals::display));
		//c++编程过程中尽量不要使用自己写的循环，
		//mem_fun_ref的作用和用法根mem_fun一样，唯一的不同就是：
		//当容器中存放的是对象实体的时候用mem_fun_ref，
		//当容器中存放的是对象的指针的时候用mem_fun。
	cout << endl;

	//Use of mem_fun_ref calling member function through a reference
	//remove the even numbers in the vector v2 using isEven()
	it2 = remove_if(v2.begin(), v2.end(), mem_fun_ref(&NumVals::isEven));
	cout << "v2中删除偶数后剩下的值为：" << endl;
	for_each(v2.begin(), it2, mem_fun_ref(&NumVals::display));
	cout << endl;

	//3.
	//测试mem_fn函数
	//结果：可以，以后可以用mem_fn取代mem_fun_ref和mem_fun了，简便很多
	//remove_if不是真正的删除元素，只是把元素放到后面去了
#if 1
	vector<NumVals> v3(13);
	vector<NumVals>::iterator it3;
	for(int k = 0; k < 13; ++k)
	{
		v3[k] = NumVals(k+1);
	}
	cout << "v3中的原始值为：" << endl;
	for_each(v3.begin(), v3.end(), mem_fn(&NumVals::display));
	cout << endl;

	it3 = remove_if(v3.begin(), v3.end(), mem_fn(&NumVals::isEven));
	cout << "v3中删除偶数后剩下的值为：" << endl;
	for_each(v3.begin(), it3, mem_fn(&NumVals::display));
	cout << endl;

	cout << "v3中当前的元素为：" << endl;
	for_each(v3.begin(), v3.end(), mem_fn(&NumVals::display));
	cout << endl;
#endif

	return 0;
}
