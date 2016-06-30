 ///
 /// @file    composition.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-30 20:31:31
 ///

//组合还是继承
#include <iostream>
 
using namespace std; 

class Eye
{
public:
	Eye()
	{
		cout << "Eye()" << endl;
	}
	void Look()
	{
		cout << "Eye.look()" << endl;
	}
};

class Nose
{
public:
	Nose()
	{
		cout << "Nose()" << endl;
	}
	void Smell()
	{
		cout << "Nose.Smell()" << endl;
	}
};

class Mouth
{
public:
	Mouth()
	{
		cout << "Eat()" << endl;
	}
	void Eat()
	{
		cout << "Mouth.Eat()" << endl;
	}
};

class Ear
{
public:
	Ear()
	{
		cout << "Ear()" << endl;
	}
	void Listen()
	{
		cout << "Ear.Listen()" << endl;
	}
};


//组合方式：逻辑很清楚，后续扩展很方便
class Head
{
public:
	Head()
	{
		cout << "Head()" << endl;
	}
	void Look()
	{
		m_eye.Look();
	}
	void Smell()
	{
		m_nose.Smell();
	}
	void Eat()
	{
		m_mouth.Eat();
	}
	void Listen()
	{
		m_ear.Listen();
	}

private:
	Eye m_eye;
	Nose m_nose;
	Mouth m_mouth;
	Ear m_ear;
};

//继承方式，会给或续设计带来很多逻辑上的问题
class HeadX
: public Eye
, public Nose
, public Mouth
, public Ear
{
public:
	HeadX()
	{
		cout << "HeadX()" << endl;
	}
};

int main()
{
	Head h;
	h.Look();
	h.Smell();
	h.Eat();
	h.Listen();

	cout << endl;

	HeadX hx;
	hx.Look();
	hx.Smell();
	hx.Eat();
	hx.Listen();

	return 0;
}


