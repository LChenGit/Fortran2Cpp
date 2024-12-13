#include <vector>

void GETBUF(std::vector<float>& BUF1, std::vector<float>& BUF2, int NPIX, int NRAST) {
    int totalSize = NPIX * NRAST;
    BUF2.resize(totalSize);  // Ensure BUF2 is the right size
    for (int i = 0; i < totalSize; ++i) {
        BUF2[i] = BUF1[i];
    }
}