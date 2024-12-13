// CommDataIO.hpp
#include <vector>

class CommDataIO {
public:
    static long long num_neib_domain_IO;
};

long long CommDataIO::num_neib_domain_IO = 0; // Definition

// CommunicationTable.hpp
#include <vector>

class CommunicationTable {
public:
    long long num_neib;

    // Constructor
    CommunicationTable() : num_neib(0) {}
};

// set_comm_table_4_IO.hpp
#include "CommDataIO.hpp"
#include "CommunicationTable.hpp"

void copy_comm_tbl_type_from_IO(CommunicationTable& comm_tbls) {
    comm_tbls.num_neib = CommDataIO::num_neib_domain_IO;
}

// main.cpp - Test Program
#include <iostream>
#include "set_comm_table_4_IO.hpp"

int main() {
    CommunicationTable comm_tbls;
    
    // Initialize with some test data
    CommDataIO::num_neib_domain_IO = 2;

    // Call the function
    copy_comm_tbl_type_from_IO(comm_tbls);

    // Verify the results
    std::cout << "C++ Test Output:" << std::endl;
    std::cout << "num_neib = " << comm_tbls.num_neib << std::endl;

    return 0;
}