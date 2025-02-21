program main
    implicit none

    ! Define variables
    integer, parameter :: n = 5
    double precision :: W(n), U(n), AD(n), Au(n)
    integer :: JQ(n+1), IROW(n)

    ! Initialize arrays
    W = [1.0, 2.0, 3.0, 4.0, 5.0]
    AD = [2.0, 2.0, 2.0, 2.0, 2.0]
    Au = [1.0, 1.0, 1.0, 1.0, 1.0]
    JQ = [1, 3, 5, 6, 6, 6]  ! Adjusted to one-based indexing
    IROW = [1, 2, 3, 4, 5]   ! Adjusted to one-based indexing

    ! Call the subroutine
    call OPNONSYM(n, W, U, AD, Au, JQ, IROW)

    ! Print results
    print *, "Results:"
    print *, U

end program main

subroutine OPNONSYM(n, W, U, AD, Au, JQ, IROW)
    implicit none

    ! Dummy arguments
    integer, intent(in) :: n
    double precision, intent(in) :: W(n), AD(n), Au(n)
    integer, intent(in) :: JQ(n+1), IROW(n)
    double precision, intent(out) :: U(n)

    ! Local variables
    integer :: i, j, start, end, l

    ! First loop
    do i = 1, n
        U(i) = AD(i) * W(i)
    end do

    ! Second loop
    do j = 1, n
        start = JQ(j)
        end = JQ(j+1) - 1
        do l = start, end
            i = IROW(l)
            U(i) = U(i) + Au(l) * W(j)
        end do
    end do

end subroutine OPNONSYM