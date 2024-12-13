#ifndef OPTIONS_H
#define OPTIONS_H

#include <string>
#include <array>

class Options {
public:
    int itheory;
    int itheory_xc;

    // Constructor
    Options() : itheory(0), itheory_xc(0) {
        // Initialize other members as necessary
    }

    // Other members and methods are omitted for brevity
};

#endif // OPTIONS_H