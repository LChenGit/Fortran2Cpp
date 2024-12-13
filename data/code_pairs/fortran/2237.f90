subroutine sescalm(n, dx, incx, dy, incy)
    real dx(*), dy(*)
    integer incx, incy, n
    integer i, ix, iy
    if (n <= 0) return
    if (incx == 1 .and. incy == 1) then
        do i = 1, n
            dy(i) = dy(i) * dx(i)
        end do
    else
        ix = 1
        iy = 1
        if (incx < 0) ix = (-n + 1) * incx + 1
        if (incy < 0) iy = (-n + 1) * incy + 1
        do i = 1, n
            dy(iy) = dy(iy) * dx(ix)
            ix = ix + incx
            iy = iy + incy
        end do
    endif
end subroutine sescalm

program test_sescalm
    implicit none
    integer :: n, incx, incy
    real, dimension(5) :: dx, dy
    integer :: i

    n = 5
    dx = (/ 1.0, 2.0, 3.0, 4.0, 5.0 /)
    dy = (/ 1.0, 1.0, 1.0, 1.0, 1.0 /)
    incx = 1
    incy = 1

    call sescalm(n, dx, incx, dy, incy)

    print *, 'Resulting dy:'
    do i = 1, n
        print *, dy(i)
    end do
end program test_sescalm