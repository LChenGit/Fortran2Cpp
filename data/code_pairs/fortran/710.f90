subroutine msolve(n, r, z, nelt, ia, ja, a, isym, rwork, iwork)
    implicit none
    integer n, nelt, ia(*), ja(*), isym, iwork(*), i, nd
    real*8 r(*), z(*), a(*), rwork(*)

    do i = 1, n
        z(i) = r(i) * rwork(i)
    enddo

    return
end subroutine msolve