// SETUP_EXACT_UNDOING_TO_DISK__genmod.h
#pragma once

namespace SETUP_EXACT_UNDOING_TO_DISK__genmod {
    extern bool setupDone; // Declaration
    
    void SETUP_EXACT_UNDOING_TO_DISK();
}

// SETUP_EXACT_UNDOING_TO_DISK__genmod.cpp
#include "SETUP_EXACT_UNDOING_TO_DISK__genmod.h"

namespace SETUP_EXACT_UNDOING_TO_DISK__genmod {
    bool setupDone = false; // Definition
    
    void SETUP_EXACT_UNDOING_TO_DISK() {
        setupDone = true;
    }
}