#include <iostream>
#include <array>

constexpr int LENRLS = 218;
constexpr int LENILS = 37;

std::array<double, LENRLS> RLS;
std::array<int, LENILS> ILS;

void DSRCOM(std::array<double, LENRLS>& RSAV, std::array<int, LENILS>& ISAV, int JOB) {
    if (JOB == 2) {
        for (int i = 0; i < LENRLS; ++i) {
            RLS[i] = RSAV[i];
        }
        for (int i = 0; i < LENILS; ++i) {
            ILS[i] = ISAV[i];
        }
    } else {
        for (int i = 0; i < LENRLS; ++i) {
            RSAV[i] = RLS[i];
        }
        for (int i = 0; i < LENILS; ++i) {
            ISAV[i] = ILS[i];
        }
    }
}

int main() {
    std::array<double, LENRLS> RSAV;
    std::array<int, LENILS> ISAV;
    
    // Initialize arrays with test data
    for (int i = 0; i < LENRLS; i++) {
        RSAV[i] = i * 1.0;
    }
    for (int i = 0; i < LENILS; i++) {
        ISAV[i] = -i;
    }

    // Test JOB = 1
    DSRCOM(RSAV, ISAV, 1);

    // Test JOB = 2
    DSRCOM(RSAV, ISAV, 2);

    return 0;
}