#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <vector>
#include <mutex>

using namespace std;

mutex mtx;	// mutual exclusion

int main()
{
	auto work_func = [](const string& name)
	{
		for (int i = 0; i < 5; ++i)
		{
			this_thread::sleep_for(chrono::milliseconds(100));

			mtx.lock();	// 다른 thread 못 들어오게 막음
			cout << name << " " << this_thread::get_id() << " is working " << i << endl;
			mtx.unlock();	// unlock 빼먹으면 문제 생김
		}
	};

	thread t1 = thread(work_func, "JackJack");
	thread t2 = thread(work_func, "Dash");

	t1.join();
	t2.join();

	return 0;
}