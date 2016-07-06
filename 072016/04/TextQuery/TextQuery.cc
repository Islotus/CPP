 ///
 /// @file    TestQuery.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-07-04 20:18:07
 ///

#include "TextQuery.h"
#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <fstream>
#include <stdexcept>
#include <cctype>

using namespace std;

TextQuery::TextQuery()
{ //TODO Auto-generated constructor stub

}

TextQuery::~TextQuery()
{ //TODO Auto-generated destructor stub

}

void TextQuery::store_file(ifstream &is)
{ //read input file: store each line as element in lines_of_text
	string textline;
	while(getline(is, textline))
		lines_of_text.push_back(textline);
}

void TextQuery::build_map()
{ //process each line from the input vector
	for(line_no n = 0; n != lines_of_text.size(); ++n)
	{ //we'll use line to read the text a word at a time
		istringstream line(lines_of_text[n]);
		string word;
		while(line >> word)
			// add this number to the set;
			// subscript will add word to the map if it's not already there
			word_map[cleanup_str(word)].insert(n);
	}
}
 
set<TextQuery::line_no> TextQuery::run_query(const string &query_word) const
{ // note: must use find and not subscript the map directly
	// to avoid adding words to word_map!
	map<string, set<line_no> >::const_iterator it = word_map.find(cleanup_str(query_word));
	if (it == word_map.end())
		return set<line_no> ();  //not found, return empty set
	else
		return it->second;
}

string TextQuery::text_line(line_no line) const
{
	if (line <lines_of_text.size())
		return lines_of_text[line];
	throw std::out_of_range("line number out of range");
}

string TextQuery::cleanup_str(const string &word)
{
	string ret;
	for (string::const_iterator it = word.begin(); it != word.end(); ++it)
	{
		if (!ispunct(*it))
			ret += tolower(*it);
	}
	return ret;
}

////////////////////////////////////////////////////////////
void TextQuery::print_results(const set<TextQuery::line_no> &locs, const string &sought, const TextQuery &file)
{ // if the word was found, then print count and all occurrences
	typedef set<TextQuery::line_no> line_nums;
	line_nums::size_type size = locs.size();
	cout << "Executed Query for: " << sought << endl;
	cout << "match occurs " << size << " " << (size > 1 ? "times" : "time") << endl;

	// print each line in which the word appeared
	line_nums::const_iterator it = locs.begin();
	for (; it != locs.end(); ++it)
	{
		cout << "(line"
			// don't confound user with text lines starting at 0
			<< (*it) + 1 << ")" << file.text_line(*it) << endl;
	}
}

