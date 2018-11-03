/**
 * @file log.hpp
 * @brief Logging time
 * @ingroup pumas_and_hares
 */

#ifndef LOG_HPP
#define LOG_HPP

#include <iostream>
#include <string>
#include <time.h>
#include <chrono>
#include <map>

using namespace std;

typedef std::chrono::high_resolution_clock Clock;

/**
 * @class Log
 * @brief Logging execution time
 * @details Logs the execution time and exports logs
 */
class Log {
private:
    static map<string, Clock::time_point> startTime;
    static map<string, Clock::time_point> endTime;
public:
    static void startLogTime(string name);
    static void endLogTime(string name);
    static void exportLog(string name);
};

#endif
