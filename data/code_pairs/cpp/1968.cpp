#ifndef REPLACE_CHARACTER_H
#define REPLACE_CHARACTER_H

#include <string>

void replaceCharacter(std::string& str, char oldChar, char newChar) {
    size_t length = str.length();
    for (size_t i = 0; i < length; ++i) {
        if (str[i] == oldChar) {
            str[i] = newChar;
        }
    }
}

#endif // REPLACE_CHARACTER_H