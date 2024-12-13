module mpi_tools
    implicit none
    integer :: rank, mpi_size, ierror

contains

    subroutine start_parallel()
        ! Using MPI library calls to initialize MPI environment
        call MPI_INIT(ierror)
        call MPI_COMM_RANK(MPI_COMM_WORLD, rank, ierror)
        call MPI_COMM_SIZE(MPI_COMM_WORLD, mpi_size, ierror)
    end subroutine start_parallel

    subroutine end_parallel()
        ! Using MPI library call to finalize MPI environment
        call MPI_FINALIZE(ierror)
    end subroutine end_parallel

end module mpi_tools

program test_mpi_tools
    use mpi_tools
    implicit none

    call start_parallel()
    print *, "Process Rank: ", rank
    print *, "Total Number of Processes: ", mpi_size
    call end_parallel()
end program test_mpi_tools