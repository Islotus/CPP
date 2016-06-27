 ///
 /// @file    sale_ticket.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-27 19:32:00
 ///

//完成“航空售票系统”的子模块“录入航班资料”
//要求：
//1.设计一个CFlight类，要求包含航班号，起飞城市，到达城市，航班距离，机票单价等信息。
//格式形如：FM9501 SZ SH 2300 1800
//2.进行航班信息的录入，要求航班号不能重复。
//3.选择一个合适的容器来保存所有的航班资料。
//4.尽量使用已学的C++知识而非C语言知识来做。

#include <iostream>
#include <string>
#include <string.h>
#include <set>
#include <iterator>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::set;
using std::ostream;
using std::ios;

//#pragme warning(disable : 4996)  //消除strcpy()的不安全警告

class CFlight
{
public:
	CFlight();  //默认构造函数

	//get()函数
	char* getFlightNo();
	char* getFromCity();
	char* getToCity();
	double getDistance();
	double getPrice();

	//set()函数
	void setFlightNo(char* p_szNo);
	void setFromCity(char* p_szFromCity);
	void setToCity(char* p_szToCity);
	void setDistance(double distance);
	void setPrice(double price);

	friend ostream & operator <<(ostream& os, const CFlight& other);  //输出运算符重载
	bool operator ==(const CFlight& other);  //比较运算符重载
	bool operator <(const CFlight& other) const;  //比较运算符重载

private:
	char m_flightNo[7];  //航班编号
	char m_fromCity[16];  //起飞城市
	char m_toCity[16];  //到达城市
	double m_distance;  //航线距离
	double m_price;  //机票单价

};

CFlight::CFlight()
{
	strcpy(this->m_flightNo, "");
	strcpy(this->m_fromCity, "");
	strcpy(this->m_toCity, "");
	this->m_distance = 0;
	this->m_price = 0;
}

char* CFlight::getFlightNo()
{
	return this->m_flightNo;
}

char* CFlight::getFromCity()
{
	return this->m_fromCity;
}

char* CFlight::getToCity()
{
	return this->m_toCity;
}

double CFlight::getDistance()
{
	return this->m_distance;
}

double CFlight::getPrice()
{
	return this->m_price;
}

void CFlight::setFlightNo(char* p_szNo)
{
	strcpy(this->m_flightNo, p_szNo);
}

void CFlight::setFromCity(char* p_szFromCity)
{
	strcpy(this->m_fromCity, p_szFromCity);
}

void CFlight::setToCity(char* p_szToCity)
{
	strcpy(this->m_toCity, p_szToCity);
}

void CFlight::setDistance(double distance)
{
	this->m_distance = distance;
}

void CFlight::setPrice(double price)
{
	this->m_price = price;
}

ostream& operator <<(ostream& os, const CFlight& other)
{
	os.setf(ios::left, ios::adjustfield);  //设置为左对齐
	os << " " << other.m_flightNo << "    ";
	os << other.m_fromCity << "    ";
	os << other.m_toCity << "    ";
	os << other.m_distance << "    ";
	os << other.m_price;
	return os;
}

bool CFlight::operator ==(const CFlight& other)
{
	return (strcmp(this->m_flightNo, other.m_flightNo) == 0);
}

bool CFlight::operator <(const CFlight& other) const
{
	return (strcmp(this->m_flightNo, other.m_flightNo) < 0);
}

void InputFlight(set<CFlight> & sf)
{
	char cChoose = '\0';
	cout << "请录入航班信息！" << endl;
	while(1)
	{
		CFlight flight;
		char flightNo[7] = {'\0'};
		char fromCity[16] = {'\0'};
		char toCity[16] = {'\0'};
		double distance = 0.0;
		double price = 0.0;
		cout << "请输入航班编号：";
		cin.clear();  //清除状态
		cin.sync();  //清除缓冲区
		cin >> flightNo;
		while(flightNo[0] == ' ')
			strcpy(flightNo, flightNo + 1);  //消除左边空格 trimLeft()  //这个方法不错
		if(strlen(flightNo) <= 0)
		{
			cout << "航班号不能为空，请重新输入！" << endl;
			continue;
		}
		cout << "请输入起飞城市: ";
		cin.clear();  //清除状态
		cin.sync();  //清除缓冲区
		cin >> fromCity;
		cout << "请输入到达城市：";
		cin.clear();  //清除状态
		cin.sync();  //清除缓冲区
		cin >> toCity;
		cout << "请输入航线距离：";
		cin >> distance;
		cout << "请输入机票价格：";
		cin >> price;
		flight.setFlightNo(flightNo);
		flight.setFromCity(fromCity);
		flight.setToCity(toCity);
		flight.setDistance(distance);
		flight.setPrice(price);
		if(sf.find(flight) != sf.end())
		{
			cout << "该航班已经存在了，请重新录入！" << endl;
			continue;
		}
		sf.insert(flight);
		cout << "录入航班成功！是否继续录入?(Y/N):";
		cin >> cChoose;
		if(cChoose != 'y' && cChoose != 'Y')
			break;
	}
}

void ShowAllFlight(set<CFlight>& sf)
{
	//输出所有航班信息
	cout << endl;
	cout << "\t\t< 航班信息如下 > " << endl;
	cout << "-----------------------------------------------" << endl;
	cout << "航班编号  " << "起飞城市  " << "到达城市  " << "航班距离  " << "机票单价  " << endl;
	set<CFlight>::iterator it;
	for(it = sf.begin(); it != sf.end(); ++it)
	{
		cout << *it << endl;
	}
	cout << "-----------------------------------------------" << endl;
}

int main()
{
	set<CFlight> sf;
	
	InputFlight(sf);

	ShowAllFlight(sf);

	return 0;
}
