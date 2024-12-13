#include <iostream>
#include <cstdlib>
#include <cassert>

struct T {
    int X;
    int Y;
};

int main() {
    T S;

    S.X = 1;
    S.Y = 2;

    {
        struct T {
            int X;
            int Y;
        };

        T S;

        S.X = 3;
        S.Y = 4;
    }

    {
        struct T {
            int X;
            int Y;
        };

        T S;

        S.X = 5;
        S.Y = 6;
    }

    // Assertions as a simple test mechanism
    assert(S.X == 1);
    assert(S.Y == 2);

    // You could also print out values if you prefer a manual check
    std::cout << "S.X: " << S.X << ", S.Y: " << S.Y << std::endl;

    return 0;
}