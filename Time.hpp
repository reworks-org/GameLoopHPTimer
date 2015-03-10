//  Time.hpp
//
//  Free for public and private use. No credit required
//
//  Single header for everything. Just add to your project and away you go!

#ifndef __TIME__CHRONO__
#define __TIME__CHRONO__

#include <chrono>
#include <cstdint>

using namespace std::chrono; //to keep things clean. you can remove if you want, but prepare to have to add it to all the lines of code.

class ChronoWrapper
{
    //defines a type Chrono of namespace std::chrono::high_resolution_clock (nanosecond timer)
    typedef high_resolution_clock Chrono;
    
public:
    //returns the current system time in nanoseconds (use for gameloops over functions like SDL_GetTicks() ). This is the same as Java's System.nanoTime()
    std::uint64_t nanoTime()
    {
        //define type at compiletime. set it to the current system time
        auto curTime = Chrono::now();
        
        //get current time since epoch from curTime and return in nanoseconds
        return duration_cast<nanoseconds>(curTime.time_since_epoch()).count();
    }
    
    //returns time since 1970 in milliseconds. This is more accurate than <ctime>'s time() which returns in seconds. This is the same as Java's Date().getTime() or System.currentTimeMillis()
    std::uint64_t sysTimeMillis()
    {
        //get current time from system clock
        auto curTime = system_clock::now().time_since_epoch();
        
        //cast to milliseconds and return
        return duration_cast<milliseconds>(curTime).count();
    }
};

#endif