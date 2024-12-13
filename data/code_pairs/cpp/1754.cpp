#ifndef DSTAR_CRUST_DEF_H
#define DSTAR_CRUST_DEF_H

#include <vector>
#include <string>
#include <memory>

namespace dStar_crust_def {

    constexpr int crust_default_number_table_points = 2048;
    constexpr double crust_default_lgPmin = 22.0;
    constexpr double crust_default_lgPmax = 33.5;
    constexpr double crust_default_temperature = 1.0e8;

    struct crust_table_type {
        bool is_loaded = false;
        int nv = 0;
        int nisos = 0;
        std::vector<std::string> network;
        double lgP_min = 0.0, lgP_max = 0.0;
        double T = 0.0;
        std::vector<double> lgP;
        std::unique_ptr<std::vector<std::vector<double>>> Y = nullptr;
        std::unique_ptr<std::vector<double>> lgRho = nullptr;
        std::unique_ptr<std::vector<double>> lgEps = nullptr;
    };

    extern crust_table_type crust_table;
    extern bool crust_is_initialized;
    extern std::string crust_datadir;

}

#endif // DSTAR_CRUST_DEF_H