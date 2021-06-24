#include <iostream>
#include <memory>
#include <string>

using namespace std;

class Person
{
	// Person ��ü�� shared_ptr�� �Ǿ� ���� ��, Person�� ������� �ϸ� m_partner�� ������� �Ѵ�.
	// �׷��� m_partner�� shared_ptr�� ī��Ʈ �Ǳ� ������ �������� ��ȯ�Ǿ� ���� �� ����
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
		//weak pointer �� ���빰�� ����� �� lock �� ����� ��
		//lock() ȣ���ϸ� shared_ptr �� �ٲ㼭 ����
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