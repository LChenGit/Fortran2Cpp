// loglikelihood.h
#include <vector>
#include <cmath>
#include <cassert>
using namespace std;

typedef vector<double> Vector;
typedef vector<Vector> Matrix;

void sptransitmodel(int nplanet, int npars, const Vector &sol, const Matrix &solrange,
                    int nwv, int nobs, const Matrix &time, const Matrix &exptime,
                    const Vector &ntt, const Matrix &tobs, Matrix &omc, Matrix &sptmodel, int nwvc) {
    // Example: Setting sptmodel to an arbitrary value for demonstration purposes.
    for (int i = 0; i < nwv; ++i) {
        for (int j = 0; j < nobs; ++j) {
            sptmodel[i][j] = 1.0; // Example operation, replace with actual calculations
        }
    }
}

double loglikelihood(int nwv, int nobs, int nplanet, int npars, 
                     const Vector &sol, const Matrix &solrange, const Matrix &time, 
                     const Matrix &flux, const Matrix &ferr, const Matrix &exptime, 
                     const Vector &ntt, const Matrix &tobs, Matrix &omc, Matrix &sptmodel, int nwvc) {
    Matrix sptmodel1(nwv, Vector(nobs));
    sptransitmodel(nplanet, npars, sol, solrange, nwv, nobs, time, exptime, ntt, tobs, omc, sptmodel1, nwvc);

    if (nwvc == 0) {
        sptmodel = sptmodel1;
    } else {
        for (int i = 0; i < nobs; ++i) {
            sptmodel[nwvc][i] = sptmodel1[nwvc][i];
        }
    }

    double ll1 = 0.0;
    double ll2 = 0.0;
    double ll3 = 0.0;
    for (int i = 0; i < nwv; ++i) {
        for (int j = 0; j < nobs; ++j) {
            double diff = sptmodel[i][j] - flux[i][j];
            ll3 += (diff * diff) / (ferr[i][j] * ferr[i][j]);
        }
    }

    double loglikelihood = -0.5 * (ll1 + ll2 + ll3);
    double prior = 1.0;

    return loglikelihood * prior;
}

// test_loglikelihood.cpp
#include <iostream>

int main() {
    int nwv = 1;
    int nobs = 1;
    int nplanet = 1;
    int npars = 1;
    int nwvc = 0;
    Vector sol = {0.5};
    Matrix solrange = {{1}};
    Matrix time = {{0.5}};
    Matrix flux = {{1.0}};
    Matrix ferr = {{0.1}};
    Matrix exptime = {{0.5}};
    Vector ntt = {0};
    Matrix tobs = {{0.5}};
    Matrix omc = {{0.0}};
    Matrix sptmodel(nwv, Vector(nobs, 0.0));

    double result = loglikelihood(nwv, nobs, nplanet, npars, sol, solrange, time, flux, ferr, exptime, ntt, tobs, omc, sptmodel, nwvc);

    cout << "Loglikelihood result: " << result << endl;

    return 0;
}