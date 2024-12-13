#include <array>
#include <cassert>
#include <iostream>

// Translated C++ Code
struct WAV {
    static constexpr int BUFLEN = 8192;
    static constexpr int NBUFS = 10;
    static constexpr int NDESCR = 9;
    
    static char BUF[BUFLEN][NBUFS];
    static std::array<int, 2 * NBUFS> RECORD; // Assuming 2D array flattened
    static std::array<int, NBUFS> USED;
    static std::array<bool, NBUFS> DIRTY;
    static std::array<bool, 100> FILEWR;
    static int NXT;
    static std::array<int, NDESCR * 100> DESCR; // Assuming 2D array flattened
    static std::array<bool, 100> DTLAST;
    static std::array<bool, 100> CHGWLN;
    static std::array<bool, 100> CHGSAM;
};

// Definitions for static members
char WAV::BUF[BUFLEN][NBUFS];
std::array<int, 2 * NBUFS> WAV::RECORD;
std::array<int, NBUFS> WAV::USED;
std::array<bool, NBUFS> WAV::DIRTY;
std::array<bool, 100> WAV::FILEWR;
int WAV::NXT;
std::array<int, NDESCR * 100> WAV::DESCR;
std::array<bool, 100> WAV::DTLAST;
std::array<bool, 100> WAV::CHGWLN;
std::array<bool, 100> WAV::CHGSAM;

int main() {
    // Unit test code for C++
    WAV::NXT = 1;
    WAV::USED[0] = 1; // Adjust for 0-based indexing
    WAV::DIRTY[0] = true;
    WAV::FILEWR[0] = true;
    WAV::DESCR[0] = 10; // Assuming flat array and considering DESLEN as 1 (adjusted for 0-based indexing)
    WAV::DTLAST[0] = false;
    WAV::CHGWLN[0] = true;
    WAV::CHGSAM[0] = false;

    std::cout << "Running C++ unit tests..." << std::endl;

    assert(WAV::NXT == 1);
    assert(WAV::USED[0] == 1);
    assert(WAV::DIRTY[0] == true);
    assert(WAV::FILEWR[0] == true);
    assert(WAV::DESCR[0] == 10);
    assert(WAV::DTLAST[0] == false);
    assert(WAV::CHGWLN[0] == true);
    assert(WAV::CHGSAM[0] == false);

    std::cout << "All C++ tests passed." << std::endl;

    return 0;
}