#ifndef PPM_RC_UPPERCASE_H
#define PPM_RC_UPPERCASE_H

#include <string>
#include <cctype> // For std::toupper

void ppm_rc_uppercase(std::string& record) {
    for (char& c : record) {
        if (c >= 'a' && c <= 'z') {
            c = std::toupper(c);
        }
    }
}

#endif // PPM_RC_UPPERCASE_H