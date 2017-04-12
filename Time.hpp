//
//	Time.hpp
//	Two functions that can be used for high precision timers for gameloops
//

#ifndef HP_TIMERFUNCS_HPP_
#define HP_TIMERFUNCS_HPP_

#include <chrono>
#include <cstdint>

namespace Timee
{
	inline std::uint64_t nanoTime()
	{
		return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count();
	}

	inline std::uint64_t sysTime()
	{
		return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
	}
}

#endif