#include <iostream>
#include <array>
#include <string>

namespace TAB_DATA {
    std::array<std::string, 6> TAB_ERRMSG = {
        "Success",
        "Null tabprm pointer passed",
        "Memory allocation failed",
        "Invalid tabular parameters",
        "One or more of the x coordinates were invalid",
        "One or more of the world coordinates were invalid"
    };
}

int main() {
    for (size_t i = 0; i < TAB_DATA::TAB_ERRMSG.size(); ++i) {
        std::cout << "TAB_ERRMSG(" << i << "): " << TAB_DATA::TAB_ERRMSG[i] << std::endl;
    }
    return 0;
}