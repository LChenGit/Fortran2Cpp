program main
    implicit none
    integer :: a
    a = getA()
    print *, a
end program main

function getA() result(a)
    integer :: a
    a = 1
end function getA