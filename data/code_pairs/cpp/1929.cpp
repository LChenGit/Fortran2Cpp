// kinds.hpp
#pragma once
#include <cstddef>
using DP = double;

// ions_base.hpp
#pragma once
#include <vector>
#include "kinds.hpp"
extern std::vector<std::vector<DP>> if_pos;

// path_variables.hpp
#pragma once
#include <vector>
#include "kinds.hpp"
extern std::vector<std::vector<DP>> fix_atom_pos;

// path_input_parameters_module.hpp
#pragma once
extern int nat;