program test_program
    implicit none
    integer :: a = 1
    integer :: b = 2
    double precision :: j = 3.14
    double precision :: expected = 3.14
    double precision :: tolerance = 0.01
    
    write(*, '(F4.2)') j
    
    ! Test
    if (abs(j - expected) <= tolerance) then
        print *, "Test Passed."
    else
        print *, "Test Failed: Value does not match expected."
    end if
end program test_program