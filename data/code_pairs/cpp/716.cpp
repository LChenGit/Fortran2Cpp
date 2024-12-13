#include <mpi.h>
#include <iostream>

class MpiTools {
public:
    int rank, mpi_size, ierror;

    MpiTools() : rank(0), mpi_size(0), ierror(0) {}

    void start_parallel() {
        MPI_Init(nullptr, nullptr);
        MPI_Comm_rank(MPI_COMM_WORLD, &rank, &ierror);
        MPI_Comm_size(MPI_COMM_WORLD, &mpi_size, &ierror);
    }

    void end_parallel() {
        MPI_Finalize();
    }
};

int main() {
    MpiTools mpiTools;

    mpiTools.start_parallel();
    std::cout << "Process Rank: " << mpiTools.rank << std::endl;
    std::cout << "Total Number of Processes: " << mpiTools.mpi_size << std::endl;
    mpiTools.end_parallel();

    return 0;
}