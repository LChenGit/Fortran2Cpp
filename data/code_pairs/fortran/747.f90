! bad1.f90
subroutine bad1(d)
    double precision, intent(out) :: d
    d = 5.0
end subroutine bad1

! Test program for bad1
program test_bad1
    double precision :: d
    call bad1(d)
    print *, "Value of d: ", d
end program test_bad1