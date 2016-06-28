 ///
 /// @file    shared_ptr.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-28 23:45:02
 ///
 
#include <iostream>
#include <memory>

using std::cin;
using std::cout;
using std::endl;
using std::shared_ptr;

class Point
{
friend std::ostream & operator <<(std::ostream & os, const Point & rhs);
public:
	Point(int ix = 0, int iy = 0)
	:_ix(ix)
	,_iy(iy)
	{
		cout << "Point(int,int)" << endl;
	}

	~Point()
	{
		cout << "~Point()" << endl;
	}
private:
	int _ix;
	int _iy;
};

std::ostream & operator <<(std::ostream & os, const Point & rhs)
{
	os << "(" << rhs._ix
		<< ", " << rhs._iy
		<< ")";
	return os;
}

int test0()
{
	shared_ptr<int> spi(new int(88));
	cout << "*spi = " << *spi << endl;
	cout << "spi'use_count = " << spi.use_count() << endl;

	{
	shared_ptr<int> spi2 = spi;//shared_ptr可以进行复制，复制时，只是引用计数加1，析构是，引用计数减1，为零才销毁
	cout << "spi2 = " << *spi2 << endl;
	cout << "spi'use_count = " << spi.use_count() << endl;
	cout << "spi2'use_count = " << spi2.use_count() << endl;
	}
	cout << endl;
	cout << "spi'use_count = " << spi.use_count() << endl;
	return 0;
}

int main()
{
	shared_ptr<Point> spi(new Point(88,66));
	cout << "*spi = " << *spi << endl;
	cout << "spi'use_count = " << spi.use_count() << endl;

	{
	shared_ptr<Point> spi2 = spi;
	cout << "spi2 = " << *spi2 << endl;
	cout << "spi'use_count = " << spi.use_count() << endl;
	cout << "spi2'use_count = " << spi2.use_count() << endl;
	}
	cout << endl;
	cout << "spi'use_count = " << spi.use_count() << endl;
	return 0;
}

