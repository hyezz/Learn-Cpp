#include <iostream>
#include <thread>
#include <atomic>
#include <mutex>
#include <chrono>

using namespace std;

mutex mtx;

int main()
{
	int shared_memory(0);
	// 1) atomic 변수 사용 (남용하면 퍼포먼스 속도 떨어짐)
	//atomic<int> shared_memory(0);

	auto count_func = [&]() {
		for (int i = 0; i < 1000; ++i)
		{
			// sleep_for 주석 처리하면 연산 속도가 빨라서 병렬 처리가 안됨
			this_thread::sleep_for(chrono::milliseconds(1));

			// 1) fetch_add() 사용
			//shared_memory.fetch_add(1);

			// 3) lock_guard() 사용 : scope 내에서 unlock 하지 않아도 됨
			//lock_guard lock(mtx);

			// 4) scoped_lock() 사용 : scope 벗어나면 unlock 됨 (C++ 17에서 lock_guard보다 더 선호)
			scoped_lock lock(mtx);

			// 2) mutex lock() 사용 (unlock 누락하지 않도록 주의)
			//mtx.lock();
			shared_memory++;	// ++는 atomic<int> 연산자 overloading
			//mtx.unlock();
		}
	};

	thread t1 = thread(count_func);
	thread t2 = thread(count_func);

	t1.join();
	t2.join();

	cout << "After" << endl;
	cout << shared_memory << endl;

	return 0;
}