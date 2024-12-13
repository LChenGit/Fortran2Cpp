#ifndef XCLIB_UTILS_AND_PARA_H
#define XCLIB_UTILS_AND_PARA_H

// Assuming MPI is needed, include the appropriate MPI header.
// If you're not using MPI, you can comment out or remove these lines.
#ifdef __MPI
    #ifdef __MPI_MODULE
        #include <mpi.h>
    #else
        extern "C" {
            #include "mpif.h"
        }
    #endif
#else
    // Define MPI constants if MPI is not enabled
    const int MPI_COMM_WORLD = 0;
    const int MPI_COMM_NULL = -1;
    const int MPI_COMM_SELF = -2;
#endif

// Define stdout and nowarning within the file
const int stdout_fd = 6;
bool nowarning = false;

#endif // XCLIB_UTILS_AND_PARA_H