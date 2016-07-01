 ///
 /// @file    duotai.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-07-01 09:06:56
 ///

//设计多态的主要目的是：定义好一个祖先类，并定义一些虚函数（接口），但在这个接口函数中并不给出具体的实现，或者
//只是一些简单的实现，这个工作留给后代去具体实现
#include <iostream>

using namespace std;

class CWorm
{
public:
	virtual void Draw()
	{
		cout << "CWorm::Draw()" << endl;
	}
	virtual void Draw1()
	{
		cout << "CWorm::Draw1()" << endl;
	}
};

class CAnt
: public CWorm
{
public:
	void Draw()
	{
		cout << "CAnt::Draw()" << endl;
	}
};

class CSpider
: public CWorm
{
public:
	void Draw()
	{
		cout << "CSpider::Draw()" << endl;
	}
};

void display(CWorm *p)  //display函数，以base指针为参数
{
	p->Draw();
}

int main()
{
	CWorm *pWorm;

	cout << "ant: " << endl;
	CAnt ant;
	pWorm = & ant;
	pWorm->Draw();
	display(pWorm);
	display(&ant);

	cout << "spider: " << endl;
	CSpider spider;
	pWorm = &spider;
	pWorm->Draw();
	display(pWorm);
	display(&spider);


	return 0;
}

