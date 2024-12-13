#include <iostream>
#include <string>
#include <cstdlib>

int main() {
    std::string str = "Print rather a lot of ampersands &&&&&"
                      "&&&&&"
                      "&&&&&";
    if (str.size() != 44 || str != "Print rather a lot of ampersands &&&&&&&&&&&") {
        std::abort();
    }
    
    return 0;
}