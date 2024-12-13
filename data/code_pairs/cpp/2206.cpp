#include <iostream>
#include <vector>
#include <algorithm>
#include <mpi.h>

using namespace std;

int check_results(const vector<int>& tmp) {
    int nerr = 0;
    for (int i = 1; i <= 10; ++i) { // Adjust loop to match Fortran 1-based indexing
        int ival = (i >= 2 && i <= 6) ? i * 3 : 0;
        if (tmp[i-1] != ival) { // Adjust index for C++ 0-based indexing
            cerr << "tmp(" << i << ")=" << tmp[i-1] << " should be " << ival << endl;
            nerr++;
        }
    }
    return nerr;
}

void simulate_parallel_function(int me, vector<int>& a1d1, vector<int>& tmp) {
    for (int i = 0; i < 10; ++i) {
        a1d1[i] = (i + 1) * me + std::max(-1, 0);
    }
    fill(tmp.begin(), tmp.end(), 0); // Ensure tmp is initialized to 0
    if (me == 1) {
        for (int i = 2; i <= 6; ++i) {
            tmp[i - 1] = a1d1[i - 1]; // Adjust index for C++ 0-based indexing
        }
    }
}

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int me;
    MPI_Comm_rank(MPI_COMM_WORLD, &me);

    vector<int> a1d1(10), tmp(10, 0);

    simulate_parallel_function(me, a1d1, tmp);

    int nerr = check_results(tmp);
    if (nerr == 0) {
        cout << "(" << me << ") OK" << endl;
    } else {
        cout << "(" << me << ") number of NGs: " << nerr << endl;
    }

    MPI_Finalize();
    return 0;
}