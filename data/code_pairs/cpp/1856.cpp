#include <iostream>
#include <string>

class Para {
public:
    static std::string bobo(int n) {
        std::string baseString = "1234567890";
        return baseString.substr(0, n);
    }
};