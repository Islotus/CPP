 ///
 /// @file    TextQuery.h
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-07-04 20:02:52
 ///
 
#ifndef __TEXTQUERY_H__
#define __TEXTQUERY_H__

#include <string>
#include <set>
#include <map>
#include <vector>

class TextQuery
{
public:
	TextQuery();
	virtual ~TextQuery();
	typedef std::vector<std::string>::size_type line_no;
	/* interface:
	 * read_file builds internal data structures for the given file
	 * run_query finds the given word and teturns set of lines on which it appears
	 * text_line returns a requested line from the input file
	 */
	void read_file(std::ifstream &is)
	{
		store_file(is);
		build_map();
	}
	std::set<line_no> run_query(const std::string&) const;
	std::string text_line(line_no) const;
	line_no size() const
	{
		return lines_of_text.size();
	}
	void print_results(const std::set<TextQuery::line_no>&, const std::string&, const TextQuery&);
private:
	//utility functions used by read_file
	void store_file(std::ifstream&);  //store input file
	void build_map();  //associated each word with a set of line numbers
	//remember the whole input file
	std::vector<std::string> lines_of_text;
	//map word to set of the lines on which it occurs
	std::map<std::string, std::set<line_no> > word_map;
	static std::string cleanup_str(const std::string&);
	
};
//void print_results(const std::set<TestQuery::line_no>&, const std::string&, const TextQuery&);

#endif /* __TEXTQUERY_H__ */
 
