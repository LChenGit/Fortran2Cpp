#include <iostream>

bool isFinalized = false; // Global variable to track finalization status.

void ROMS_finalize() {
    // Simulate some finalization logic.
    isFinalized = true;
    std::cout << "ROMS_finalize called, environment finalized." << std::endl;
}

void abort(int status) {
    ROMS_finalize();
    std::exit(status);
}