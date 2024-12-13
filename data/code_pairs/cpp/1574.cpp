#include <vector>

class ModuleCells {
public:
    std::vector<std::vector<int>> cells;

    void allocate(int numRows, int numCols) {
        cells.resize(numRows);
        for (auto& row : cells) {
            row.resize(numCols, 0); // Initialize cells with 0
        }
    }
};