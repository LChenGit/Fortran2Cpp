#include <cassert>
#include <iostream>
#include <vector>
#include <string>

// Definitions based on the context provided
const int MAXREC = 10;
const int RECLEN = 20;

// Equivalent structure for the first common block /dbbuf1/
struct DbBuf1 {
    int stidmx;
    std::vector<int> strpos; // Using vector to hold array of positions
    int stid;
    bool newpos;
    bool newrec;

    DbBuf1() : strpos(MAXREC), newpos(false), newrec(false) {}
};

// Equivalent structure for the second common block /dbbuf2/
struct DbBuf2 {
    std::string strec; // Using string to hold character array

    DbBuf2() : strec(RECLEN, ' ') {}
};

// Global instances of the structures
DbBuf1 dbbuf1;
DbBuf2 dbbuf2;

int main() {
    // Initialize some data
    dbbuf1.stidmx = 100;
    dbbuf1.stid = 1;
    dbbuf1.newpos = true;
    dbbuf1.newrec = false;
    for (int i = 0; i < MAXREC; ++i) {
        dbbuf1.strpos[i] = (i+1) * 10;
    }
    dbbuf2.strec = "Hello, C++ Common!";

    // Assertions to verify the data
    assert(dbbuf1.stidmx == 100);
    assert(dbbuf1.stid == 1);
    assert(dbbuf1.newpos == true);
    assert(dbbuf1.newrec == false);
    for (int i = 0; i < MAXREC; ++i) {
        assert(dbbuf1.strpos[i] == (i+1) * 10);
    }
    assert(dbbuf2.strec == "Hello, C++ Common!");

    std::cout << "All assertions passed!" << std::endl;

    return 0;
}