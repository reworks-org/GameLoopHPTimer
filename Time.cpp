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
    std::uint64_t nanos = duration_cast<nanoseconds>(curTime.time_since_epoch()).count();
    
    //return value
    return nanos;
}

std::uint64_t ChronoWrapper::epochTimeMillis()
{
    //get current time
    auto curTime  = system_clock::now();
    
    //get time since epoch
    auto since_epoch = curTime.time_since_epoch();
    
    //auto define millis type then retrive casted data
    auto millis = duration_cast<milliseconds>(since_epoch);
    
    //return in milliseconds
    return millis.count();
}