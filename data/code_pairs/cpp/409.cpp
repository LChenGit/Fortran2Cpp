#include <vector>

void mafillpbc(int nef, std::vector<double>& au, std::vector<double>& ad,
               std::vector<int>& jq, std::vector<int>& irow,
               std::vector<double>& b, int iatleastonepressurebc, int nzs) {
    if (iatleastonepressurebc == 0) {
        ad[nef - 1] = 1.0; // Adjusted for 0-based indexing
        b[nef - 1] = 0.0;  // Adjusted for 0-based indexing
        for (int i = 1; i < nef; ++i) { // Adjust loop to start from 1 for direct translation
            if (jq[i] - 1 > 0) {
                if (irow[jq[i] - 1 - 1] == nef) { // Adjusted index twice for 0-based indexing
                    au[jq[i] - 1 - 1] = 0.0; // Adjusted for 0-based indexing
                }
            }
        }
    }
}