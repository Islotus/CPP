 ///
 /// @file    String.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-24 21:55:35
 ///

//移动构造函数时c++11新增的功能，故在编译时要加上-std=c++11,
//也可以加上-fno-elide-constructors看详细的过程

#include <iostream>
#include <string.h>

using std::cin;
using std::cout;
using std::endl;
using std::ostream;

class String
{
	friend ostream & operator <<(ostream &os, const String &rhs);  //output operator overloading
public:
	String();  //default constructor
	String(const char* pstr);  //band one parameter constructor
	String(const String &rhs);  //copy constructor
	String &operator =(const String &rhs);  //assignment operator overloading

	//当同时定义了复制构造函数和移动构造函数时，如果传递的实参就是右值时，会优先调用
	//移动构造函数；同理，移动赋值运算符函数也有这样的优先权
	String(String && rhs);  //move constructor
	String &operator =(String && rhs);  //move assignment operator overloading

	~String();  //destructor 

	void swap(String & rhs)
	{
		char* ptmp = _pstr;
		_pstr = rhs._pstr;
		rhs._pstr = ptmp;
	}
private:
	char* _pstr;
};

ostream &operator <<(ostream &os, const String &rhs)  //realize output operator overloading
{
	os << rhs._pstr;
	return os;
}
String::String()  //realize default constructor
:_pstr(new char[1])
{
	cout << "String()" << endl;
}
String::String(const char* pstr)  //realize band one parameter constructor
:_pstr(new char[strlen(pstr) + 1])
{
	strcpy(_pstr, pstr);
	cout << "String(const char* pstr)" << endl;
}
String::String(const String & rhs)  //realize copy constructor
:_pstr(new char[strlen(rhs._pstr) + 1])
{
	strcpy(_pstr, rhs._pstr);
	cout << "String(const String &rhs)" << endl;
}
String &String::operator =(const String &rhs)  //realize assignment constructor
{
	if(this != &rhs)
	{
		String tmp(rhs);  //先创建局部对象
		swap(tmp);  //再进行交换  
			//这样做的目的，是为了避免因为避免因为申请堆内存不足而产生的错误
	}
	return *this;
}
//移动构造函数
String::String(String && rhs)  //realize move-constructor
:_pstr(rhs._pstr)  //先指向临时对象的空间
{
	rhs._pstr = NULL;  //再将临时对象的空间设为NULL
	cout << "String(String && rhs)" << endl;
}
//移动赋值运算符函数 （形参的右值引用本身是一个左值）
String & String::operator =(String && rhs)  //realize move-assignment operator overloading 
{
	delete [] _pstr;
	_pstr = rhs._pstr;
	rhs._pstr = NULL;
	cout << "String & operator =(String && rhs)" << endl;

	return *this;
}
String::~String()  //realize destructor
{
	delete [] _pstr;
	cout << "~String()" << endl;
}


int main()
{
	String s1 = "hello";  //String(const char *)
	cout << "s1 = " << s1 << endl;
	String s2 = "world";
	cout << "s2 = " << s2 << endl;
	cout << endl;

	String s3 = String("hello");  //调用了移动构造函数
	cout << "s3 = " << s3 << endl;

	s2 = std::move(s1);  //显示的将左值转换成右值
	cout << "s2 = " << s2 << endl;

	//当使用std::move函数将某个对象s1转成右值后，s1不能再使用
	//cout << "s1 = " << s1 << endl;  //Error
	
	cout << "s3 = " << s3 << endl;
	return 0;
}
