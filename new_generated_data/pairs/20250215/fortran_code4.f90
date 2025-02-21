program memory_sync_test
    use omp_lib
    implicit none

    integer, parameter :: n = 4
    integer :: i
    character(len=42) :: msg
    real, dimension(n) :: shared_array

    ! Initialize array
    shared_array = 0.0

    ! OpenMP directives for parallel execution
    !$omp parallel num_threads(2)
        !$omp critical
            if (omp_get_thread_num() == 0) then
                ! Thread 0 modifies the array
                shared_array = 1.0
                ! Synchronize memory
                !$omp flush(shared_array)
            end if
        !$omp end critical

        ! All threads wait
        !$omp barrier

        ! Verify array values
        do i = 1, n
            if (shared_array(i) /= 1.0) then
                write(*, *) "Test failed: shared_array(", i, ") is not 1.0"
                call exit(1)
            end if
        end do

    !$omp end parallel

    write(*, *) "All tests passed in Fortran!"

end program memory_sync_test