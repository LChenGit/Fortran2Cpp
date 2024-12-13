module constants
    implicit none
    real(kind=8), parameter :: pi = 3.14159265358979323846
end module constants

subroutine area(r, a)
    use constants, only: pi
    implicit none
    real(kind=8), intent(in) :: r
    real(kind=8), intent(out) :: a

    a = pi * r**2
end subroutine area

program test_area
    use constants, only: pi
    implicit none
    real(kind=8) :: r, a

    ! Test 1: Radius = 0.0
    r = 0.0
    call area(r, a)
    print *, "Test 1 (r=0.0): ", a, " Expected: ", 0.0

    ! Test 2: Radius = 1.0 (Area should be Pi)
    r = 1.0
    call area(r, a)
    print *, "Test 2 (r=1.0): ", a, " Expected: ", pi

    ! Test 3: Radius = 10.0
    r = 10.0
    call area(r, a)
    print *, "Test 3 (r=10.0): ", a, " Expected: ", pi * 100.0

    ! Test 4: Small radius
    r = 0.001
    call area(r, a)
    print *, "Test 4 (r=0.001): ", a, " Expected: ", pi * 0.001**2
end program test_area