#include <string>

void ST_LCUC(const std::string& string, std::string& outstr, int& iret) {
    iret = 0; // Assuming iret is used to indicate success/failure, keeping it 0 as the original code doesn't modify it.
    outstr = string; // Copy input string to output string.
    int isize = outstr.length(); // Get the length of the string.

    for (int i = 0; i < isize; ++i) {
        if (outstr[i] >= 'a' && outstr[i] <= 'z') { // Check if the character is lowercase.
            outstr[i] = outstr[i] - 32; // Convert to uppercase (ASCII manipulation).
        }
    }
}