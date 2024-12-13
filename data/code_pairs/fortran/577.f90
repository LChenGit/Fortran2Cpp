subroutine curved_elem_tri(nnodes, xel, info_curved, tmp)
    implicit none
    integer*8 nnodes, info_curved
    double precision xel(2,nnodes)
    integer*8 nnd_triangle
    parameter (nnd_triangle = 6)
    double precision xel_triangle(2,nnd_triangle)
    integer*8 i, j, i2
    double precision tol, tmp

    if (nnodes .ne. nnd_triangle) then
        write(*,*)
        write(*,*) "   ???"
        write(*,*) "curved_elem_tri: nnodes != nnd_triangle : ", nnodes, nnd_triangle
        write(*,*) "curved_elem_tri: Aborting..."
        stop
    endif

    do i=1,3
        do j=1,2
            xel_triangle(j,i) = xel(j,i)
        enddo
    enddo

    do i=1,3
        i2 = mod(i+1,3)
        if(i2 .eq. 0) i2 = 3
        do j=1,2
            xel_triangle(j,i+3) = (xel(j,i)+xel(j,i2))/2.0d0
        enddo
    enddo

    tmp = 0.0d0
    do i=1,nnodes
        do j=1,2
            tmp = tmp + (xel_triangle(j,i) - xel(j,i))**2
        enddo
    enddo

    tol = 1.0d-14
    if(abs(tmp) .lt. tol) then
        info_curved = 0
    else
        info_curved = 1
    endif

end subroutine curved_elem_tri

! Unit test program for curved_elem_tri
program test_curved_elem_tri
    implicit none
    integer*8 :: nnodes, info_curved
    double precision :: tmp
    double precision, dimension(2,6) :: xel

    ! Test case 1: Correct number of nodes, expect info_curved = 0
    nnodes = 6
    xel = reshape([1.0D0, 2.0D0, 3.0D0, 1.5D0, 2.5D0, 3.5D0, &
                   1.0D0, 2.0D0, 3.0D0, 1.5D0, 2.5D0, 3.5D0], shape(xel), order = [1, 2])
    call curved_elem_tri(nnodes, xel, info_curved, tmp)
    print *, "Test 1, Expected info_curved = 0, Actual:", info_curved

end program test_curved_elem_tri