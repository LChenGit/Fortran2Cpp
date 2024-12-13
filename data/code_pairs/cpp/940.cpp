#ifndef DFT_SETTING_PARAMS_HPP
#define DFT_SETTING_PARAMS_HPP

#include <string>

namespace dft_setting_params {

    constexpr int max_iter = 100;
    constexpr double conv_thresh = 1.0e-6;
    bool print_info = true;

#ifdef __LIBXC
    std::string xc_functional = "PBE";
#else
    std::string xc_functional = "LDA";
#endif

} // namespace dft_setting_params

#endif // DFT_SETTING_PARAMS_HPP