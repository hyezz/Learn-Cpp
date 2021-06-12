#include <iostream>
#include <array>
#include "Storage8.h"

using namespace std;

int main()
{
	// Define a Storage8 for integers
	Storage8<int> intStorage;

	for (int count = 0; count < 8; ++count)
		intStorage.set(count, count);

	for (int count = 0; count < 8; ++count)
		cout << intStorage.get(count) << '\n';

	cout << "Sizeof Storage8<int> " << sizeof(Storage8<int>) << endl;
		
	// Define a Storage8 for bool
	Storage8<bool> boolStorage;

	for (int count = 0; count < 8; ++count)
		boolStorage.set(count, count);

	for (int count = 0; count < 8; ++count)
		cout << boolStorage.get(count) << '\n';

	// specialization �ϸ� 1 Byte, ���ϸ� 8 Byte ��� (ȿ����)
	cout << "Sizeof Storage8<bool> " << sizeof(Storage8<bool>) << endl;

	return 0;
}