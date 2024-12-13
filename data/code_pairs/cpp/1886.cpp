#include <iostream>

void fsub3(int arg, int& res) {
    std::cout << "fsub3 called" << std::endl;
    res = arg * 4;
}