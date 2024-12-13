#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct CommonBlock {
    char s3[2][3]; // 2 elements of 3 characters each
    char s8[8];    // 8 characters
};

union Equivalence {
    CommonBlock com;
    char s6[6];
    char s2[3][2];
    char s4[2][4];
    char s8e[8];
    char s1[5];
};

int main() {
    ofstream outFile("output_cpp.txt");
    Equivalence eq;

    strncpy(eq.com.s3[0], "AbC", 3);
    strncpy(eq.com.s3[1], "dEf", 3);

    outFile.write(eq.s6, 6) << '\n';

    strncpy(eq.s6, "PqrStu", 6);

    for (int i = 0; i < 3; ++i) {
        outFile.write(eq.s2[i], 2) << '\n';
    }

    strncpy(eq.s2[0], "gH", 2);
    strncpy(eq.s2[1], "Ij", 2);
    strncpy(eq.s2[2], "kL", 2);

    for (int i = 0; i < 2; ++i) {
        outFile.write(eq.com.s3[i], 3) << '\n';
    }

    strncpy(eq.s8e, "AbcdefgH", 8);

    for (int i = 0; i < 2; ++i) {
        outFile.write(eq.s4[i], 4) << '\n';
    }

    for (int i = 0; i < 5; ++i) {
        outFile << eq.s1[i] << '\n';
    }

    outFile.close();
    return 0;
}