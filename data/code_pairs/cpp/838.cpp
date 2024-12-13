#include <cctype> // for std::toupper

bool LSAME(char CA, char CB) {
    return std::toupper(CA) == std::toupper(CB);
}