 ///
 /// @file    main.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-07-04 20:41:29
 ///

#include "TextQuery.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	TextQuery tq;
	ifstream fin("china_daily.txt");
	tq.read_file(fin);
	while(true)
	{
		cout << "enter the word to look for, or q to exit: ";
		string s;
		cin >> s;
		if (s == "q") break;
		set<TextQuery::line_no> locs = tq.run_query(s);
		tq.print_results(locs, s, tq);
	}
}
 
