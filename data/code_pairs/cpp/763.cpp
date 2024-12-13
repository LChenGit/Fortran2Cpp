// dat_node_mod.hpp
#include <iostream>
#include <memory>

class DAT_MOD {
public:
    struct DAT {
        int NN;

        bool operator<(const DAT& other) const {
            return NN < other.NN;
        }
    };
};

class NODE_MOD {
public:
    struct NODE {
        int KEY;
        std::unique_ptr<DAT_MOD::DAT> PTR;

        bool operator<(const NODE& other) const {
            if (KEY != other.KEY) {
                return KEY < other.KEY;
            } else {
                // Assuming PTR is always valid for simplicity
                return *PTR < *(other.PTR);
            }
        }
    };
};