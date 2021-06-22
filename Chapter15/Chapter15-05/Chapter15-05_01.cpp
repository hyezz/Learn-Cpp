#include <iostream>
#include <memory>
#include "Resource.h"

auto doSomething()
{
	//return std::unique_ptr<Resource>(new Resource(5));
	return std::make_unique<Resource>(5);	// 내부적으로 move semantics 사용
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
		// 자동으로 소멸자 호출
		std::unique_ptr<Resource> res(new Resource(10000000));
	}

	{
		std::unique_ptr<int> upi(new int);	// 기본 자료형에도 사용 가능

		// 동적 할당된 메모리의 포인터를 파라미터로 받을 수 있음
		//auto* ptr = new Resource(5);
		//std::unique_ptr<Resource> res1(ptr);

		//std::unique_ptr<Resource> res1(new Resource(5));
		
		// std::make_unique<Resource>가 Resource인 것처럼 생성 (권장)
		auto res1 = std::make_unique<Resource>(5);
		
		// 함수로부터 받는 경우
		//auto res1 = doSomething();

		res1->setAll(5);
		res1->print();

		std::unique_ptr<Resource> res2;

		std::cout << std::boolalpha;
		std::cout << static_cast<bool>(res1) << std::endl;
		std::cout << static_cast<bool>(res2) << std::endl;

		//res2 = res1;	// unique_ptr은 복사 못함 (copy semantics 불가능)
		res2 = std::move(res1);		// move semantics 가능

		std::cout << std::boolalpha;
		std::cout << static_cast<bool>(res1) << std::endl;
		std::cout << static_cast<bool>(res2) << std::endl;

		// unique_ptr 도 member operator 사용 가능
		if (res1 != nullptr) res1->print();
		if (res2 != nullptr) res2->print();	// (*res2).print()
	}

	{
		auto res1 = std::make_unique<Resource>(5);
		res1->setAll(1);
		res1->print();

		std::cout << std::boolalpha;
		std::cout << static_cast<bool>(res1) << std::endl;

		// doSomething2() 파라미터를 l-value ref에서 그냥 value로 바꾸면 compile error 발생
		//doSomething2(res1);

		// doSomething2() scope 끝나면서 res1 destroyed
		//doSomething2(std::move(res1));

		// 함수에 소유권을 줬다가 다시 돌려받음
		//res1 = doSomething3(std::move(res1));

		// get() : unique_ptr가 내부적으로 가지고 있는 Resource의 포인터를 가져오는 함수
		doSomething4(res1.get());
		
		std::cout << std::boolalpha;
		std::cout << static_cast<bool>(res1) << std::endl;

		res1->print();
	}

	{
		Resource* res = new Resource;
		std::unique_ptr<Resource> res1(res);

		// 1) 두 군데에 소유권을 주면 안됨
		//std::unique_ptr<Resource> res2(res);

		// 2) 지워진 메모리를 또 지우려고 하면 안됨
		//delete res;
	}

	return 0;
}