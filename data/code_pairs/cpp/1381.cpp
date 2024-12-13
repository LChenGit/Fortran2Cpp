#include <iostream>
#include <vector>
#include <cassert>

const int mxtime = 10;

void depsto(int i, std::vector<float>& recum, const std::vector<float>& f, float dtime, float avedep,
            int& idep, float& dinf, std::vector<float>& retemp, std::vector<float>& re, float& xmul,
            float& relast) {
    
    static int ifst = 0; // Preserved across calls
    static float frate = 0.0; // Preserved across calls
    float redep;

    if (idep == 0) {
        redep = recum[i] - relast + dinf;
        if (redep <= avedep) {
            if (re[i - 1] > 0) {
                retemp[i] = retemp[i - 1];
                re[i - 1] = 0;
                ifst = 0;
            } else {
                if (ifst == 0) {
                    xmul += (redep - dinf) / avedep;
                    dinf = redep;
                    frate = f[i - 2];
                    ifst = 1;
                }
                dinf -= frate * dtime;
                if (dinf < 0) dinf = 0;
                idep = 0;
                retemp[i] = retemp[i - 1];
                relast = recum[i];
            }
        } else {
            xmul += (avedep - dinf) / avedep;
            retemp[i] -= avedep * xmul;
            idep = 1;
            ifst = 1;
        }
    } else {
        if (re[i - 1] > 0) {
            retemp[i] -= avedep * xmul;
        } else {
            frate = f[i - 2];
            dinf = avedep - frate * dtime;
            if (dinf < 0) dinf = 0;
            idep = 0;
            retemp[i] = retemp[i - 1];
            relast = recum[i];
        }
    }
}

int main() {
    int i = 4; // Adjusted for 0-based indexing
    int idep = 0;
    float dtime = 1.0;
    float avedep = 2.0;
    float dinf = 0.5;
    float xmul = 1.0;
    float relast = 0.0;
    std::vector<float> recum = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<float> f = {0.5, 1.0, 1.5, 2.0, 2.5, 3.0, 3.5, 4.0, 4.5, 5.0};
    std::vector<float> retemp(10, 0);
    std::vector<float> re = {0, 0, 0, 0, 1, 0, 0, 0, 0, 0};

    depsto(i, recum, f, dtime, avedep, idep, dinf, retemp, re, xmul, relast);

    // Output results for manual verification
    std::cout << "idep: " << idep << std::endl;
    std::cout << "dinf: " << dinf << std::endl;
    std::cout << "xmul: " << xmul << std::endl;
    std::cout << "relast: " << relast << std::endl;
    for (size_t index = 0; index < retemp.size(); ++index) {
        std::cout << "retemp[" << index << "]: " << retemp[index] << std::endl;
    }

    return 0;
}