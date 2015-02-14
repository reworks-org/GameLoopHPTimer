//  Time.h
//
//  Free for public and private use. No credit required
//
//  Defines the class and functions

#ifndef __CHRONO__WRAPPER__Timer__
#define __CHRONO__WRAPPER__Timer__

#include <chrono>
#include <cstdint>

class ChronoWrapper
{
    //defines a type Chrono of namespace std::chrono::high_resolution_clock
    typedef std::chrono::high_resolution_clock Chrono;
    
public:
    //returns the current system time in nanoseconds (use for gameloops over functions like SDL_GetTicks() ). This is the same as Java's System.nanoTime()
    std::uint64_t sysTime();
    
    //returns time since 1970 in milliseconds. This is more accurate than <ctime>'s time() which returns in seconds. This is the same as Java's Date().getTime() or System.currentTimeMillis()
    std::uint64_t epochTimeMillis();
    
    //More to come
    
};

#endif