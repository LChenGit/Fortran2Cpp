// DSRoutines.h
#include <vector>

class DSRoutines {
public:
    void dsget(std::vector<float>& rstore, std::vector<std::vector<float>>& vertic) {
        int nrvert = 4;
        int point = 26;
        // Ensure vertic has the correct size
        vertic.resize(1);
        vertic[0].resize(nrvert);
        // Adjusting for 0-based indexing in C++
        for (int i = 0; i < nrvert; ++i) {
            vertic[0][i] = rstore[point + i]; // point+i adjusts for 0-based indexing
        }
    }
};