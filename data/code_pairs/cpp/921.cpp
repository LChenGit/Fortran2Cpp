#ifndef DEF_NESTS_HPP
#define DEF_NESTS_HPP

#include <string>
#include <vector>

class Grid {
public:
    int tdm, time_step, tstart_yy, tstart_mm, tstart_dd;
    int tend_yy, tend_mm, tend_dd;
    bool dataExist, tilted, orthogrid;
    double fill_value;
    std::string fnameold, time_units, uname, vname, wname, densname, salnname, tempname;

    // Constructors, destructors, and other member functions can be added here.
};

#endif // DEF_NESTS_HPP