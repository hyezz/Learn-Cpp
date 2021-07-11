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
	const int num_pro = std::thread::hardware_concurrency();

	// main function 실행되는 thread ID
	cout << std::this_thread::get_id() << endl;

	//std::thread t1 = std::thread([]() {
	//	cout << std::this_thread::get_id() << endl;
	//	while (true) {}});

	//std::thread t2 = std::thread([]() {
	//	cout << std::this_thread::get_id() << endl;
	//	while (true) {}});

	//std::thread t3 = std::thread([]() {
	//	cout << std::this_thread::get_id() << endl;
	//	while (true) {}});

	//std::thread t4 = std::thread([]() {
	//	cout << std::this_thread::get_id() << endl;
	//	while (true) {}});

	//t1.join();	// t1 끝날 때까지 기다림 (join 없으면 자식 thread 끝나기 전에 main thread 끝나서 에러 생김)
	//t2.join();
	//t3.join();
	//t4.join();

	vector<thread> my_threads;
	my_threads.resize(num_pro);

	for(auto& e : my_threads)
		e = std::thread([]() {
			cout << std::this_thread::get_id() << endl;
			while (true) {}});

	for (auto& e : my_threads)
		e.join();

	return 0;
}