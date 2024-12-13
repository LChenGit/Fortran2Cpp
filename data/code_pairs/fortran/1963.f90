program main
    implicit none
    integer, parameter :: N=1000
    integer :: random_array(N)
    integer :: ans_val, sa, i
    real :: tmp(N)

    ! Initialize random number generator
    call random_seed()
    call random_number(tmp)
    random_array = int(tmp * 10000)

    ! Compute XOR of the random array
    ans_val = 0
    do i = 1, N
        ans_val = ieor(ans_val, random_array(i))
    end do

    sa = 0
    do i = 1, N
        sa = ieor(sa, random_array(i))
    end do

    if (sa == ans_val) then
        print *, "PASS"
    else
        print *, "ERROR"
    endif
end program main