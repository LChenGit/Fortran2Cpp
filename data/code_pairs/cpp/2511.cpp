#include <iostream>

int main() {
    int* n0array = new int[10];
    int* n1array = new int[10];
    float* psi0 = new float[10];
    float* psi = new float[10];
    float* polar = new float[10];
    int* iwork_st = new int[10];
    int* iblock_st = new int[10];
    int* isplit_st = new int[10];
    float* d_st = new float[10];
    float* e_st = new float[10];
    float* w_st = new float[10];
    float* work_st = new float[10];
    float* z_st = new float[10];

    // Deallocate arrays
    delete[] n0array;
    delete[] n1array;
    delete[] psi0;
    delete[] psi;
    delete[] polar;
    delete[] iwork_st;
    delete[] iblock_st;
    delete[] isplit_st;
    delete[] d_st;
    delete[] e_st;
    delete[] w_st;
    delete[] work_st;
    delete[] z_st;

    std::cout << "Deallocation successful!" << std::endl;

    return 0;
}