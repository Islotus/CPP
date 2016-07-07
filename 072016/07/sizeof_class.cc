 ///
 /// @file    sizeof_class.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-07-07 21:05:53
 ///

//求包含虚函数的类的sizeof
#include <iostream>

using namespace std;

class A
{
int i;
void f() {}
virtual void run() {}
virtual void run1() {}
virtual void run2() {}
};

class B
: virtual public A
{
virtual void run() {}
virtual void run1() {}
};
 
int main()
{
	cout << "sizeof(A) = " << sizeof(A) << endl;
	cout << endl;
	cout << "sizeof(B) = " << sizeof(B) << endl;
}

/*
 * 其中 sizeof(A) = 8;(int i占4个字节，run()是virtual，会有一个指向虚函数表的指针，占4个字节，此时虽然
 * run1和run2也都是virtual，但是已经有一个虚函数表，则不再创建。所以是8)
 * sizeof(B) = 12;（继承来的int i 占4个字节，虚继承,会创建虚表，占4个字节，run()是virtual，占4个字节，
 * 此时虽然run1也是virtual，但是已经存在虚函数表，则不再创建，所以为12）
 *
 */
//我的想法：class B中，继承i占4个字节，继承基类的虚函数指针4个字节，虚继承，有一个指向基类的虚基指针占4个字节


#if 0

//
#include <iostream>
 
using namespace std;

class A
{
	int i;
	void f();
	virtual void run() {}
	virtual void run1() {}
	virtual void run2() {}
};
class B
: virtual public A
{
	virtual void run() {}
	virtual void run1() {}
	virtual void run3() {}
};

int main()
{
	cout << "sizeof(A) = " << sizeof(A) << endl;
	cout << "sizeof(B) = " << sizeof(B) << endl;

	return 0;
}
/*
 *其中，sizeof(A) = 8；（int i占4个字节，run()是virtual，会有一个指向虚函数的指针，占4个字节，此时虽然run1和
 *run2也都是virtual，但是已经有一个虚函数表，则不再创建，所以为8）
 *sizeof(B) = 16(VS中，而在vim中为12)（继承来的int i占4个字节，虚继承，会创建虚表，占4个字节，run()和run1()都是
 *基类中已经存在的虚函数，此时覆盖基类虚函数，占4个字节，此时run3是新定义的virtual，则有多了4个字节，所以为16）
 */

//我的看法：
//继承int i,4个字节。派生类B中虚表4个字节（其中子类覆盖基类的相同函数），由于虚继承，派生类中又多了一个虚基指针
//由于派生类中有自己特有的虚函数，在VS中，它会再多一个指向自己的虚函数的虚指针。而在vim中，系统直接把派生类中
//特有的虚函数放在第一个基类虚函数表的后面。



#endif
