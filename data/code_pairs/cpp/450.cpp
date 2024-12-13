#pragma once

// Define precision macros similarly to the original approach
#define SINGLE_PRECISION 1
#define DOUBLE_PRECISION 2

// Declare template function that will be specialized
template<int precision>
void ppm_topo_box2subs();

// Declare template specializations
template<>
void ppm_topo_box2subs<SINGLE_PRECISION>(float a, float b);

template<>
void ppm_topo_box2subs<DOUBLE_PRECISION>(double a, double b);