//  Time.cpp
//
//  Free for public and private use. No credit required
//
//  Implements the functions

#include "Time.h"

using namespace std::chrono; //keeps things more tidy

std::uint64_t ChronoWrapper::sysTime()
{
    //define type at compiletime. set it to the current system time
    auto curTime = Chrono::now();
    
    //get current time since epoch from curTime and return in nanoseconds
    return duration_cast<nanoseconds>(curTime.time_since_epoch()).count();
}

std::uint64_t ChronoWrapper::epochTimeMillis()
{
    //get current time from system clock
    auto curTime  = system_clock::now();
    
    //get time since epoch (1970)
    auto since_epoch = curTime.time_since_epoch();
    
    //cast to milliseconds and return
    return duration_cast<milliseconds>(since_epoch).count();
}