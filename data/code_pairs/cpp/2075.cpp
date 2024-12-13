#include <iostream>
#include <cstring> // for strncpy

void copy(const char* in, char* out, int size) {
    strncpy(out, in, size);
    out[size] = '\0'; // Ensuring null termination
}

int main() {
    const int array_size = 10;
    char digit_string[array_size] = "123456789";
    char digit_arr[array_size + 1]; // +1 for null terminator

    copy(digit_string, digit_arr, array_size - 1);

    // Print each character in the array
    for (int i = 0; i < array_size - 1; ++i) { // '-1' because we're not copying the null terminator of the string
        std::cout << ' ' << digit_arr[i];
    }
    std::cout << std::endl;

    return 0;
}