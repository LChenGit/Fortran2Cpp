// AstObs.hpp
#ifndef AST_OBS_HPP
#define AST_OBS_HPP

#include <vector>

class AstObs {
public:
    std::vector<float>* geopos = nullptr; // Using pointer to vector to mimic Fortran pointer behavior

    AstObs() = default; // Default constructor

    explicit AstObs(std::vector<float>* vec) : geopos(vec) {} // Constructor initializing geopos

    void resetGeopos() {
        geopos = nullptr; // Reset geopos to simulate get_null_ast_obs behavior
    }
};

void get_null_ast_obs(AstObs& obs);

#endif // AST_OBS_HPP