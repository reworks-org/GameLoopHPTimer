Small wrapper around std::chrono that implements some needed functions more easily. It basically emulates javas System.NanoTime() and System.GetTimeMillis()

Note: Requires a C++11 compliant compiler that supports <chrono> and the 'auto' typedef.