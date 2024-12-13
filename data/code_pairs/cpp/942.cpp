#include <iostream>
#include <vector>
#include <cmath>

void per_credat(std::vector<double>& x, std::vector<double>& y, int nval, 
                const std::vector<double>& f, const std::vector<double>& c, const std::vector<double>& p, 
                int nf, bool epfl, const std::vector<double>& ep, double epoch, double freq) {
    
    double delt = (ep[1] - ep[0]) / static_cast<double>(nval - 1);
    
    for (int i = 0; i < nval; ++i) {
        double t;
        
        if (epfl) {
            x[i] = ep[0] + static_cast<double>(i) * delt;
            t = (x[i] - epoch) * 6.28318530717958647692; // 2*PI
        } else {
            x[i] = static_cast<double>(i) / static_cast<double>(nval - 1);
            t = (x[i] / freq + ep[0] - epoch) * 6.28318530717958647692; // 2*PI
        }
        
        y[i] = c[0];
        
        for (int j = 0; j < nf; ++j) {
            y[i] += c[j + 1] * std::sin(t * f[j] + p[j]);
        }
    }
}

int main() {
    const int nval = 5;
    std::vector<double> x(nval), y(nval);
    std::vector<double> f = {1.0, 2.0};
    std::vector<double> c = {0.0, 1.0, 0.5};
    std::vector<double> p = {0.0, 3.14};
    int nf = 2;
    bool epfl = true;
    std::vector<double> ep = {0.0, 10.0};
    double epoch = 5.0, freq = 1.0;
    
    per_credat(x, y, nval, f, c, p, nf, epfl, ep, epoch, freq);
    
    std::cout << "X: ";
    for (const auto& value : x) std::cout << value << " ";
    std::cout << "\nY: ";
    for (const auto& value : y) std::cout << value << " ";
    std::cout << std::endl;
    
    return 0;
}