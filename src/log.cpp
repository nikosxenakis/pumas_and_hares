#include "../include/log.hpp"

map<string, Clock::time_point> Log::startTime;
map<string, Clock::time_point> Log::endTime;

void Log::startLogTime(string name) {
    Log::startTime[name] = Clock::now();
}

void Log::endLogTime(string name) {
    Log::endTime[name] = Clock::now();
    Log::exportLog(name);
}

void Log::exportLog(string name) {
    cout << "Running time for " << name <<": " << chrono::duration_cast<chrono::milliseconds>(Log::endTime[name] - Log::startTime[name]).count() << " milliseconds" << endl;
}
