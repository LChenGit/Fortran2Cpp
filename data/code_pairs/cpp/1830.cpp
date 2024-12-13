#include <vector>
#include <numeric>

class Arrays {
public:
    static int array_in(int n, const std::vector<int>& x) {
        return std::accumulate(x.begin(), x.end(), 0);
    }

    static void array_out(int nx, int ny, std::vector<int>& x, std::vector<int>& y) {
        x.assign(nx, 20);
        y.assign(ny, 30);
    }

    static int inner_prod(int n, const std::vector<int>& a, const std::vector<int>& b) {
        int result = 0;
        for (int i = 0; i < n; ++i) {
            result += a[i] * b[i];
        }
        return result;
    }

    static int inner_prod_2(int n, const std::vector<int>& a, const std::vector<int>& b) {
        int result = 0;
        for (int i = 0; i < n; ++i) {
            result += a[i] * b[i];
        }
        return result;
    }
};