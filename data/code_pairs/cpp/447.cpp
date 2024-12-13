#include <iostream>

// Assuming constants for indexing into the company table
const int max_company = 10;
const int c_company_id = 0, c_nmgr = 1, c_mgr_mem = 2, c_nwrkr = 3, c_wrkr_mem = 4;
int c_table[max_company][5]; // Company table

void build_company(int id, int nmgr, int mgr_mem, int nwrkr, int wrkr_mem) {
    for (int i = 0; i < max_company; ++i) {
        if (c_table[i][c_company_id] == -1) { // Using -1 to simulate MPI_UNDEFINED
            c_table[i][c_company_id] = id;
            c_table[i][c_nmgr] = nmgr;
            c_table[i][c_mgr_mem] = mgr_mem;
            c_table[i][c_nwrkr] = nwrkr;
            c_table[i][c_wrkr_mem] = wrkr_mem;
            return;
        }
    }
    
    std::cerr << "Error: Limit of " << max_company << " companies has been exceeded." << std::endl;
}

int main() {
    // Initialize the company table
    for (int i = 0; i < max_company; ++i) {
        for (int j = 0; j < 5; ++j) {
            c_table[i][j] = -1; // Using -1 to simulate MPI_UNDEFINED
        }
    }

    // Example usage of build_company
    build_company(1, 2, 100, 50, 500);
    build_company(2, 3, 150, 60, 600);

    // Print the company table to verify
    for (int i = 0; i < max_company; ++i) {
        if (c_table[i][c_company_id] != -1) { // Using -1 to simulate MPI_UNDEFINED
            std::cout << "Company ID: " << c_table[i][c_company_id]
                      << ", Managers: " << c_table[i][c_nmgr]
                      << ", Manager Memory: " << c_table[i][c_mgr_mem]
                      << ", Workers: " << c_table[i][c_nwrkr]
                      << ", Worker Memory: " << c_table[i][c_wrkr_mem]
                      << std::endl;
        }
    }

    return 0;
}