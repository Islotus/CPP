 ///
 /// @file    point2.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-29 16:17:58
 ///

//public派生与private派生
//C++中利用基类派生其派生类的基本格式为：
//class 派生类名：派生方式 基类名
//{
//private:
//	新增私有成员列表；
//public:
//	新增公开成员列表；
//};

//public,protected,private派生方式
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class Point
{
public:
	Point(int x = 0, int y = 0)  //构造函数，带缺省构造参数
	:xPos(x)
	,yPos(y)
	{
		cout << "Poing(int,int)" << endl;
	}

	void disp()  //membet function:disp(),output information of Point
	{
		cout << "(" << xPos
			<< ", " << yPos
			<< ")" << endl;
	}

	int getX()  //读取private成员xPos
	{
		return xPos;
	}

	int getY()  //读取private成员yPos
	{
		return yPos;
	}

private:  //private成员列表，表示点的坐标信息
	int xPos;
	int yPos;
};

class Point3D
:protected Point  //3维点类Point3D,从Point类继承而来，注意格式
{
public:
	Point3D(int x, int y, int z)  //派生类构造函数，初始化表中调用基类构造函数
	:Point(x,y)
	 ,zPos(z)
	{
		cout << "Point3D(int,int,int)" << endl;
	}

	void disp()  //隐藏了基类的中的同名disp函数
	{
		cout << "(" << getX() 
			<< ", " << getY()
			<< ", " << zPos
			<< ")" << endl;
	}

	int calcSum()  //增添了计算3个数据成员和的函数
	{
		return getX() + getY() + zPos;
	}

private:
	int zPos;  //在Point类基础上增加了zPos坐标信息
};

int main()
{

	//自己动手，分别使用public,protected和private派生Point3D类
	//则在public派生方式时下列访问派生类的getX()不会出错，
	//但protected和private派生方式时会编译报错

#if 0  //测试public继承
	Point3D pt(3, 4, 5);
	cout<< "pt.getX(): " << pt.getX() << endl;  

	//disp()在3种方式下都可以访问，因为disp()在Point3D类中被覆盖成public类型了
	pt.disp();

	//calcSum()在3种方式下都可以访问，因为它是在Point3D类中新定义的public成员函数
	cout << "pt.calcSum(): " << pt.calcSum() << endl;
#endif

#if 0  //测试protected继承

	Point3D pt(3, 4, 5);
//	cout<< "pt.getX(): " << pt.getX() << endl;  //Error,pt.getX是Point3D类的私有成员，对象不能调用

	//disp()在3种方式下都可以访问，因为disp()在Point3D类中被覆盖成public类型了
	pt.disp();  //可以，因为disp()是类Point3D的public成员函数，对象可以调用

	//calcSum()在3种方式下都可以访问，因为它是在Point3D类中新定义的public成员函数
	cout << "pt.calcSum(): " << pt.calcSum() << endl;  //可以调用，因为，是新定义的成员函数
#endif

#if 1  //测试private继承
	Point3D pt(3, 4, 5);
//	cout<< "pt.getX(): " << pt.getX() << endl; //不能访问，因为它在派生类Point3D中是私有的，对象不能访问 

	//disp()在3种方式下都可以访问，因为disp()在Point3D类中被覆盖成public类型了
	pt.disp();

	//calcSum()在3种方式下都可以访问，因为它是在Point3D类中新定义的public成员函数
	cout << "pt.calcSum(): " << pt.calcSum() << endl;
#endif
	return 0;

}

