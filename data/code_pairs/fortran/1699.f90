! This Fortran code defines a function `dsum` that computes the sum of elements in a 
! double precision array `dx` with a specified increment `incx`.

double precision function dsum(n, dx, incx)
    integer, intent(in) :: n, incx
    double precision, intent(in) :: dx(*)
    double precision :: dtemp
    integer :: i, m, mp1, nincx

    dsum = 0.0d0
    dtemp = 0.0d0
    if (n <= 0 .or. incx <= 0) return
    if (incx == 1) then
        m = mod(n, 6)
        if (m /= 0) then
            do i = 1, m
                dtemp = dtemp + dx(i)
            end do
            if (n < 6) then
                dsum = dtemp
                return
            end if
        end if
        mp1 = m + 1
        do i = mp1, n, 6
            dtemp = dtemp + dx(i) + dx(i+1) + dx(i+2) + dx(i+3) + dx(i+4) + dx(i+5)
        end do
    else
        nincx = n*incx
        do i = 1, nincx, incx
            dtemp = dtemp + dx(i)
        end do
    end if
    dsum = dtemp
end function dsum