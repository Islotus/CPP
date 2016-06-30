 ///
 /// @file    derived_conversion_derived.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-30 21:14:04
 ///

//example1
#include <iostream>
#include <string.h>

using namespace std;

class CBase
{
public:
	CBase(const char *pszData)  //1
	: m_pszData(new char[strlen(pszData) + 1])
	{
		strcpy(m_pszData, pszData);
		cout << "CBase(const char *)" << endl;
	}
	CBase(const CBase & base)  //3
	: m_pszData(new char[strlen(base.m_pszData) + 1])
	{
		strcpy(m_pszData, base.m_pszData);
		cout << "CBase(const CBase &)" << endl;
	}
	CBase & operator =(const CBase & base)
	{
		cout << "CBase & operator =(const CBase &)" << endl;
		if(this == &base)
			return *this;
		delete [] this->m_pszData;
		m_pszData = new char[strlen(base.m_pszData) + 1];
		strcpy(m_pszData, base.m_pszData);
		return *this;
	}
	~CBase()
	{
		delete [] m_pszData;
		cout << "~CBase()" << endl;
	}

protected:
	char* m_pszData;
};

class CDerived
: public CBase
{
public:
	CDerived(const char *pszData)
	:CBase(pszData)
	{
		cout << "CDerived(const char *)" << endl;
	}
};

int main()
{
	CDerived d1("Hello!");
	CDerived d2 = d1;  //派生类使用缺省的拷贝构造函数、基类调用用户定义的拷贝构造函数

	d1 = d2;

	return 0;
}



