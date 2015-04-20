//
//	Time.hpp
//	A class around std::chrono that can be used for high precision timers for gameloops
//

#pragma once

#include <chrono>
#include <cstdint> //std::uint64_t

using namespace std;
using namespace chrono;

class ChronoTime {
public:
	inline uint64_t nanoTime()
	{
		return duration_cast<nanoseconds>(high_resolution_clock::now().time_since_epoch()).count();
	}

	inline uint64_t sysTime()
	{
		return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
	}
};