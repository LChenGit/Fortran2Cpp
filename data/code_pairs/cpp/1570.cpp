#ifndef GLOBALS_HPP
#define GLOBALS_HPP

#include <vector>
#include <string>
#include <array>

namespace globals {
    int rank;

    int nbmin;
    int nbmax;
    int nbrootx;
    int nbrooty;
    int nbrootz;
    int maxcells_x;
    int maxcells_y;
    int maxcells_z;
    int maxlev;
    int nbLocal;
    int nbActive;

    int it;
    float time;
    float dt;
    int nextout;

    int start_mark;
    int logu;
    std::string logfile;
    std::string host;

    std::array<float, 3> timings;
}

#endif // GLOBALS_HPP