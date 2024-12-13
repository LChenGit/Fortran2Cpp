#include <iostream>

#define MPI_COMM_WORLD 0
typedef int MPI_Comm;
typedef int MPI_Datatype;
const MPI_Datatype MPI_INT = 1;
const MPI_Datatype MPI_FLOAT = 2;
const int MPI_SUCCESS = 0;

// Mock MPI function declarations
int MPI_Init(int *argc, char ***argv) {
    std::cout << "MPI_Init called (mock)" << std::endl;
    return MPI_SUCCESS;
}

int MPI_Finalize() {
    std::cout << "MPI_Finalize called (mock)" << std::endl;
    return MPI_SUCCESS;
}

int MPI_Comm_rank(MPI_Comm comm, int *rank) {
    *rank = 0; // In a mock environment, always the "rank 0"
    std::cout << "MPI_Comm_rank called (mock)" << std::endl;
    return MPI_SUCCESS;
}

int MPI_Comm_size(MPI_Comm comm, int *size) {
    *size = 1; // In a mock environment, always "size 1"
    std::cout << "MPI_Comm_size called (mock)" << std::endl;
    return MPI_SUCCESS;
}

// Example test program using mock MPI
int main(int argc, char* argv[]) {
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    std::cout << "Rank: " << rank << ", Size: " << size << std::endl;

    MPI_Finalize();
    return 0;
}