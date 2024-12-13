subroutine clusfgt(n, x, incx, target, index, nclus)
    integer :: n, incx, nclus
    real :: target
    integer, dimension(2,*) :: index
    real, dimension(*) :: x
    integer :: i, ib, ie, nb, ne

    if (n < 1) return

    if (incx >= 0) then
        ib = 1
        ie = 1
    else
        ib = 1 - incx * (n - 1)
        ie = 1 - incx * (n - 1)
    endif

    nb = 0
    do i = 1, n
        if (x(ib) > target) then
            if (nb == 0 .or. x(ib-incx) <= target) then
                nb = nb + 1
                index(1,nb) = i
            endif
            if (i == n) then
                index(2,nb) = i
            endif
        elseif (ib - incx > 0 .and. x(ib-incx) > target) then
            index(2,nb) = i - 1
        endif
        ib = ib + incx
    end do

    nclus = nb
end subroutine clusfgt