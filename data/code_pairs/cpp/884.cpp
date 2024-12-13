#include <string>
#include <array>
#include <iostream>

struct LIN_DATA {
    std::array<std::string, 4> LIN_ERRMSG = {
        "Success",
        "Null linprm pointer passed",
        "Memory allocation failed",
        "PCi_ja matrix is singular"
    };
};

LIN_DATA lin_data;

int main() {
    // Example usage (not required for the unit test)
    for (const auto& msg : lin_data.LIN_ERRMSG) {
        std::cout << msg << std::endl;
    }

    return 0;
}