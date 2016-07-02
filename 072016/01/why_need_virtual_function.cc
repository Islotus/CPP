 ///
 /// @file    why_need_virtual_function.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-07-02 20:29:25
 ///

//为什么需要虚函数
#include <iostream>

using namespace std;

class base  //基类base定义
{
public:
	virtual
	void disp()  //基类base中的普通成员函数disp
	{
		cout << "hello, base" << endl;
	}
};

class child1
: public base  //派生类child1从base派生而来
{
public:
	void disp()  //派生类child1中定义的disp函数将base类中定义的disp函数隐藏
	{
		cout << "hello, child1" << endl;
	}
};

class child2
: public base  //派生类child2从base派生而来
{
public:
	void disp()  //派生类child2中定义的disp函数同样会隐藏base类中定义的disp函数
	{
		cout << "hello, child2" << endl;
	}
};
 
void display(base * pb)  //display函数，以base指针为参数
{
	pb->disp();
}

int main()
{
	base *pBase = NULL, obj_base;  //创建一个基类指针pBase，初始化为NULL，创建一base类对象obj_base
	obj_base.disp();  //通过对象名调用disp函数

	pBase = &obj_base;  //使用obj_base的地址为pBase赋值
	pBase->disp();  //通过指针调用disp()函数
	
	cout << endl;
	child1 *pChild1 = NULL, obj_child1;  //创建一个child1类指针pChild，初始化为NULL，创建一child1类对象obj_base
	obj_child1.disp();  //通过对象名调用disp函数

	pChild1 = &obj_child1;  //使用obj_child1的地址为pChild1赋值
	pChild1->disp();  //通过指针调用disp函数

	cout << endl;
	child2 *pChild2 = NULL, obj_child2;  //创建一child2类指针pChild2,初始化为NULL，创建一child类对象obj_child2
	obj_child2.disp();  //通过对象名调用disp函数

	pChild2 = &obj_child2;  //使用obj_child2的地址为pChild2赋值
	pChild2->disp();  //通过指针调用disp函数

	cout << endl;
	//测试在void base::disp()函数前加和不加virtual时下列指针式输出的不同！！！！！！！！！！！！
	pBase = &obj_child1;  //使用obj_child1的地址为pBase赋值
	pBase->disp();  //通过指针pBase调用disp函数

	cout << endl;
	display(&obj_base);
	display(&obj_child1);
	display(&obj_child2);

	cout << endl;

	//(*指针).disp()式的调用
	(*pBase).disp();

	return 0;
}

//总结：
//形成多态的条件：有继承关系并且派生类中对基类的virtual函数实现了覆盖，利用基类的引用或指针指向派生类对象，
//再用基类的对象去调用virtual寒素的时候会实现多态


