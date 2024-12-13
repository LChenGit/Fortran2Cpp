#include <iostream>
#include <array>
#include <string>

void defcolor(int icolor) {
    std::array<std::string, 8> colors = {
        "white",
        "red",
        "cyan",
        "yellow",
        "green",
        "magenta",
        "blue",
        "black"
    };

    if (icolor >= 1 && icolor <= 8) {
        std::string selectedColor = colors[icolor - 1]; // Adjust for 0-based indexing
        std::cout << "Selected color is: " << selectedColor << std::endl;
    } else {
        std::cout << "Invalid color index" << std::endl;
    }
}

int main() {
    defcolor(1);
    defcolor(5);
    defcolor(9); // Test with an invalid index

    return 0;
}