subroutine clusigt(n, x, incx, target, index, nclus)
    integer n, incx, target, nclus
    integer x(*), index(2,*)
    integer i, ib, ie, nb, ne
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
            if (i == 1 .or. x(ib-incx) <= target) then
                nb = nb + 1
                index(1,nb) = i
            endif
        endif
        ib = ib + incx
    end do
    ne = 0
    if (nb > 0) then
        do i = 1, n-1
            if (x(ie) > target .and. x(ie+incx) <= target) then
                ne = ne + 1
                index(2,ne) = i
            endif
            ie = ie + incx
        end do
        if (x(ie) > target) then
            ne = ne + 1
            index(2,ne) = n
        endif
    endif
    nclus = nb
end subroutine

! Test program for clusigt
program test_clusigt
    implicit none
    integer, allocatable :: x(:), index(2,:)
    integer :: nclus, i, n

    ! Example test case
    n = 7
    allocate(x(n))
    x = (/5, 6, 7, 8, 9, 10, 11/)
    allocate(index(2,n))
    call clusigt(n, x, 1, 9, index, nclus)
    
    print *, 'nclus =', nclus
    do i = 1, nclus
        print *, 'Cluster', i, ': Start =', index(1,i), ', End =', index(2,i)
    end do
end program