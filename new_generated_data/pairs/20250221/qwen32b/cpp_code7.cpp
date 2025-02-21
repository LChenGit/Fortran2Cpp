#include <iostream>
#include <memory>
#include <cassert>
#include <cmath>
#include <algorithm>

class vd_2d_obj {
private:
    std::unique_ptr<double[]> vd_p_arr;
    double dx, dy;
    int npx, npy;
    double px_min, px_max, py_min, py_max;
    double dpx, dpy;
    std::unique_ptr<double[]> px_range;
    std::unique_ptr<double[]> py_range;

public:
    vd_2d_obj(double dx, double dy, int npx, int npy, double px_min, double px_max,
              double py_min, double py_max, double dpx, double dpy,
              const double* px_range, const double* py_range, double dt, bool sc,
              bool vd_disjoint, double hbar, double m, int vd_np_stdev = 0,
              const double* vd_p_arr = nullptr) {
        this->dx = dx;
        this->dy = dy;
        this->npx = npx;
        this->npy = npy;
        this->px_min = px_min;
        this->px_max = px_max;
        this->py_min = py_min;
        this->py_max = py_max;
        this->dpx = dpx;
        this->dpy = dpy;

        // Copy the ranges
        this->px_range = std::make_unique<double[]>(npx);
        std::copy(px_range, px_range + npx, this->px_range.get());
        this->py_range = std::make_unique<double[]>(npy);
        std::copy(py_range, py_range + npy, this->py_range.get());

        if (vd_disjoint) {
            this->vd_p_arr = std::unique_ptr<double[]>(const_cast<double*>(vd_p_arr));
        } else {
            this->vd_p_arr = std::make_unique<double[]>(npx * npy);
            std::fill(this->vd_p_arr.get(), this->vd_p_arr.get() + npx * npy, 0.0);
        }
    }

    ~vd_2d_obj() {
        // Cleanup handled by unique_ptr
    }

    void cleanup() {
        vd_p_arr.reset();
        px_range.reset();
        py_range.reset();
    }

    void update(double* psi_arr) {
        // Placeholder for update logic
    }

    int getNpx() const {
        return npx;
    }
};

bool has_close_elements(const double* a, const double* b, size_t size, double tolerance) {
    for (size_t i = 0; i < size; ++i) {
        if (std::abs(a[i] - b[i]) > tolerance) {
            return false;
        }
    }
    return true;
}

void testInitialization() {
    double dx = 0.1;
    double dy = 0.1;
    int npx = 100;
    int npy = 100;
    double px_min = -5.0;
    double px_max = 5.0;
    double py_min = -5.0;
    double py_max = 5.0;
    double dpx = 0.1;
    double dpy = 0.1;
    double dt = 0.01;
    bool sc = true;
    bool vd_disjoint = false;
    double hbar = 1.0;
    double m = 1.0;

    double* px_range = new double[npx];
    double* py_range = new double[npy];
    // Initialize ranges...

    vd_2d_obj obj(dx, dy, npx, npy, px_min, px_max, py_min, py_max, dpx, dpy,
                  px_range, py_range, dt, sc, vd_disjoint, hbar, m);

    // Check if initialization is correct
    assert(obj.getNpx() == npx);

    delete[] px_range;
    delete[] py_range;
}

void testCleanup() {
    // Test cleanup functionality
}

void testUpdate() {
    // Test update functionality
}

int main() {
    testInitialization();
    testCleanup();
    testUpdate();

    std::cout << "All tests passed!" << std::endl;
    return 0;
}