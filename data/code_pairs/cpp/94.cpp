#include <iostream>
#include <vector>
using namespace std;

void minimax(const vector<double>& x, double& xmin, double& xmax) {
    if (x.empty()) return; // Handle empty vector case

    xmax = x[0];
    xmin = xmax;

    for (size_t i = 1; i < x.size(); ++i) {
        if (x[i] < xmin) xmin = x[i];
        if (x[i] > xmax) xmax = x[i];
    }
}

int main() {
    vector<double> x = {1.5, -2.3, 3.7, 0.1, -0.5};
    double xmin, xmax;

    minimax(x, xmin, xmax);

    cout << "Minimum: " << xmin << endl;
    cout << "Maximum: " << xmax << endl;

    return 0;
}