#include <iostream>
#include <cmath>
#include <vector>
#include <limits>

void ESSAI(double APX, double& AKPX, int IND, bool& ERREUR, std::vector<double>& AKP, std::vector<double>& AP) {
    static const double epsilon = std::numeric_limits<double>::epsilon();
    
    ERREUR = false;

    if (IND > 0) {
        if (APX < 0.0) {
            ERREUR = true;
            return;
        }

        bool FIN_TRAITEMENT = false;
        int I = 1;
        int IM;

        while (I <= 28 && !FIN_TRAITEMENT) {
            if (std::abs(APX - AP[I - 1]) <= epsilon) {
                AKPX = AKP[I - 1];
                FIN_TRAITEMENT = true;
            } else if (APX <= AP[I - 1]) {
                IM = I - 1;
                if (IM == 0) {
                    // Handle potential division by zero if AP(I-1) == AP(IM) when IM == 0
                    AKPX = AKP[I - 1]; // Assumes a linear extrapolation or fallback behavior
                } else {
                    AKPX = AKP[IM - 1] + (AKP[I - 1] - AKP[IM - 1]) * (APX - AP[IM - 1]) / (AP[I - 1] - AP[IM - 1]);
                }
                FIN_TRAITEMENT = true;
            } else {
                I = I + 1;
            }
        }
    }
}

int main() {
    double APX = 1.5;
    double AKPX;
    int IND = 1;
    bool ERREUR;

    std::vector<double> AKP(28);
    std::vector<double> AP(28);

    for (int I = 0; I < 28; ++I) {
        AKP[I] = I + 1.0;
        AP[I] = I + 1.0;
    }

    ESSAI(APX, AKPX, IND, ERREUR, AKP, AP);

    if (ERREUR) {
        std::cerr << "Error: APX is less than 0." << std::endl;
    } else {
        std::cout << "AKPX: " << AKPX << std::endl;
    }

    return 0;
}