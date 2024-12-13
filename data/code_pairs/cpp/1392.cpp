#include <iostream>
#include <vector>

void check_arrays(const std::vector<int>& auxiliary_empty_cells, int current_empty_cells, const std::vector<int>& empty_cells, int& error_index) {
    error_index = -1; // Initialize error_index to -1
    for(int i = 0; i < current_empty_cells; ++i) {
        if(i != auxiliary_empty_cells[empty_cells[i]]) {
            error_index = empty_cells[i];
            return;
        }
    }
}