#pragma once

#include <iomanip>
#include <string>
#include <iostream>
#include <chrono>


#define __UNIQUE_ID_IMPL__(line) unique_var_ ## line
#define UNIQUE_ID(line) __UNIQUE_ID_IMPL__(line)

#define PROFILE(msg)    \
    Profiler UNIQUE_ID(__LINE__){msg};

//template<typename
class Profiler{
public:
    Profiler(const std::string &msg)
    : message(msg)
    , start_time(std::chrono::steady_clock::now())
    {
    }

    ~Profiler(){
        auto end_time = std::chrono::steady_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();

        std::cerr << message << ": " << duration <<" ms" << std::endl;
    }
private:
    std::chrono::steady_clock::time_point  start_time;
    std::string message;
};