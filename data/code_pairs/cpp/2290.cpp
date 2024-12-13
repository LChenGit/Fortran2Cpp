#ifndef CLOCK_HPP
#define CLOCK_HPP

#include <chrono>

class Clock {
public:
    Clock() : elapsed_time(0.0) {}

    void start() {
        start_time = std::chrono::high_resolution_clock::now();
    }

    void stop() {
        auto stop_time = std::chrono::high_resolution_clock::now();
        elapsed_time = std::chrono::duration<double>(stop_time - start_time).count();
    }

    double getElapsedTime() const {
        return elapsed_time;
    }

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start_time;
    double elapsed_time;
};

#endif // CLOCK_HPP