 ///
 /// @file    point.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-29 15:42:45
 ///

//继承与派生的概念 有point类 派生point3D类

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class Point
{
public:
	Point(int x = 0, int y = 0)  //constructor,band default parameter
	:_x(x)
	,_y(y)
	{
		cout << "Point(int,int)" << endl;
	}
	~Point()
	{
		cout << "~Point()" << endl;
	}
	
	void disp()
	{
		cout << "(" << _x
			<< ", " << _y
			<< ")" << endl;
	}

	int getX()
	{	return _x;	}
	
	int getY()
	{	return _y;	}

private:
	int _x;
	int _y;
};
 

class Point3D
:public Point  //3维点类point3D，从point类继承而来
{
public:
	Point3D(int x, int y, int z) 
	:Point(x,y)  //派生类构造函数，初始化表中调用基类构造函数
	,_z(z)
	{
		cout << "point3D(int,int,int)" << endl;
	}

	void disp()  //隐藏了基类的同名disp函数
	{
		cout << "(" << getX()
			<< ", " << getY()
			<< ", " << _z
			<< ")" << endl;
	}

	int calcSum()  //增加了计算3个数据成员和的函数
	{
		return getX() + getY() + _z;
	}

	~Point3D()
	{
		cout << "~Point3D()" << endl;
	}

private:
	int _z;  //在point类基础上增加了_z坐标信息
};

int main()
{
	Point pt1(7,8);
	pt1.disp();

	Point3D pt2(3,4,5);
	pt2.disp();

	int res = pt2.calcSum();
	cout <<res << endl;

	return 0;
}

