#include <complex>

class kind_types {
public:
    using dp = double;
    using qp = long double;

    static const std::complex<dp> cI_dp;
    static const std::complex<qp> cI_qp;

    static std::complex<dp> cmplx_dp(dp re, dp im = 0.0) {
        return std::complex<dp>(re, im);
    }

    static std::complex<qp> cmplx_qp(qp re, qp im = 0.0) {
        return std::complex<qp>(re, im);
    }
};

// Initialize the static constants
const std::complex<kind_types::dp> kind_types::cI_dp(0.0, 1.0);
const std::complex<kind_types::qp> kind_types::cI_qp(0.0, 1.0);