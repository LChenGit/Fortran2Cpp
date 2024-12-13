! File: parallel_include.f90
MODULE parallel_include
! Use preprocessor to check if __MPI is defined
#if defined(__MPI)
    INCLUDE 'mpif.h'
    LOGICAL :: tparallel = .TRUE.
#else
    LOGICAL :: tparallel = .FALSE.
#endif
END MODULE parallel_include