// File: parallel_include.hpp
#ifndef PARALLEL_INCLUDE_HPP
#define PARALLEL_INCLUDE_HPP

#ifdef __MPI
#include <mpi.h>
constexpr bool tparallel = true;
#else
constexpr bool tparallel = false;
#endif

#endif // PARALLEL_INCLUDE_HPP