// file: Handlers.hpp
#include <iostream>

class Handlers {
public:
    static void onClosing() {
        std::cout << "Closing event triggered." << std::endl;
    }
};

// file: main.cpp
#include "Handlers.hpp"

int main() {
    Handlers::onClosing();
    return 0;
}