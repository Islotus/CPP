 ///
 /// @file    derived_conversion_derived2.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-30 22:03:43
 ///

//example2
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

class CBase
{
public:
	CBase()
	: m_pszData1(new char[1])
	{
		*(this->m_pszData1) = '\0';
		cout << "CBase()" << endl;
	}
	CBase(const char *pszData)
	: m_pszData1(new char[strlen(pszData) + 1])
	{
		strcpy(m_pszData1, pszData);
		cout << "CBase(const char *)" << endl;
	}
	CBase(const CBase & base)
	: m_pszData1(new char[strlen(base.m_pszData1) + 1])
	{
		strcpy(m_pszData1, base.m_pszData1);
		cout << "CBase(const CBase &)" << endl;
	}
	CBase & operator =(const CBase & base)
	{
		if(this != &base)
		{
			delete [] m_pszData1;
			m_pszData1 = new char[strlen(base.m_pszData1) + 1];
			strcpy(m_pszData1, base.m_pszData1);
		}
		cout << "CBase & operator =(const CBase &)" << endl;
		return *this;
	}
	~CBase()
	{
		delete [] m_pszData1;
		cout << "~CBase()" << endl;
	}

	void disp()
	{
		cout << m_pszData1;
	}
protected:
	char *m_pszData1;
};

class CDerived
: public CBase
{
public:
	CDerived()
	{
		cout << "CDerived()" << endl;
	}
	CDerived(const char *pszData1, const char *pszData2)
	: CBase(pszData1)
	, m_pszData2(new char[strlen(pszData2) + 1])
	{
		strcpy(m_pszData2, pszData2);
		cout << "CDerived(const char *, const char *)" << endl;
	}
	CDerived(const CDerived & derived)
	: CBase(derived)  //显示调用,这是，基类的复制构造函数，只执行基类的部分
	, m_pszData2(new char[strlen(derived.m_pszData2) + 1])
	{
		strcpy(m_pszData2, derived.m_pszData2);
		cout << "CDerived(const CDerived &)" << endl;
	}
	CDerived & operator =(const CDerived & derived)
	{
		if(this != &derived)
		{
			CBase::operator =(derived);  //显示调用
			m_pszData2 = new char[strlen(derived.m_pszData2) + 1];
			strcpy(m_pszData2, derived.m_pszData2);
		}
		cout << "CDerived & operator =(const CDerived & )" << endl;
		return *this;
	}
	~CDerived()
	{
		delete [] m_pszData2;
		cout << "~CDerived()" << endl;
	}
	
	void disp()
	{
		CBase::disp();
		cout << " " << m_pszData2 << endl;
	}

private:
	char *m_pszData2;
};

int main()
{
	CDerived d1("Hello!","world!");
	d1.disp();
	cout << endl;

	CDerived d2 = d1;  //派生类调用用户自定义的拷贝构造函数、基类不调用拷贝构造函数
	d2.disp();

	cout << endl;
	d1 = d2;  //派生类调用用户自定义的赋值操作、基类不调用重载的赋值运算符
	d1.disp();

	return 0;
}

