! sum_serial.f90
program sum_serial
    implicit none
    integer :: i, sum, total_sum
    integer, parameter :: N = 10000

    sum = 0
    total_sum = 0

    ! Calculate total sum in a serial manner
    do i = 1, N
        sum = sum + i
    end do
    total_sum = sum

    print *, 'Total Sum: ', total_sum
    if (total_sum == (N * (N + 1)) / 2) then
        print *, 'Test PASSED.'
    else
        print *, 'Test FAILED.'
    endif
end program sum_serial