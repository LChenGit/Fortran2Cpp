program main
    implicit none
    integer :: a(10)
    integer :: sa, ia

    a = [2, 1, 4, 6, 3, 2, 6, 3, 3, 1]

    ! Finding the maximum value and its index
    sa = 0
    do ia = 1, 10
       if (sa < a(ia)) then
          sa = a(ia)
       endif
    enddo

    if (sa == 6) then
       print *, "PASS"
    else
       print *, "ERROR"
    endif

    ! Finding the minimum value and its index
    sa = 10
    do ia = 1, 10
       if (sa > a(ia)) then
          sa = a(ia)
       endif
    enddo

    if (sa == 1) then
       print *, "PASS"
    else
       print *, "ERROR"
    endif
end program main