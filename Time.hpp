//  Time.hpp
//
//  Free for public and private use. No credit required
//
//  Single header for everything. Just add to your project and away you go!

//inclusion guards. use #pragma once if you prefer that...
#ifndef __TIME__CHRONO__
#define __TIME__CHRONO__

#include <chrono>
#include <cstdint>

using namespace std::chrono; //to keep things clean. you can remove if you want, but prepare to have to add it to all the lines of code.

class ChronoWrapper //rename this if you want. i couldnt think of anything better.
{
    //defines a type Chrono of namespace std::chrono::high_resolution_clock (nanosecond timer)
    typedef high_resolution_clock HRC;
    typedef system_clock SC; //also adds this if your using chrono for other things aswell.
    
public:
    //we use an unsigned 64bit integer because its the largest interger to use for storing these huge numbers
    //returns the current system time in nanoseconds (use for gameloops over functions like SDL_GetTicks() ). This is the same as Java's System.nanoTime()
    inline std::uint64_t nanoTime()
    {
        //get current time since epoch from curTime and return in nanoseconds
        return duration_cast<nanoseconds>(HRC::now().time_since_epoch()).count();
    }
    
    //returns time since 1970 in milliseconds. This is more accurate than <ctime>'s time() which returns in seconds. This is the same as Java's Date().getTime() or System.currentTimeMillis()
    inline std::uint64_t sysTimeMillis()
    {
        //cast to milliseconds and return
        return duration_cast<milliseconds>(SC::now().time_since_epoch()).count();
    }
};

#endif