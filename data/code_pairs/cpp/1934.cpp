#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#include <string>

namespace constants {
    constexpr int nb_nodes = 9;
    constexpr int nb_edges = 8;
    constexpr char it_max_fmt[] = "(I4)";
    constexpr int NODE_PIP3 = 1;
    constexpr int NODE_PIP2 = 2;
    constexpr int NODE_PI3K = 3;
    constexpr int NODE_Insulin_receptor_substrat_1 = 4;
    constexpr int NODE_Insulin_like_GF1_receptor = 5;
    constexpr int NODE_Insulin_receptor = 6;
    constexpr int NODE_Insulin_like_growth_factor_1 = 7;
    constexpr int NODE_Insulin = 8;
    constexpr int NODE_anti_PI3K = 9;
    constexpr int EDGE_PIP2__PIP3 = 1;
    constexpr int EDGE_PI3K__PIP2 = 2;
    constexpr int EDGE_Insulin_receptor_substrat_1__PI3K = 3;
    constexpr int EDGE_anti_PI3K__PI3K = 4;
    constexpr int EDGE_Insulin_receptor__Insulin_receptor_substrat_1 = 5;
    constexpr int EDGE_Insulin_like_GF1_receptor__Insulin_receptor_substrat_1 = 6;
    constexpr int EDGE_Insulin_like_growth_factor_1__Insulin_like_GF1_receptor = 7;
    constexpr int EDGE_Insulin__Insulin_receptor = 8;
}

#endif // CONSTANTS_HPP