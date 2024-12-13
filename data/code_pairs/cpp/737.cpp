#include <vector>

void FIND(const std::vector<int>& ibuffer, int ib, int nini, int ntot, int ip, int& iat) {
    int ipx = 0;
    // Note: Adjusting for C++ 0-based indexing in the loop
    for (iat = nini; iat < ntot; ++iat) {
        if (ibuffer[iat - 1] == ib) { // Adjusted index for 0-based array
            ++ipx;
            if (ip == ipx) {
                return; // Exiting the function if the condition is met
            }
        }
    }
    iat = -1; // Indicates not found or condition not met
}