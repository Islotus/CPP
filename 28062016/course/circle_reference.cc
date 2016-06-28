 ///
 /// @file    circle_reference.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-29 00:06:40
 ///
 
#include <iostream>
#include <memory>

using std::cin;
using std::cout;
using std::endl;
using std::shared_ptr;

class Parent;  //前向声明

class Child
{
public:
	Child() {	cout << "Child()" << endl;	}
	~Child() {	cout << "~Child()" << endl;	}

	shared_ptr<Parent> _parentPtr;
};

class Parent
{
public:
	Parent() {	cout << "Parent()" << endl;		}
	~Parent() {	cout << "~Parent()" << endl;	}
	
	shared_ptr<Child> _childPtr;
};

int main()
{
	//问题是：循环引用，发生内存泄露
	shared_ptr<Parent> parentPtr(new Parent);
	shared_ptr<Child> childPtr(new Child);
	cout << "parent's use_count() = " << parentPtr.use_count() << endl;
	cout << "child's use_count() = " << childPtr.use_count() << endl;

	parentPtr->_childPtr = childPtr;
	childPtr->_parentPtr = parentPtr;
	cout << "parent's use_count() = " << parentPtr.use_count() << endl;
	cout << "child's use_count() = " << childPtr.use_count() << endl;

	return 0;
}





