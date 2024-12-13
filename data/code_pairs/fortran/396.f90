! saxpy.f90
subroutine saxpy(n, sa, sx, incx, sy, incy)
    real :: sx(*), sy(*), sa
    integer :: n, incx, incy, i, ix, iy, m, mp1

    if (n <= 0) return
    if (sa == 0.0) return

    if (incx == 1 .and. incy == 1) then
        m = mod(n, 4)
        if (m /= 0) then
            do i = 1, m
                sy(i) = sy(i) + sa * sx(i)
            end do
            if (n < 4) return
        end if
        do i = m+1, n, 4
            sy(i) = sy(i) + sa * sx(i)
            sy(i+1) = sy(i+1) + sa * sx(i+1)
            sy(i+2) = sy(i+2) + sa * sx(i+2)
            sy(i+3) = sy(i+3) + sa * sx(i+3)
        end do
    else
        ix = 1
        iy = 1
        if (incx < 0) ix = (-n + 1) * incx + 1
        if (incy < 0) iy = (-n + 1) * incy + 1
        do i = 1, n
            sy(iy) = sy(iy) + sa * sx(ix)
            ix = ix + incx
            iy = iy + incy
        end do
    endif
end subroutine saxpy

program test_saxpy
    external saxpy
    integer :: n, incx, incy
    real :: sa
    real, allocatable :: sx(:), sy(:)

    n = 5
    sa = 2.0
    incx = 1
    incy = 1
    allocate(sx(n), sy(n))

    sx = (/1.0, 2.0, 3.0, 4.0, 5.0/)
    sy = (/5.0, 4.0, 3.0, 2.0, 1.0/)

    call saxpy(n, sa, sx, incx, sy, incy)

    print *, "SY after SAXPY:"
    print *, sy

    deallocate(sx, sy)
end program test_saxpy