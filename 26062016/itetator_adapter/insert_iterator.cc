 ///
 /// @file    insert_iterator.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-26 19:50:10
 ///

//插入迭代器适配器 insert iterator adapter

#include <iostream>
#include <vector>
#include <list>
#include <iterator>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::list;
using std::back_insert_iterator;
using std::front_insert_iterator;
using std::insert_iterator;


template<typename T>
void PrintElements(T c)
{
	typename T::const_iterator itr = c.begin();
	while(itr != c.end())
	{
		cout << *itr++ << " ";
	}
}

int main()
{
	vector<int> vecSrc;
	list<int> vecDest;

	for(vector<int>::size_type i = 0; i < 3; ++i)
	{
		vecSrc.push_back(i);
	}

	cout << "vector<int> vecDest:" << endl;
	PrintElements(vecSrc);
	cout << endl;
	
	cout << "back_insert_iterator<list<int> >(vecDest)):" << endl;
	copy(vecSrc.begin(), vecSrc.end(), back_insert_iterator<list<int> >(vecDest));
	PrintElements(vecDest);
	cout << endl;
	
	cout << "front_insert_iterator<list<int> >(vecDest)):" << endl;
	copy(vecSrc.begin(), vecSrc.end(), front_insert_iterator<list<int> >(vecDest));
	PrintElements(vecDest);
	cout << endl;

	cout << "insert_iterator<list<int> >(vecDest)):" << endl;
	copy(vecSrc.begin(), vecSrc.end(), insert_iterator<list<int> >(vecDest, ++vecDest.begin()));
	PrintElements(vecDest);
	cout << endl;

	return 0;
}
