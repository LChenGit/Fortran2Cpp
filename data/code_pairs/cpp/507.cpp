#include <vector>

template<typename T>
void DCOPY(int N, const T* DX, int INCX, T* DY, int INCY) {
    for (int ix = 0, iy = 0; N > 0; N--, ix += INCX, iy += INCY) {
        DY[iy] = DX[ix];
    }
}

void dcopy_wrapper(int N, const std::vector<double>& dx, int INCX, std::vector<double>& dy, int INCY) {
    if(dy.size() < static_cast<size_t>((N-1) * INCY + 1)){
        dy.resize((N-1) * INCY + 1);
    }
    DCOPY<double>(N, dx.data(), INCX, dy.data(), INCY);
}