#include <iostream>
#include <string>
#include <cassert>

int nitems(const std::string& line) {
    int number = 0;
    size_t icount = 0;
    size_t lineLen = line.length();

    while (icount < lineLen) {
        if (line[icount] != ' ' && line[icount] != ',') {
            number++;
            while (icount < lineLen && line[icount] != ' ' && line[icount] != ',') {
                icount++;
            }
        } else {
            icount++;
        }
    }

    return number;
}

int main() {
    // Test cases
    assert(nitems("apple, orange, banana, peach") == 4);
    assert(nitems("  ") == 0);
    assert(nitems("apple orange banana") == 3);
    assert(nitems("") == 0);
    assert(nitems(" , , ,") == 0);
    assert(nitems("apple,orange,banana,peach") == 4);
    assert(nitems("    apple orange    banana   peach  ") == 4);

    std::cout << "All tests passed." << std::endl;
    return 0;
}