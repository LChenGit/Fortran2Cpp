#include <iostream>
#include <cmath>
#include <algorithm>

void ping(const float* s, int nz, float dtbuf, float slim, float wmin, float pingdat[3][100], int& nping) {
    bool inside = false;
    float peak = 0.0f;
    float snrlim = std::pow(10.0f, 0.1f * slim) - 1.0f;
    float sdown = 10.0f * std::log10(0.25f * snrlim + 1.0f);
    int i0 = 0;
    float tstart = 0.0f;
    nping = 0;

    for (int i = 1; i < nz; ++i) {
        if (s[i] >= slim && !inside) {
            i0 = i;
            tstart = i0 * dtbuf;
            inside = true;
            peak = 0.0f;
        }
        if (inside && s[i] > peak) {
            peak = s[i];
        }
        if (inside && (s[i] < sdown || i == nz - 1)) {
            if ((i - i0 + 1) * dtbuf >= wmin) {
                if (nping < 100) {
                    pingdat[0][nping] = tstart;
                    pingdat[1][nping] = dtbuf * (i - i0);
                    pingdat[2][nping] = peak;
                    nping++;
                }
            }
            inside = false;
            peak = 0.0f;
        }
    }
}

int main() {
    float s[100] = {0};
    float pingdat[3][100];
    int nping;
    int nz = 100;
    float dtbuf = 1.0f, slim = 5.0f, wmin = 2.0f;

    // Test 1: No signal exceeds the slim threshold
    std::fill(s, s + nz, 0.0f);
    ping(s, nz, dtbuf, slim, wmin, pingdat, nping);
    std::cout << "Test 1: nping = " << nping << std::endl;

    // Test 2: Single signal peak
    std::fill(s, s + nz, 0.0f);
    s[49] = 6.0f; // Considering 0-based index
    ping(s, nz, dtbuf, slim, wmin, pingdat, nping);
    std::cout << "Test 2: nping = " << nping << std::endl;

    // Test 3: Multiple signal peaks, only some meet criteria
    std::fill(s, s + nz, 0.0f);
    std::fill(s + 19, s + 30, 6.0f);
    std::fill(s + 59, s + 65, 7.0f);
    ping(s, nz, dtbuf, slim, wmin, pingdat, nping);
    std::cout << "Test 3: nping = " << nping << std::endl;

    return 0;
}