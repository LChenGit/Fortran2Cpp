#include <iostream>
#include <string>
#include <cctype> // for std::tolower and std::toupper

class StringManipulation {
public:
    void convertCase(std::string &str, int direction) {
        for (char &ch : str) {
            if (direction == 0) {
                if (std::isupper(ch)) {
                    ch = std::tolower(ch);
                }
            } else if (direction == 1) {
                if (std::islower(ch)) {
                    ch = std::toupper(ch);
                }
            }
        }
    }
};