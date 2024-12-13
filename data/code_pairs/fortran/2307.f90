! example.f90
subroutine example
    implicit none
    ! This subroutine does nothing
    return
end subroutine example

program test_example
    implicit none
    ! Main program to test the subroutine
    call example()
    print *, 'The subroutine was called successfully.'
end program test_example