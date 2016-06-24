 ///
 /// @file    copy_on_write.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-24 20:00:54
 ///

//std::string -感性认识
//通过一段代码来看string类的copy-on-write的表面特征

#include <iostream>
#include <string>
#include <stdio.h>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	string str1 = "hello,world";
	string str2 = str1;

	printf("Sharing the memory:\n");
	printf("\tstr1's address: %p\n",str1.c_str());
	printf("\tstr2's address: %p\n",str2.c_str());

	str1[1] = 'q';
	str2[2] = 'w';

	printf("After Copy-On-Write: \n");
	printf("\tstr1's address: %p\n",str1.c_str());
	printf("\tstr2's address: %p\n",str2.c_str());

	return 0;
}
