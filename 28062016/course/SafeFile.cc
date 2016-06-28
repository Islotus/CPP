 ///
 /// @file    SafeFile.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-28 20:15:36
 ///

#include <stdio.h>
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

class SafeFile
{
public:
	SafeFile(const string & filename)
	:_fp(fopen(filename.c_str(), "w+"))
	{
		if(NULL == _fp)
		{
			cout << "FILE open error" << endl;
		}
	}

	~SafeFile()
	{
		if(_fp != NULL)
		{
			fclose(_fp);
			cout << "fclose(_fp)" << endl;
		}
	}

	void write(const char* str)
	{
		if(fputs(str, _fp) == EOF)
		{
			cout << "write error!" << endl;
		}
	}

	void write(const char* buf, size_t num)
	{
		if(num != 0 && fwrite(buf, num, 1, _fp) == 0)
		{
			cout << "write error!" << endl;
		}
	}

private:
	SafeFile(const SafeFile & rhs);  //禁止复制构造
	SafeFile & operator =(const SafeFile & rhs);  //禁止赋值
private:
	FILE* _fp;
};

int main()
{
	SafeFile sf("test.dat");

	sf.write("hello,world");

	return 0;
}

