#include <string>

namespace funcs {
    std::string assumed_len(int x) {
        return std::string(x, ' ');  // Returns a string of x spaces
    }
}