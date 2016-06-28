 ///
 /// @file    RAII.h
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-28 20:57:14
 ///

//RAII类模拟智能指针

#ifndef __MY_RAII_H__
#define __MY_RAII_H__

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

template <typename T>
class RAII
{
public:
	explicit
	RAII(T * p)
	:_p(p)
	{
		cout << "托管资源" << endl;
	}

	~RAII()
	{
		delete _p;
		cout << "释放资源" << endl;
	}

	T* get() const
	{	return this->_p;	}

	T & operator *() const
	{	return *(this->_p);	}

	T* operator ->()
	{	return this->_p;	}

	void reset(T* p)
	{
		delete _p;
		_p = p;
	}

	void swap(RAII & rhs)
	{
		std::swap(_p, rhs._p);
	}

private:  //这里表达对象语义
	RAII(const RAII & rhs);
	RAII & operator =(const RAII & rhs);
private:
	T* _p;
};


#endif
 
