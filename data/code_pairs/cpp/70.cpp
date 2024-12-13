#include <iostream>
#include <cublas_v2.h>
#include <cuda_runtime.h>

class MaskCuBLAS {
public:
    MaskCuBLAS() : cublas_not_init(true) {
        initialize();
    }

    ~MaskCuBLAS() {
        cleanup();
    }

    void cublas_setmat(int Msize, const double* matrix, double** dev_ptr) {
        std::cout << "Setting matrix (actual cuBLAS implementation)." << std::endl;
        cudaMalloc((void**)dev_ptr, sizeof(double) * Msize * Msize);
        cublasSetMatrix(Msize, Msize, sizeof(double), matrix, Msize, *dev_ptr, Msize);
    }

    void cublas_release(double* dev_ptr = nullptr) {
        std::cout << "Releasing resources (actual cuBLAS implementation)." << std::endl;
        if (dev_ptr != nullptr) {
            cudaFree(dev_ptr);
        }
    }

private:
    bool cublas_not_init;
    cublasHandle_t handle;

    void initialize() {
        cublasCreate(&handle);
        cublas_not_init = false;
    }

    void cleanup() {
        cublasDestroy(handle);
    }
};

int main() {
    MaskCuBLAS cublasWrapper;
    const int Msize = 2;
    double matrix[Msize * Msize] = {1.0, 2.0, 3.0, 4.0};
    double* dev_ptr = nullptr;

    cublasWrapper.cublas_setmat(Msize, matrix, &dev_ptr);

    cublasWrapper.cublas_release(dev_ptr);

    std::cout << "C++ test completed successfully." << std::endl;
    return 0;
}