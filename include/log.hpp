/**
 * @file log.hpp
 * @brief Logging time
 * @ingroup output
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
    /**
     * @brief start time
     */
    static map<string, Clock::time_point> startTime;
    /**
     * @brief end time
     */
    static map<string, Clock::time_point> endTime;
public:
    /**
     * @brief start logging time
     */
    static void startLogTime(string name);
    /**
     * @brief end logging time
     */
    static void endLogTime(string name);
    /**
     * @brief export Log
     */
    static void exportLog(string name);
};

#endif
