program test_loops
    implicit none
    integer :: i
    real :: r

    ! Note: Fortran loops with step 0 or conditions that are never true essentially "do not run".

    do i = 1, 0
    end do
    print *, "Loop with integer counter from 1 to 0 did not run."

    do i = 1, -1, 1
    end do
    print *, "Loop with integer counter from 1 to -1 with step 1 did not run."

    do i = 1, 2, -1
    end do
    print *, "Loop with integer counter from 1 to 2 with step -1 did not run."

    ! Loops with steps of 0 are undefined in Fortran; they are not represented here.

    do r = 1, 0
    end do
    print *, "Loop with real counter from 1 to 0 did not run."

    do r = 1, -1, 1
    end do
    print *, "Loop with real counter from 1 to -1 with step 1 did not run."

    do r = 1, 2, -1
    end do
    print *, "Loop with real counter from 1 to 2 with step -1 did not run."

    ! Loops with steps of 0 are undefined in Fortran; they are not represented here.

end program test_loops