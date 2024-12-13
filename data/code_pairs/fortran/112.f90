program test_qinit
    implicit none
    double precision, allocatable :: q(:,:,:)
    integer :: meqn, mbc, mx, my, maux
    double precision :: xlower, ylower, dx, dy
    integer :: i, j, k

    ! Define test parameters
    meqn = 5
    maux = 0
    mbc = 2
    mx = 3
    my = 3
    xlower = 0.0
    ylower = 0.0
    dx = 1.0
    dy = 1.0

    ! Allocate arrays
    allocate(q(meqn, 1-mbc:mx+mbc, 1-mbc:my+mbc))

    ! Call the subroutine
    call qinit(meqn, mbc, mx, my, xlower, ylower, dx, dy, q, maux)

    ! Print results for comparison
    print *, 'q values:'
    do i = 1, mx
        do j = 1, my
            print *, '(', i, ',', j, '):', (q(k, i, j), k=1, meqn)
        end do
    end do
end program test_qinit

subroutine qinit(meqn, mbc, mx, my, xlower, ylower, dx, dy, q, maux)
    implicit none
    integer, intent(in) :: meqn, mbc, mx, my, maux
    double precision, intent(in) :: xlower, ylower, dx, dy
    double precision, intent(inout) :: q(meqn,1-mbc:mx+mbc,1-mbc:my+mbc)
    integer :: i, j

    do i = 1, mx
        do j = 1, my
            q(1,i,j) = 0.d0
            q(2,i,j) = 0.d0
            q(3,i,j) = 0.d0
            q(4,i,j) = 0.d0
            q(5,i,j) = 0.d0
        end do
    end do
end subroutine qinit