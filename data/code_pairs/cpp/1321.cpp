#include <vector>
#include <iostream>

class mo_column {
public:
    std::vector<float> compute_column(int nz, std::vector<float>& q, std::vector<float>& t) {
        std::vector<float> res(nz);
        float c = 5.345f;
        for (int k = 1; k < nz; ++k) { // Arrays in C++ are 0-based
            t[k] = c * (k + 1); // Adjust index for 0-based arrays
            q[k] = t[k - 1] + t[k] * c;
        }
        q[nz - 1] *= c; // Adjust index for 0-based arrays

        std::copy(t.begin(), t.end(), res.begin());
        return res;
    }

    void compute_all(int nz, std::vector<float>& q, std::vector<float>& val) {
        val = compute_column(nz, q, val);
    }
};

int main() {
    mo_column column;
    int nz = 5;
    std::vector<float> q = {0.0f, 1.0f, 2.0f, 3.0f, 4.0f};
    std::vector<float> val = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f};

    column.compute_all(nz, q, val);

    std::cout << "Modified q: ";
    for (const auto& elem : q) std::cout << elem << " ";
    std::cout << std::endl << "Modified val: ";
    for (const auto& elem : val) std::cout << elem << " ";
    std::cout << std::endl;

    return 0;
}