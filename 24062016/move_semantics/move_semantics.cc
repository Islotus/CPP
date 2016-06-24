 ///
 /// @file    move_semantics.cc
 /// @author  Islotus(2791201278@qq.com)
 /// @date    2016-06-24 20:48:15
 ///

//移动语义--std::move  move sementics
//

//std::move
#include <iostream>


class MetaData
{
public:
	MetaData(int size, const std::string &name)
	:_name(name)
	,_size(size)
	{
		std::cout << "MetaData(int, const string &)" << std::endl;
	}

	MetaData(const MetaData &other)
	:_name(other._name)
	,_size(other._size)
	{
		std::cout << "MetaData(const MetaData &other)" << std::endl;
	}

	MetaData(MetaData &&other)
	//:_name(other._name)  //调用复制构造函数
	:_name(std::move(other._name))  //std::move将对象变成一个右值，但并不移动数据
	:_size(other._size)
	{
		std::cout << "MetaData(MetaData &&other)" << std::endl;
	}

	std::string getName() const
	{
		return _name;
	}

	int getSize() const
	{
		return _size;
	}

private:
	std::string _name;
	int _size;
};
 
class ArrayWrapper
{
public:
	ArrayWrapper()
	:_pVals(new int[64])
	,_metadata(64, "ArrayWrapper")
	{
		std::cout << "ArrayWrapper()" << std::endl;
	}

	ArrayWrapper(int n)
	:_pVals(new int[n])
	,_metadata(n, "ArrayWrapper")
	{
		std::cout << "ArrayWrapper(int)" << std::endl;
	}

	ArrayWrapper(const ArrayWrapper &other)
	:_pVals(new int[other._metadata.getSize()])
	,_metadata(other._metadata)
	{
		std::cout << "ArrayWrapper(const ArrayWrapper &other)" << std::endl;
		for(int idx = 0; idx != _size; ++idx)
		{
			_pVal[idx] = other._pVals[idx];
		}
	}

	ArrayWrapper(ArrayWrapper &&other)  //移动构造函数
	:_pVals(other._pVals)
	//,_metadata(other._metadata)  //调用MetaData的复制构造函数
	,_metadata(std::move(other._metadata))
	{
		std::cout << "ArrayWrapper(ArrayWrapper &&other)" << std::endl;
		other._pVals = NULL;
	}

	~ArrayWrapper()
	{
		delete [] _pVals;
	}
private:
	int* _pVals;
	MetaDate _metadata;
};

