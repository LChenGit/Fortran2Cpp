#ifndef CONSTANTS_H
#define CONSTANTS_H

const int nn = 25;
const int ni = 144;
const int nj = 288;
const int nnaf = 23;
const int minc = 6;

const int nnp2 = nn + 2;
const int nnp1 = nn + 1;
const int nn1 = nn - 1;
const int nn2 = nn - 2;
const int nn3 = nn - 3;
const int nps2 = nnp1 / 2;
const int ns2 = nn1 / 2;
const int nnx2 = 2 * nn;
const int nja = nj / minc;
const int nrp = nja + 2;
const int ncp = nrp / 2;
const int ntf = 3 * nja / 2 + 1;
const int njp1 = nj + 1;
const int nip1 = ni + 1;
const int lmax = nj / 3;
const int mmax = (lmax / minc) * minc;
const int nmaf = mmax + 1;
const int nmafa = mmax / minc + 1;
const int nlm = (nmaf * (nmaf + 1)) / 2;
const int nlaf = lmax + 1;
const int nlma = mmax * nlaf / minc - mmax * (mmax - minc) / (2 * minc) + nlaf - mmax;
const int lot = 2 * nlma;
const int nlafp1 = nlaf + 1;
const int nlmpa = nlma + nmafa;

#endif // CONSTANTS_H