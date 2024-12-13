#include <iostream>

struct MN {
    int M, N, MPLUSN, I;
    bool FS;
} common_mn; // Global instance

bool SLCTSX(float AR, float AI, float BETA) {
    if (common_mn.FS) {
        common_mn.I++;
        if (common_mn.I <= common_mn.M) {
            return false;
        } else {
            return true;
        }
        if (common_mn.I == common_mn.MPLUSN) {
            common_mn.FS = false;
            common_mn.I = 0;
        }
    } else {
        common_mn.I++;
        if (common_mn.I <= common_mn.N) {
            return true;
        } else {
            return false;
        }
        if (common_mn.I == common_mn.MPLUSN) {
            common_mn.FS = true;
            common_mn.I = 0;
        }
    }
    return false; // This is logically unreachable but added to avoid compiler warnings
}

void initCommonBlock() {
    common_mn.M = 2;
    common_mn.N = 3;
    common_mn.MPLUSN = 5;
    common_mn.I = 0;
    common_mn.FS = true;
}

void runTest(int testNumber, bool expected, float AR, float AI, float BETA) {
    bool result = SLCTSX(AR, AI, BETA);
    std::cout << "Test " << testNumber << ": Expected " << std::boolalpha << expected
              << ", Got: " << result << std::endl;
}