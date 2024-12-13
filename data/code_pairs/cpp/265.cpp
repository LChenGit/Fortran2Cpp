#include <vector>

void MB03BA(int K, int H, std::vector<int>& S, int& SMULT, std::vector<int>& AMAP, std::vector<int>& QMAP) {
    int TEMP;

    if (S[H-1] == -1) {
        SMULT = -1;
        for (int I = 1; I <= H; ++I) {
            AMAP[I-1] = H - I + 1;
        }
        for (int I = H+1; I <= K; ++I) {
            AMAP[I-1] = H + 1 - I + K;
        }
        TEMP = (H % K) + 1;
        for (int I = TEMP; I >= 1; --I) {
            QMAP[TEMP - I] = I;
        }
        for (int I = K; I > TEMP; --I) {
            QMAP[TEMP + K - I] = I;
        }
    } else {
        SMULT = 1;
        for (int I = H; I <= K; ++I) {
            AMAP[I - H] = I;
            QMAP[I - H] = I;
        }
        for (int I = 1; I < H; ++I) {
            AMAP[K - H + I] = I;
            QMAP[K - H + I] = I;
        }
    }
}