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

// ����� ���Խ�Ű�� ��� ����
//template<>
//void Storage<double>::print()
//{
//	cout << "Double Type ";
//	cout << scientific << m_value << endl;
//}