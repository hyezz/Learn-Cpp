#include <iostream>
#include <string>

using namespace std;

class Animal
{
protected:
	string m_name;

public:
	Animal(string name)
		: m_name(name)
	{}

public:
	string getName() { return m_name; }

	// pure virtual function
	virtual void speak() const = 0;
};

// the body of the pure virtual function : 구현해봤자 호출할 수 없음
/*void Animal::speak() const
{
	cout << m_name << " ??? " << endl;
}*/

class Cat : public Animal
{
public:
	Cat(string name)
		: Animal(name)
	{}

	void speak() const
	{
		cout << m_name << " Meow " << endl;
	}
};

class Dog : public Animal
{
public:
	Dog(string name)
		: Animal(name)
	{}

	void speak() const
	{
		cout << m_name << " Woof " << endl;
	}
};

class Cow : public Animal
{
public:
	Cow(string name)
		: Animal(name)
	{}
};

//int main()
//{
//	// compile error : 추상 클래스는 인스턴스 만들 수 없다
//	//Animal ani("Hi");
//
//	// compile error : speak() 구현해야 한다
//	//Cow cow("hello");
//
//	return 0;
//}