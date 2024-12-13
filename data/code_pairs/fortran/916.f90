! This Fortran code defines a subroutine that displays a warning message
! and then stops the execution of the program.

subroutine bmf_splitwrite
    print *, '*****************************************************'
    print *, 'WARNING: bmf_splitwrite has been replaced by         '
    print *, ' bmf_splitwrite2 with an additional first argument   '
    print *, ' first argument should be RPN_COMM_split             '
    print *, '*****************************************************'
    stop
end subroutine bmf_splitwrite

! The main program to test the subroutine bmf_splitwrite.
program test_bmf_splitwrite
    call bmf_splitwrite
end program test_bmf_splitwrite