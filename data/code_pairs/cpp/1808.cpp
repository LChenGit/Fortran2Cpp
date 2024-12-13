#ifndef TYPES_H
#define TYPES_H

#include <vector>

class grid_comm_pattern_type {
public:
    struct send_type {
        std::vector<int> index_no;
    };
    std::vector<send_type> send;
};

class t_comm_variable {
public:
    grid_comm_pattern_type grid_comm_pattern;
};

class bbstr {
public:
    int dummy;
};

#endif // TYPES_H