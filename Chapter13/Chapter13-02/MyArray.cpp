#include "MyArray.h"

template<typename T>
void MyArray<T>::print()
{
	for (int i = 0; i < m_length; ++i)
		std::cout << m_data[i] << " ";
	std::cout << std::endl;
}

// explicit instantiation (link error 방지, 함수/클래스 단위)
template class MyArray<char>;
template class MyArray<double>;
//template void MyArray<char>::print();
//template void MyArray<double>::print();