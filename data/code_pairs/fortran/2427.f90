! constantes.f90
module constantes
    implicit none
    real(kind=8), parameter :: U_PI = 3.14159265358979323846
end module constantes

! prog.f90
program prog
    use constantes
    implicit none
    write(*,*) "pi = ", U_PI
end program prog

! test_prog.f90
program test_prog
    use constantes
    implicit none
    real(kind=8) :: test_value
    logical :: test_passed

    test_value = U_PI
    test_passed = (abs(test_value - 3.14159265358979323846) < 1.0E-15)

    if (test_passed) then
        print *, "Fortran Test passed."
    else
        print *, "Fortran Test failed."
        print *, "Expected: 3.14159265358979323846"
        print *, "Got: ", test_value
    end if
end program test_prog