 ///
 /// @file    abstra_class.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-07-08 16:39:41
 ///

//抽象类：类中只要有纯虚函数，就是抽象类
//特性：抽像类只能作为基类来派生新类，不能创建抽象类的对象

//抽像类
#include <iostream>
#include <cmath>

using namespace std;

#define PI 3.1415926  //宏定义

class Figure  //图形基类定义
{
public:
	virtual float Area() = 0;  //纯虚函数，因此Figure类是抽象类，无法声明其对象
	virtual void DispName() = 0;
};

class Circle
: public Figure  //在抽象类Figure的基础上派生Circle圆类
{
public:
	Circle(float r = 0)  //构造函数
	{
		radius = r;
	}

	virtual void DispName()  //覆盖实现了虚函数DispName，此处virtual去掉没有影响
	{
		cout << "圆：" << endl;
	}
	virtual float Area()  //覆盖实现了虚函数Area，用来计算圆的面积
	{  //virtual去掉同样没有影响
		return PI * radius * radius;
	}
private:
	float radius;  //半径
};

class Rectangle
: public Figure  
{
public:
	Rectangle(float x = 0, float y = 0)
	: _x(x)
	, _y(y)
	{
	}
	virtual void  DispName()
	{
		cout << "矩形：" << endl;
	}
	virtual float Area()
	{
		return _x * _y;
	}
private:
	float _x;
	float _y;
};

class Triangle
: public Figure
{
public:
	Triangle(float x = 0, float y = 0, float z = 0)
	: _x(x)
	, _y(y)
	, _z(z)
	{
	}
	virtual void DispName()
	{
		cout << "三角形：" << endl;
	}
	virtual float Area()
	{
		float p = (_x + _y + _z) / 2;
		return sqrt(p * (p - _x) * (p - _y) * (p - _z));
	}
private:
	float _x;
	float _y;
	float _z;
};

void disp(Figure *p)
{
	p->DispName();
	cout << p->Area() << endl;
	cout << endl;
}

int main()
{
//	Figure f;  //错误，抽象类不能实例化
//	Figure *pF = new Figure();  //错误，抽象类不能使用new分配内存空间
	Figure *pF = NULL;  //虽然不能创建Figure类对象，但可声明Figure型的指针

	Circle c(3);  //声明一个圆对象，半径为3.
	Rectangle r(1.2f, 3.6f);  //声明一个矩形对象，其边长分别为1.2和3.6
	Triangle t(6, 7, 8);  //声明一个三角形对象，其边长分别为6,7,8
	//上面3句正确，可以这样实例化，因为Circle，Rectangle和Triangle不再是抽象类了
	//其基类的2个虚函数DispName()和Area()都已经有定义了。
	//如果删除其中任何一个定义，就会编译出错。
	
	pF = &c;  //用圆对象c的地址为pF赋值
	pF->DispName();  //调用DispName时，对应着Circle类中的版本
	cout << pF->Area() << endl;  //调用Area时，对应着Circle类中的版本
	cout << endl
		;
	pF = &r;  //用矩形对象r的地址为pF赋值
	pF->DispName();  //调用DispName时，对应着Rectangle类中的版本
	cout << pF->Area() << endl;  //调用Area时，对应着Rectangle类中的版本
	cout << endl;

	pF = &t;  //用圆对象t的地址为pF赋值
	pF->DispName();  //调用DispName时，对应着Triangle类中的版本
	cout << pF->Area() << endl;  //调用Area时，对应着Triangle类中的版本
	cout << endl;

	disp(&c);
	disp(&r);
	disp(&t);

	return 0;
};


