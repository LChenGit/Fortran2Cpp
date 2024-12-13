#ifndef GREAT_NE_H
#define GREAT_NE_H

#include <iostream>

void great_ne(int a, int b) {
    if (a != b) {
        std::cout << "great_ne: " << a << " and " << b << " are not equal." << std::endl;
    } else {
        std::cout << "great_ne: " << a << " and " << b << " are equal." << std::endl;
    }
}

#endif // GREAT_NE_H