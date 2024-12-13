subroutine dqpsrt(limit, last, maxerr, ermax, elist, iord, nrmax)
    integer, intent(in) :: limit, last
    integer, intent(inout) :: maxerr, iord(last), nrmax
    real*8, intent(inout) :: ermax, elist(last)
    integer :: i, ibeg, ido, isucc, j, jbnd, jupbn, k
    real*8 :: errmax, errmin

    if (last <= 2) then
        iord(1) = 1
        iord(2) = 2
        return
    endif

    errmax = elist(maxerr)
    if (nrmax /= 1) then
        ido = nrmax - 1
        do i = 1, ido
            isucc = iord(nrmax - 1)
            if (errmax <= elist(isucc)) exit
            iord(nrmax) = isucc
            nrmax = nrmax - 1
        end do
    endif

    jupbn = last
    if (last > (limit / 2 + 2)) jupbn = limit + 3 - last
    errmin = elist(last)
    jbnd = jupbn - 1
    ibeg = nrmax + 1
    if (ibeg <= jbnd) then
        do i = ibeg, jbnd
            isucc = iord(i)
            if (errmax >= elist(isucc)) exit
            iord(i - 1) = isucc
        end do
    endif

    if (i > jbnd) then
        iord(jbnd) = maxerr
        iord(jupbn) = last
    else
        iord(i - 1) = maxerr
        do j = i, jbnd
            isucc = iord(j)
            if (errmin < elist(isucc)) exit
            iord(j + 1) = isucc
        end do
        iord(i) = last
    endif

    maxerr = iord(nrmax)
    ermax = elist(maxerr)
end subroutine dqpsrt

program testDqpsrt
    implicit none
    integer, parameter :: last = 5
    integer :: limit, maxerr, nrmax, i
    real*8 :: ermax
    real*8 :: elist(last)
    integer :: iord(last)

    limit = 10
    maxerr = 2
    nrmax = 1
    ermax = 0.0
    elist = (/0.1, 0.2, 0.05, 0.3, 0.25/)
    iord = (/1, 2, 3, 4, 5/)

    call dqpsrt(limit, last, maxerr, ermax, elist, iord, nrmax)

    print *, "maxerr:", maxerr
    print *, "ermax:", ermax
    print *, "nrmax:", nrmax
    print *, "iord:", iord
end program testDqpsrt