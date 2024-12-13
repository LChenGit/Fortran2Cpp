! This Fortran code is the original subroutine provided.
! Note: Automated unit testing in Fortran would require additional setup not shown here.

program main
    call sub
end program main

subroutine sub
    logical, volatile :: t1
    logical :: t2
    integer :: i

    t2 = .false.
    t1 = .false.
    do i = 1, 2
        if(t1) print *, 'VolatileNotOptimizedAway'
        if(t2) print *, 'NonVolatileNotOptimizedAway'
    end do
end subroutine sub