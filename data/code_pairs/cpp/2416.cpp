#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

bool main_logic() {
    const int N = 10;
    std::vector<std::string> ca(3);
    std::ostringstream buffer;

    ca[0] = "foo";
    ca[1] = "bar";
    ca[2] = "xyzzy";

    for (const auto& str : ca) {
        buffer << std::setw(5) << std::left << str;
    }

    std::string result = buffer.str();
    result = result.substr(0, result.find_last_not_of(' ') + 1);

    return result == "foo  bar  xyzzy";
}

int main() {
    if (!main_logic()) {
        std::cout << "Error encountered." << std::endl;
        return 1;
    } else {
        std::cout << "All tests passed successfully." << std::endl;
        return 0;
    }
}