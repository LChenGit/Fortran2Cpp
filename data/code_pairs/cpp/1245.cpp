#include <iostream>
#include <vector>

void OCTANT1(const std::vector<std::vector<float>>& A_IN,
             const std::vector<std::vector<float>>& SD_A_IN,
             int MAXX_IN, int MAXY_IN, int NX, int NY, float BADDATA,
             int MAX_SEARCH_RADIUS, int MAX_VALUES_PER_OCTANT,
             int IX, int IY, int& POINTS_FOUND,
             std::vector<int>& IX_FOUND, std::vector<int>& IY_FOUND) {
    POINTS_FOUND = 0;
    for (int IY_SEARCH = IY + 1; IY_SEARCH <= std::min(IY + MAX_SEARCH_RADIUS, NY); ++IY_SEARCH) {
        for (int IX_SEARCH = IX; IX_SEARCH <= std::min(IX + IY_SEARCH - IY - 1, NX); ++IX_SEARCH) {
            if (A_IN[IX_SEARCH - 1][IY_SEARCH - 1] != BADDATA && SD_A_IN[IX_SEARCH - 1][IY_SEARCH - 1] != BADDATA) {
                POINTS_FOUND++;
                if (POINTS_FOUND <= MAX_VALUES_PER_OCTANT) {
                    IX_FOUND.push_back(IX_SEARCH);
                    IY_FOUND.push_back(IY_SEARCH);
                }
                if (POINTS_FOUND >= MAX_VALUES_PER_OCTANT) {
                    return;
                }
            }
        }
    }
}