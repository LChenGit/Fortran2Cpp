#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <cassert>

class TimeType {
public:
    int time;  // Simplifying Time_type as an integer for demonstration
    TimeType(int t = 0) : time(t) {}
    bool operator<(const TimeType& rhs) const { return time < rhs.time; }
    bool operator>(const TimeType& rhs) const { return time > rhs.time; }
    bool operator==(const TimeType& rhs) const { return time == rhs.time; }
};

class Config {
public:
    TimeType first_time;
    TimeType last_time;
    TimeType training_start;
    TimeType training_stop;
    TimeType transform_start;
    TimeType transform_stop;
};

class BaseDataType {
public:
    std::vector<TimeType> times;
    TimeType first_time;
    TimeType last_time;
    TimeType training_start;
    TimeType training_stop;
    TimeType transform_start;
    TimeType transform_stop;

    void setup_time_indices(const Config& options);
    static TimeType find_nearest_time(const std::vector<TimeType>& time_list, const TimeType& match_time);
};

void BaseDataType::setup_time_indices(const Config& options) {
    first_time = find_nearest_time(times, options.first_time);
    last_time = find_nearest_time(times, options.last_time);
    training_start = find_nearest_time(times, options.training_start);
    training_stop = find_nearest_time(times, options.training_stop);
    transform_start = find_nearest_time(times, options.transform_start);
    transform_stop = find_nearest_time(times, options.transform_stop);
}

TimeType BaseDataType::find_nearest_time(const std::vector<TimeType>& time_list, const TimeType& match_time) {
    TimeType nearest = time_list.front();
    int min_diff = std::abs(nearest.time - match_time.time);
    for (const auto& time : time_list) {
        int diff = std::abs(time.time - match_time.time);
        if (diff < min_diff) {
            nearest = time;
            min_diff = diff;
        }
    }
    return nearest;
}