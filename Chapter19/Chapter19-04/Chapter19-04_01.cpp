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
	// 1) atomic ���� ��� (�����ϸ� �����ս� �ӵ� ������)
	//atomic<int> shared_memory(0);

	auto count_func = [&]() {
		for (int i = 0; i < 1000; ++i)
		{
			// sleep_for �ּ� ó���ϸ� ���� �ӵ��� ���� ���� ó���� �ȵ�
			this_thread::sleep_for(chrono::milliseconds(1));

			// 1) fetch_add() ���
			//shared_memory.fetch_add(1);

			// 3) lock_guard() ��� : scope ������ unlock ���� �ʾƵ� ��
			//lock_guard lock(mtx);

			// 4) scoped_lock() ��� : scope ����� unlock �� (C++ 17���� lock_guard���� �� ��ȣ)
			scoped_lock lock(mtx);

			// 2) mutex lock() ��� (unlock �������� �ʵ��� ����)
			//mtx.lock();
			shared_memory++;	// ++�� atomic<int> ������ overloading
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