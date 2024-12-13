#include <cctype> // For std::tolower

int char2type(char character) {
    switch (std::tolower(character)) {
        case 'e':
            return 1;
        default:
            return -1234;
    }
}