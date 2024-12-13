module triloc_module
    implicit none
contains
    function triloc(xp, yp, x, y, v, e, numtri) result(t)
        implicit none
        integer, intent(in) :: v(3,*), e(3,*), numtri
        real*8, intent(in) :: x(*), y(*), xp, yp
        integer :: t, v1, v2, i

        t = numtri
10      continue
        do i = 1, 3
            v1 = v(i, t)
            v2 = v(mod(i, 3) + 1, t)
            if ((y(v1) - yp) * (x(v2) - xp) > (x(v1) - xp) * (y(v2) - yp)) then
                t = e(i, t)
                goto 10
            endif
        end do
    end function triloc
end module triloc_module