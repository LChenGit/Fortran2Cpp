program test_mpi_environment
    implicit none
    integer :: rank, size, ierr, i
    integer, allocatable :: recv_int(:)
    integer, parameter :: root = 0

    ! Simulate MPI environment initialization
    rank = 0
    size = 4  ! Simulating a size of 4 for demonstration

    allocate(recv_int(size))

    ! Simulate gathering ranks into recv_int
    do i = 1, size
        recv_int(i) = i - 1  ! Simulating ranks 0 through size-1
    end do

    ! Simulate broadcasting a single integer from root
    ierr = 123

    ! Output to demonstrate what would have been gathered and broadcasted
    if (rank == root) then
        print *, 'Simulated gather result in root:', recv_int
        print *, 'Simulated broadcast result:', ierr
    else
        print *, 'Rank', rank, 'sees broadcast result:', ierr
    endif

end program test_mpi_environment