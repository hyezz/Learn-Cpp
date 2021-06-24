#include <iostream>
#include <memory>
#include <string>

using namespace std;

class Person
{
	// Person 자체가 shared_ptr로 되어 있을 때, Person을 지우려고 하면 m_partner도 지우려고 한다.
	// 그런데 m_partner가 shared_ptr로 카운트 되기 때문에 소유권이 순환되어 지울 수 없음
	string m_name;
	//shared_ptr<Person> m_partner;
	weak_ptr<Person> m_partner;

public:
	Person(const string& name) : m_name(name)
	{
		cout << m_name << " created\n";
	}

	~Person()
	{
		cout << m_name << " destoryed\n";
	}

	friend bool partnerUp(shared_ptr<Person>& p1, shared_ptr<Person>& p2)
	{
		if (!p1 || !p2)
			return false;

		p1->m_partner = p2;
		p2->m_partner = p1;

		cout << p1->m_name << " is partnered with " << p2->m_name << "\n";

		return true;
	}

	const shared_ptr<Person> getPartner() const
	{
		//weak pointer 의 내용물을 사용할 때 lock 을 해줘야 함
		//lock() 호출하면 shared_ptr 로 바꿔서 리턴
		return m_partner.lock();
	}

	const string& getName() const
	{
		return m_name;
	}
};

int main()
{
	auto lucy = make_shared<Person>("Lucy");
	auto ricky = make_shared<Person>("ricky");

	partnerUp(lucy, ricky);

	cout << lucy->getPartner()->getName() << endl;

	return 0;
}