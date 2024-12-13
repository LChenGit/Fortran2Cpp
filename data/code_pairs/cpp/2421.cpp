#include <vector>
#include <iostream>

void slamrg(int n1, int n2, const std::vector<float>& a, int strd1, int strd2, std::vector<int>& index) {
    int ind1, ind2;
    int n1sv = n1, n2sv = n2;

    if (strd1 > 0) {
        ind1 = 0;
    } else {
        ind1 = n1 - 1;
    }

    if (strd2 > 0) {
        ind2 = n1;
    } else {
        ind2 = n1 + n2 - 1;
    }

    int i = 0;
    while (n1sv > 0 && n2sv > 0) {
        if (a[ind1] <= a[ind2]) {
            index[i] = ind1 + 1; // Adjust for Fortran 1-based indexing
            i++;
            ind1 += strd1;
            n1sv--;
        } else {
            index[i] = ind2 + 1; // Adjust for Fortran 1-based indexing
            i++;
            ind2 += strd2;
            n2sv--;
        }
    }

    while (n1sv > 0) {
        index[i] = ind1 + 1; // Adjust for Fortran 1-based indexing
        i++;
        ind1 += strd1;
        n1sv--;
    }

    while (n2sv > 0) {
        index[i] = ind2 + 1; // Adjust for Fortran 1-based indexing
        i++;
        ind2 += strd2;
        n2sv--;
    }
}

int main() {
    int n1 = 3, n2 = 3, strd1 = 1, strd2 = 1;
    std::vector<float> a = {1.0, 3.0, 5.0, 2.0, 4.0, 6.0};
    std::vector<int> index(n1 + n2);

    slamrg(n1, n2, a, strd1, strd2, index);

    std::cout << "Index:" << std::endl;
    for (int idx : index) {
        std::cout << idx << std::endl;
    }

    return 0;
}