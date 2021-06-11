#include "Storage.h"

template<>
void Storage<double>::print()
{
	cout << "Double Type ";
	cout << scientific << m_value << endl;
}