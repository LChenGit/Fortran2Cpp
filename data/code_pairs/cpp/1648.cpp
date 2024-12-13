#include <cstdlib> // For std::exit
#include "io_files.h" // Assumed header for file handling
#include "mp.h"       // Assumed header for MPI functionalities
#include "mp_global.h" // Assumed header for global MPI functionalities
#include "mp_world.h"  // Assumed header for MPI world communication

#ifdef __MPI
#include <mpi.h>
#endif

void stop_pp() {
#ifdef __MPI
    // Assuming closeFileIfNeeded is a function that checks if the file is open and closes it
    closeFileIfNeeded(iunwfc); // This is pseudo-code; replace with your actual implementation
    
    // Assumed MPI barrier and global end functionalities
    mp::mp_barrier(mp_world::world_comm);
    mp_global::mp_global_end();
#endif

    std::exit(0); // Terminates the program
}