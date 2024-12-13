! This is a single-line comment in Fortran
program test_variable
    implicit none
    integer :: x = 5 ! Another comment following code on the same line.

    ! Check if x is equal to 5
    if (x /= 5) then
        print *, 'Test failed: x is not equal to 5'
        stop 1
    else
        print *, 'Test passed: x is equal to 5'
    end if
end program test_variable