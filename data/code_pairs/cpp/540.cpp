#include <vector>
using std::vector;

void SetBoundWake(vector<vector<double>>& x, vector<vector<double>>& y, vector<vector<double>>& z, 
                  const vector<double>& xBE, const vector<double>& yBE, const vector<double>& zBE, 
                  int nb, int nbe, int nt) {
    for (int i = 0; i < nb; ++i) {
        int nei = 1 + i * (nbe + 1) - 1; // Adjusting for 0-based indexing in C++
        for (int j = 0; j <= nbe; ++j) {
            int nej = nei + j;
            x[nt][nej] = xBE[nej];
            y[nt][nej] = yBE[nej];
            z[nt][nej] = zBE[nej];
        }
    }
}