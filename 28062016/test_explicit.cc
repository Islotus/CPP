 ///
 /// @file    test_explicit.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-28 13:44:17
 ///

//测试explicit
//explicit关键字就是说，显示调用构造函数，不允许隐式调用构造函数，
//也就是说，构造临时对象不允许
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::ostream;

class Test
{
public:
//	explicit
	Test(int x = 0, int y = 0)
	:_x(x)
	,_y(y)
	{
		cout << "Test(int x = 0, int y = 0)" << endl;
	}

	Test(const Test & rhs)
	:_x(rhs._x)
	,_y(rhs._y)
	{
		cout << "Test(const Test & rhs)" << endl;
	}

	Test & operator =(const Test & rhs)
	{
		_x = rhs._x;
		_y = rhs._y;
		cout << "Test & operator =(const Test & rhs)" << endl;
	}

	friend ostream & operator <<(ostream  & os, Test & rhs);

private:
	int _x;
	int _y;
};

ostream& operator <<(ostream &os, Test &rhs)
{
	os << "(" << rhs._x << ", " << rhs._y << ")" << endl;
	return os;
}

int main()
{
	Test t1;
	cout << "t1" << endl;
	cout << t1 << endl;

	Test t2(1,2);
	cout << "t2(1,2)" << endl;
	cout << t2 << endl;

	cout << "t2 = 5" << endl;
//	t2 = 5;  //这句也是，当加explicit关键字后，这句就编译通不过
	cout << t2 << endl;

#if 0
	//构造函数前面加explicit关键字后，下面就运行不了
	cout << "t2 = Test(10,10)" << endl;
	t2 = Test(10,10);
	cout << t2 << endl;
#endif

	

	return 0;
}

