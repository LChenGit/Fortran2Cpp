#include <iostream>
#include <cassert>

// Assuming the maximum dimensions are known. Adjust these values as necessary.
const int maxnspec = 10; // Example value, adjust as needed
const int maxspecdim = 10; // Example value, adjust as needed
const int maxpnts = 10; // Example value, adjust as needed

double spec_min(double spec[maxnspec][maxspecdim][maxpnts], int nspec, int nchannel, int npnts) {
    nspec -= 1; // Adjust for zero-based indexing
    nchannel -= 1; // Adjust for zero-based indexing
    
    double min_val = spec[nspec][nchannel][0];
    for (int i = 1; i < npnts; ++i) {
        if (spec[nspec][nchannel][i] < min_val) {
            min_val = spec[nspec][nchannel][i];
        }
    }

    return min_val;
}