! m.f90
module m
    implicit none
    intrinsic :: min
    intrinsic :: abs
end module m

! main.f90
program main
    use m
    implicit none
    integer :: X, Y

    X = 1
    Y = -1

    Y = min(X, 4)
    Y = abs(Y)

    print *, "Y = ", Y
end program main