#include <iostream>
#include <memory>
#include "Resource.h"

auto doSomething()
{
	//return std::unique_ptr<Resource>(new Resource(5));
	return std::make_unique<Resource>(5);	// ���������� move semantics ���
}

//void doSomething2(std::unique_ptr<Resource>& res)
void doSomething2(std::unique_ptr<Resource> res)
{
	res->setAll(100);
	res->print();
}

auto doSomething3(std::unique_ptr<Resource> res)
{
	res->setAll(100);
	res->print();

	return res;
}

void doSomething4(Resource* res)
{
	res->setAll(100);
	res->print();
}

int main()
{
	{
		// �ڵ����� �Ҹ��� ȣ��
		std::unique_ptr<Resource> res(new Resource(10000000));
	}

	{
		std::unique_ptr<int> upi(new int);	// �⺻ �ڷ������� ��� ����

		// ���� �Ҵ�� �޸��� �����͸� �Ķ���ͷ� ���� �� ����
		//auto* ptr = new Resource(5);
		//std::unique_ptr<Resource> res1(ptr);

		//std::unique_ptr<Resource> res1(new Resource(5));
		
		// std::make_unique<Resource>�� Resource�� ��ó�� ���� (����)
		auto res1 = std::make_unique<Resource>(5);
		
		// �Լ��κ��� �޴� ���
		//auto res1 = doSomething();

		res1->setAll(5);
		res1->print();

		std::unique_ptr<Resource> res2;

		std::cout << std::boolalpha;
		std::cout << static_cast<bool>(res1) << std::endl;
		std::cout << static_cast<bool>(res2) << std::endl;

		//res2 = res1;	// unique_ptr�� ���� ���� (copy semantics �Ұ���)
		res2 = std::move(res1);		// move semantics ����

		std::cout << std::boolalpha;
		std::cout << static_cast<bool>(res1) << std::endl;
		std::cout << static_cast<bool>(res2) << std::endl;

		// unique_ptr �� member operator ��� ����
		if (res1 != nullptr) res1->print();
		if (res2 != nullptr) res2->print();	// (*res2).print()
	}

	{
		auto res1 = std::make_unique<Resource>(5);
		res1->setAll(1);
		res1->print();

		std::cout << std::boolalpha;
		std::cout << static_cast<bool>(res1) << std::endl;

		// doSomething2() �Ķ���͸� l-value ref���� �׳� value�� �ٲٸ� compile error �߻�
		//doSomething2(res1);

		// doSomething2() scope �����鼭 res1 destroyed
		//doSomething2(std::move(res1));

		// �Լ��� �������� ��ٰ� �ٽ� ��������
		//res1 = doSomething3(std::move(res1));

		// get() : unique_ptr�� ���������� ������ �ִ� Resource�� �����͸� �������� �Լ�
		doSomething4(res1.get());
		
		std::cout << std::boolalpha;
		std::cout << static_cast<bool>(res1) << std::endl;

		res1->print();
	}

	{
		Resource* res = new Resource;
		std::unique_ptr<Resource> res1(res);

		// 1) �� ������ �������� �ָ� �ȵ�
		//std::unique_ptr<Resource> res2(res);

		// 2) ������ �޸𸮸� �� ������� �ϸ� �ȵ�
		//delete res;
	}

	return 0;
}