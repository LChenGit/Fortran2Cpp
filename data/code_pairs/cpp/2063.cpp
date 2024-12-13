#include <vector>

void DLAPMT(bool FORWRD, int M, int N, std::vector<std::vector<double>>& X, std::vector<int>& K) {
    int I, IN, J, II;
    double TEMP;

    if (N <= 1) return;

    for (I = 1; I <= N; ++I) {
        K[I - 1] = -K[I - 1];
    }

    if (FORWRD) {
        for (I = 1; I <= N; ++I) {
            if (K[I - 1] > 0) continue;

            J = I;
            K[J - 1] = -K[J - 1];
            IN = K[J - 1];

            while (true) {
                if (K[IN - 1] > 0) break;

                for (II = 1; II <= M; ++II) {
                    TEMP = X[II - 1][J - 1];
                    X[II - 1][J - 1] = X[II - 1][IN - 1];
                    X[II - 1][IN - 1] = TEMP;
                }

                K[IN - 1] = -K[IN - 1];
                J = IN;
                IN = K[IN - 1];
            }
        }
    }
}