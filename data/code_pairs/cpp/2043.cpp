#include <iostream>
#include <string>

// Mock Global Variables and Functions
bool twfcollect = true;
bool do_coulomb = true;
int iuwfc = 1;
int iubar = 2;

void close_buffer(int id, std::string action) {
    std::cout << "close_buffer called with id=" << id << " action=" << action << std::endl;
}

void close_gwq(bool flag) {
    if (twfcollect) {
        close_buffer(iuwfc, "delete");
    } else {
        close_buffer(iuwfc, "keep");
    }

    if (flag && do_coulomb) {
        close_buffer(iubar, "keep");
    } else {
        close_buffer(iubar, "keep");
    }
}

int main() {
    close_gwq(true);
    close_gwq(false);
    return 0;
}