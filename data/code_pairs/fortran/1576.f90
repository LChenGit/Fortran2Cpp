module xclib_utils_and_para
    ! Define the constants and variables directly in the module.
    ! This is a demonstration based on the given unit tests.
    integer, parameter :: MPI_COMM_WORLD = 0
    integer, parameter :: MPI_COMM_NULL = -1
    integer, parameter :: MPI_COMM_SELF = -2
    integer, parameter :: stdout = 6
    logical :: nowarning = .FALSE.
end module xclib_utils_and_para