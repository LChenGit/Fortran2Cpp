#ifndef GLOBVARS_H
#define GLOBVARS_H

#include <cmath>
#include <complex>
#include <string>
#include <limits>

namespace globvars {

const double eps_dp = std::numeric_limits<double>::epsilon();
const std::string dp_format = "(es25.16e3)";  
const std::string dp_format_raw = "es25.16e3";
const double pi = 4.0 * atan(1.0);
const double tau = 2.0 * pi;
const double e = exp(1.0);
const std::complex<double> j = std::complex<double>(0.0, 1.0);

} // namespace globvars

#endif // GLOBVARS_H