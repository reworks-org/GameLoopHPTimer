//
//	Time.hpp
//	A wrapper around std::chrono that can be used for high precision timers for gameloops
//

#pragma once

#include <chrono>
#include <cstdint>

using namespace std::chrono;

struct Time
{
	inline std::uint64_t nanoTime()
	{
		return duration_cast<nanoseconds>(high_resolution_clock::now().time_since_epoch()).count();
	}

	inline std::uint64_t sysTime()
	{
		return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
	}
} Time;