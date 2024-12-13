#include <cstdint> // for std::int32_t

extern "C" {
    char return_char1(std::int32_t i) {
        return static_cast<char>(i);
    }

    char return_char2(std::int32_t i) {
        return static_cast<char>(i);
    }

    char return_char3(std::int32_t i) {
        return static_cast<char>(i);
    }
}