#pragma once
#include<iostream>
#include<chrono>

using namespace std;

class Timer
{
	using clock_t = chrono::high_resolution_clock;
	using second_t = chrono::duration<double, ratio<1>>;

	chrono::time_point<clock_t> start_time = clock_t::now();

public:
	double elapsed()
	{
		chrono::time_point<clock_t> end_time = clock_t::now();

		return chrono::duration_cast<second_t>(end_time - start_time).count();
	}
};