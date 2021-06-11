#pragma once
#include <iostream>

using namespace std;

template <class T>
class Storage
{
private:
	T m_value;

public:
	Storage(T value)
	{
		m_value = value;
	}

	~Storage()
	{
	}

	void print()
	{
		cout << m_value << endl;
	}
};

// 헤더에 포함시키는 경우 많음
//template<>
//void Storage<double>::print()
//{
//	cout << "Double Type ";
//	cout << scientific << m_value << endl;
//}