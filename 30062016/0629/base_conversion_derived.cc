 ///
 /// @file    base_conversion_derived.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-30 20:50:15
 ///

//单基继承的类型适应
#include <iostream>

using namespace std;

class Point  //定义Point类
{
public:
	Point(int xp = 0, int yp = 0)  //构造函数
	: _x(xp)
	, _y(yp)
	{
		cout << "Point(int, int)" << endl;
	}
	void DispPoint()  //成员函数DispPoint的定义
	{
		cout << "(" << _x
			<< ", " << _y
			<< ")" << endl;
	}
	int GetX()  //成员函数用以读取private成员x的值
	{
		return _x;
	}
	int GetY()  //成员函数用以读取private成员y的值
	{
		return _y;
	}

private:
	int _x;
	int _y;
};
 
class Point3D
: public Point  //类Point3D由类Point派生而来
{
public:
	Point3D(int xp = 1, int yp = 1, int zp = 1)
	: Point(xp, yp)  //构造函数，在初始化表中调用基类的构造函数
	,_z(zp)
	{
		cout << "Point3D(int, int, int)" << endl;
	}
	void Disp3DPoint()  //成员函数Disp3DPoint
	{
		cout << "(" << GetX()
			<< ", " << GetY()
			<< ", " << _z
			<< ")" << endl;
	}

private:
	int _z;  //在基类Point的基础上增加的数据成员
};

int main()
{
	Point pt1(1, 1);  //声明一个Point类对象pt1
	pt1.DispPoint();  //通过pt1调用DispPoint函数

	Point3D pt2(2, 3, 4);  //
	pt2.Disp3DPoint();

	pt1 = pt2;  //派生类对象给基类对象赋值
	pt1.DispPoint();

	Point &rpt1 = pt2;  //派生类对象初始化基类对象引用
						//不能反过来，因为基类不知道如何给派生类新增的成员赋值
	rpt1.DispPoint();

	Point* ppt1 = &pt2;  //派生类对象地址为基类指针赋值
	ppt1->DispPoint();

	return 0;
}

