#include <chrono>

class TimingModule {
public:
    double MPI_wtime() const {
        using namespace std::chrono;
        auto current_time = high_resolution_clock::now();
        auto time_since_epoch = current_time.time_since_epoch();
        double time_in_seconds = duration_cast<duration<double>>(time_since_epoch).count();
        return time_in_seconds;
    }
};