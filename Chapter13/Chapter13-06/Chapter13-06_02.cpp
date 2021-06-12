#include <iostream>

using namespace std;

template<class T, int size>
class StaticArray_BASE
{
private:
	T m_array[size];

public:
	T* getArray() { return m_array; }

	T& operator[] (int index)
	{
		return m_array[index];
	}

	// member function으로 이동
	void print()
	{
		for (int count = 0; count < size; ++count)
			cout << (*this)[count] << ' ';
		cout << endl;
	}
};

// member function은 specialization하기 어렵기 때문에 상속 사용
template<class T, int size>
class StaticArray : public StaticArray_BASE<T, size>
{
};

template<int size>
class StaticArray<char, size> : public StaticArray_BASE<char, size>
{
public:
	// override
	void print()
	{
		for (int count = 0; count < size; ++count)
			cout << (*this)[count];
		cout << endl;
	}
};

int main()
{
	StaticArray<int, 4> int4;
	int4[0] = 1;
	int4[1] = 2;
	int4[2] = 3;
	int4[3] = 4;

	int4.print();

	StaticArray<char, 14> char14;
	char14[0] = 'H';
	char14[1] = 'e';

	strcpy_s(char14.getArray(), 14, "Hello, World");

	char14.print();

	return 0;
}